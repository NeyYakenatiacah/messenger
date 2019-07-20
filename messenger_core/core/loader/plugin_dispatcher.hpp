#ifndef CORE_PLUGIN_DISPATCHER_H
#define CORE_PLUGIN_DISPATCHER_H

#include <QPluginLoader>

#include <core/loader/plugin.hpp>
#include <core/loader/abstract_plugin_dispatcher.hpp>

namespace core
{
class MESSENGER_CORE_EXPORT PluginDispatcher : public AbstractPluginDispatcher, public Factory
{
    Q_OBJECT

    Q_INTERFACES(core::Factory)

public:

    explicit PluginDispatcher(QObject * parent = nullptr);
    virtual ~PluginDispatcher() override;

    // AbstractPluginDispatcher interface

    virtual QStringList plugins() const override;

    virtual QFileInfo info(const QString & plugin_name) const override;

    virtual QStringList content(const QString & plugin_name) const override;

    // Factory interface

    virtual QStringList objectIds() const override;

    virtual QObject * createObjectInstance(const QString & id) const override;

protected:

    // AbstractPluginDispatcher interface

    virtual bool load(const QString &file) override;

    virtual bool unload(const QString &file) override;

private:

    QList<Plugin*> m_plugins;

};
}
#endif // CORE_PLUGIN_DISPATCHER_H
