#include "core_plugin_dispatcher.h"

#include <QDebug>

CorePluginDispatcher::CorePluginDispatcher(QObject *parent) : AbstractPluginDispatcher(parent)
{

}

CorePluginDispatcher::~CorePluginDispatcher()
{
    for(CorePlugin * plugin : m_plugins)
    {
        if(plugin)
        {
            plugin->unload();
        }
    }
    qDeleteAll(m_plugins);
}

QStringList CorePluginDispatcher::plugins() const
{
    QStringList list;

    for(const CorePlugin * plugin : m_plugins)
    {
        if(plugin)
        {
            list << plugin->filename();
        }
    }

    return list;
}

QFileInfo CorePluginDispatcher::info(const QString & plugin_name) const
{
    for(const CorePlugin * plugin : m_plugins)
    {
        if(plugin && plugin->filename() == plugin_name)
        {
            return QFileInfo(plugin->filename());
        }
    }

    return QFileInfo();
}

QStringList CorePluginDispatcher::content(const QString & plugin_name) const
{
    for(const CorePlugin * plugin : m_plugins)
    {
        if(plugin && plugin->filename() == plugin_name)
        {
            return plugin->objectIds();
        }
    }

    return QStringList();
}

QStringList CorePluginDispatcher::objectIds() const
{
    QStringList list;

    for(const CorePlugin * plugin : m_plugins)
    {
        list << plugin->objectIds();
    }

    return list;
}

QObject * CorePluginDispatcher::createObjectInstance(const QString & id) const
{
    for(const CorePlugin * plugin : m_plugins)
    {
        QObject * instance = plugin->createObjectInstance(id);

        if(instance)
        {
            return instance;
        }
    }

    return nullptr;
}

bool CorePluginDispatcher::load(const QString & file)
{
    bool duplicate = plugins().contains(file);

    if(!duplicate)
    {
        CorePlugin * plugin = new CorePlugin();

        if(plugin->load(file))
        {
            m_plugins << plugin;

            qDebug() << "Plugin " << file << " loaded!";

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

bool CorePluginDispatcher::unload(const QString & file)
{
    for(CorePlugin * plugin : m_plugins)
    {
        if(plugin)
        {
            if(plugin->filename() == file)
            {
                if(plugin->unload())
                {
                    m_plugins.removeOne(plugin);

                    delete plugin;

                    qDebug() << "Plugin " << file << " deleted!";

                    return true;
                }
            }
        }
    }

    return false;
}
