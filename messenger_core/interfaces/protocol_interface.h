#ifndef PROTOCOL_INTERFACE_H
#define PROTOCOL_INTERFACE_H

#include <QObject>

#include <messenger_core_export.h>
#include "core_factory_interface.h"

class MESSENGER_CORE_EXPORT ProtocolInterface : public QObject
{
    Q_OBJECT
public:
    explicit ProtocolInterface(QObject *parent = nullptr);

    virtual QString id() const = 0;
    virtual QString name() const = 0;

    virtual QVariantMap options() const;

    virtual bool enabled() const;



signals:
    void statusChanged();

public slots:

private:
    CoreFactoryInterface * m_factory;
};

#endif // PROTOCOL_INTERFACE_H
