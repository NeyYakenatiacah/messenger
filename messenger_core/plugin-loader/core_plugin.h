#ifndef CORE_PLUGIN_H
#define CORE_PLUGIN_H

#include <QPluginLoader>

#include "messenger_core_export.h"
#include "interfaces/core_factory_interface.h"

class MESSENGER_CORE_EXPORT CorePlugin : public CoreFactoryInterface
{

public:

    CorePlugin();

    explicit CorePlugin(const QString & filename);

    ~CorePlugin();

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

#endif // CORE_PLUGIN_H
