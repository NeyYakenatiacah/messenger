#ifndef ABSTRACT_PLUGIN_DISPATCHER_H
#define ABSTRACT_PLUGIN_DISPATCHER_H

#include <QFileInfo>
#include <QObject>
#include <QStringList>

#include <messenger_core_export.h>

namespace core
{
class MESSENGER_CORE_EXPORT AbstractPluginDispatcher : public QObject
{
    Q_OBJECT

public:

    explicit AbstractPluginDispatcher(QObject * parent = nullptr);
    virtual ~AbstractPluginDispatcher();

    virtual QStringList plugins() const = 0;

    virtual QFileInfo info(const QString & plugin) const;

    virtual QStringList content(const QString & plugin) const;

public slots:

    void addPlugin(QString file);

    void removePlugin(QString file);

protected:

    virtual bool load(const QString & file);

    virtual bool unload(const QString & file);

signals:

    void loaded(QString);

    void unloaded(QString);

    void errorOccured(QString);

    void pluginsChanged();

};
}
#endif // ABSTRACT_PLUGIN_DISPATCHER_H
