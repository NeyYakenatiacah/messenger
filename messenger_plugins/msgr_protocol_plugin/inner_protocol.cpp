#include "inner_protocol.h"

QStringList InnerProtocol::objectIds() const
{
    return {};
}

QObject *InnerProtocol::createObjectInstance(const QString &id) const
{
    Q_UNUSED(id)
    return new QObject();
}
