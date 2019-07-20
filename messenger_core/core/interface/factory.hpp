#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <QtPlugin>

#include <messenger_core_export.h>

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

#endif // FACTORY_HPP
