#ifndef INNER_PROTOCOL_H
#define INNER_PROTOCOL_H

#include <interfaces/core_factory_interface.h>

class InnerProtocol : public QObject, public CoreFactoryInterface
{
    Q_OBJECT

    Q_PLUGIN_METADATA(IID CORE_FACTORY_IID)

    Q_INTERFACES(CoreFactoryInterface)

public:

    // CoreFactoryInterface interface

    QStringList objectIds() const;

    QObject *createObjectInstance(const QString &id) const;

};

#endif // INNER_PROTOCOL_H
