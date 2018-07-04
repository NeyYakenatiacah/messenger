#include "core_plugin.h"

CorePlugin::CorePlugin()
{

}

CorePlugin::CorePlugin(const QString & filename)
{
    load(filename);
}

CorePlugin::~CorePlugin()
{

}

bool CorePlugin::load(const QString & filename)
{
    bool unloaded = unload();

    if(unloaded)
    {
        m_loader.setFileName(filename);

        if(!m_loader.load())
        {
            return false;
        }

        if(objectIds().isEmpty())
        {
            return false;
        }

        return true;
    }
    else
    {
        return false;
    }
}

bool CorePlugin::unload()
{
    return true;
    //return m_loader.unload();
}

bool CorePlugin::contains(const QString & id) const
{
    return objectIds().contains(id);
}

QString CorePlugin::filename() const
{
    return m_loader.fileName();
}

QStringList CorePlugin::objectIds() const
{
    QObject * root = m_loader.instance();

    if(root)
    {
        CoreFactoryInterface * interface = qobject_cast<CoreFactoryInterface *>(root);

        if(interface)
        {
            return interface->objectIds();
        }
    }

    return QStringList();
}

QObject *CorePlugin::createObjectInstance(const QString &id) const
{
    QObject * root = m_loader.instance();

    if(root)
    {
        CoreFactoryInterface * interface = qobject_cast<CoreFactoryInterface *>(root);

        if(interface)
        {
            QObject * instance = interface->createObjectInstance(id);

            if(instance)
            {
                return instance;
            }
        }
    }

    return nullptr;
}
