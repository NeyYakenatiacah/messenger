#include <core/loader/abstract_plugin_dispatcher.hpp>

namespace core
{
AbstractPluginDispatcher::AbstractPluginDispatcher(QObject * parent) : QObject(parent)
{

}

AbstractPluginDispatcher::~AbstractPluginDispatcher()
{

}

QFileInfo AbstractPluginDispatcher::info(const QString &plugin) const
{
    Q_UNUSED(plugin)

    return QFileInfo();
}

QStringList AbstractPluginDispatcher::content(const QString &plugin) const
{
    Q_UNUSED(plugin)

    return QStringList();
}

void AbstractPluginDispatcher::addPlugin(QString file)
{
    if(load(file))
    {
        emit loaded(file);

        emit pluginsChanged();
    }
    else
        emit errorOccured("Can not load plugin file.");
}

void AbstractPluginDispatcher::removePlugin(QString file)
{
    if(unload(file))
    {
        emit unloaded(file);

        emit pluginsChanged();
    }
    else
    {
        emit errorOccured("Can not unload plugin.");
    }
}

bool AbstractPluginDispatcher::load(const QString &file)
{
    Q_UNUSED(file)

    return false;
}

bool AbstractPluginDispatcher::unload(const QString &file)
{
    Q_UNUSED(file)

    return false;
}
}
