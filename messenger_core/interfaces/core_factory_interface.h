#ifndef PROTOCOL_FACTORY_INTERFACE_H
#define PROTOCOL_FACTORY_INTERFACE_H

#include <QtPlugin>

#include <messenger_core_export.h>

#define CORE_FACTORY_IID "Messenger.Interface.CoreFactory"

class MESSENGER_CORE_EXPORT CoreFactoryInterface
{

public:

    virtual ~CoreFactoryInterface();

    virtual QStringList objectIds() const = 0;

    virtual QObject * createObjectInstance(const QString & id) const = 0;

};

Q_DECLARE_INTERFACE(CoreFactoryInterface, CORE_FACTORY_IID)

#endif // PROTOCOL_FACTORY_INTERFACE_H
