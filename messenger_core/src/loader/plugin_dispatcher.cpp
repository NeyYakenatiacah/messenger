#include <core/loader/plugin_dispatcher.hpp>

namespace core
{
PluginDispatcher::PluginDispatcher(QObject *parent) : AbstractPluginDispatcher(parent)
{

}

PluginDispatcher::~PluginDispatcher()
{
    for(Plugin * plugin : m_plugins)
    {
        if(plugin)
        {
            plugin->unload();
        }
    }
    qDeleteAll(m_plugins);
    //TODO: Unload plugins & ensure all created modules(via plugin) are successfuly destroyed
}

QStringList PluginDispatcher::plugins() const
{
    QStringList list;

    for(const Plugin * plugin : m_plugins)
    {
        if(plugin)
        {
            list << plugin->filename();
        }
    }

    return list;
}

QFileInfo PluginDispatcher::info(const QString & plugin_name) const
{
    for(const Plugin * plugin : m_plugins)
    {
        if(plugin && plugin->filename() == plugin_name)
        {
            return QFileInfo(plugin->filename());
        }
    }

    return QFileInfo();
}

QStringList PluginDispatcher::content(const QString & plugin_name) const
{
    for(const Plugin * plugin : m_plugins)
    {
        if(plugin && plugin->filename() == plugin_name)
        {
            return plugin->objectIds();
        }
    }

    return QStringList();
}

QStringList PluginDispatcher::objectIds() const
{
    QStringList list;

    for(const Plugin * plugin : m_plugins)
    {
        list << plugin->objectIds();
    }

    return list;
}

QObject * PluginDispatcher::createObjectInstance(const QString & id) const
{
    for(const Plugin * plugin : m_plugins)
    {
        QObject * instance = plugin->createObjectInstance(id);

        if(instance)
        {
            return instance;
        }
    }

    return nullptr;
}

bool PluginDispatcher::load(const QString & file)
{
    if(!plugins().contains(file))
    {
        Plugin * plugin = new Plugin();

        if(plugin->load(file))
        {
            m_plugins << plugin;

            return true;
        }
        else
        {
            delete plugin;

            return false;
        }
    }

    return false;
}

bool PluginDispatcher::unload(const QString & file)
{
    for(Plugin * plugin : m_plugins)
    {
        if(plugin)
        {
            if(plugin->filename() == file)
            {
                if(plugin->unload())
                {
                    m_plugins.removeOne(plugin);

                    delete plugin;

                    return true;
                }
            }
        }
    }

    return false;
}
}
