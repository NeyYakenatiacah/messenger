#include "abstract_plugin_dispatcher.h"

AbstractPluginDispatcher::AbstractPluginDispatcher(QObject * parent) : QObject(parent)
{

}

AbstractPluginDispatcher::~AbstractPluginDispatcher()
{

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
