#ifndef CORE_PLUGIN_DISPATCHER_H
#define CORE_PLUGIN_DISPATCHER_H

#include <QPluginLoader>

#include "abstract_plugin_dispatcher.h"
#include "core_plugin.h"

class MESSENGER_CORE_EXPORT CorePluginDispatcher : public AbstractPluginDispatcher, public CoreFactoryInterface
{
    Q_OBJECT

    Q_INTERFACES(CoreFactoryInterface)

public:

    explicit CorePluginDispatcher(QObject * parent = nullptr);
    virtual ~CorePluginDispatcher();


    // AbstractPluginDispatcher interface

    virtual QStringList plugins() const override;

    virtual QFileInfo info(const QString & plugin_name) const override;

    virtual QStringList content(const QString & plugin_name) const override;

    // CoreFactoryInterface interface

    virtual QStringList objectIds() const override;

    virtual QObject * createObjectInstance(const QString & id) const override;

protected:

    // AbstractPluginDispatcher interface

    virtual bool load(const QString &file) override;

    virtual bool unload(const QString &file) override;

private:

    QList<CorePlugin *> m_plugins;

};

#endif // CORE_PLUGIN_DISPATCHER_H
