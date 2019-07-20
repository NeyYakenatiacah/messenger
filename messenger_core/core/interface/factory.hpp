#ifndef PROTOCOL_FACTORY_INTERFACE_H
#define PROTOCOL_FACTORY_INTERFACE_H

#include <QtPlugin>

#include <messenger_core_export.h>

//constexpr char CORE_FACTORY_IID[] = "Messenger.Core.Interface.Factory";
#define CORE_FACTORY_IID "Messenger.Core.Interface.Factory"

namespace core
{
class MESSENGER_CORE_EXPORT Factory
{
public:
    virtual ~Factory();

    virtual QStringList objectIds() const = 0;

    virtual QObject * createObjectInstance(const QString & id) const = 0;
};
}

Q_DECLARE_INTERFACE(core::Factory, CORE_FACTORY_IID)

#endif // PROTOCOL_FACTORY_INTERFACE_H
