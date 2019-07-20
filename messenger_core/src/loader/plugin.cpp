#include <core/loader/plugin.hpp>

namespace core
{
Plugin::Plugin()
{

}

Plugin::Plugin(const QString& filename)
{
    load(filename);
}

Plugin::~Plugin()
{

}

bool Plugin::load(const QString& filename)
{
    if(!m_loader.isLoaded())
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

bool Plugin::unload()
{
    return m_loader.unload();
}

bool Plugin::contains(const QString & id) const
{
    return objectIds().contains(id);
}

QString Plugin::filename() const
{
    return m_loader.fileName();
}

QStringList Plugin::objectIds() const
{
    QObject * root = m_loader.instance();

    if(root)
    {
        Factory * interface = qobject_cast<Factory*>(root);

        if(interface)
        {
            return interface->objectIds();
        }
    }

    return QStringList();
}

QObject *Plugin::createObjectInstance(const QString &id) const
{
    QObject * root = m_loader.instance();

    if(root)
    {
        Factory *interface = qobject_cast<Factory*>(root);

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
}
