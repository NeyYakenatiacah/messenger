#ifndef CORE_PLUGIN_H
#define CORE_PLUGIN_H

#include <QPluginLoader>

#include <messenger_core_export.h>
#include <core/interface/factory.hpp>

namespace core
{
class MESSENGER_CORE_EXPORT Plugin : public Factory
{

public:

    Plugin();

    explicit Plugin(const QString & filename);

    virtual ~Plugin() override;

    bool load(const QString & filename);

    bool unload();

    bool contains(const QString & id) const;

    QString filename() const;

    // CoreFactoryInterface interface

    QStringList objectIds() const override;

    QObject *createObjectInstance(const QString &id) const override;

private:

    mutable QPluginLoader m_loader;



};
}
#endif // CORE_PLUGIN_H
