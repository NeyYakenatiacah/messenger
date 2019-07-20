#include "websocket_protocol.h"

WSProtocol::WSProtocol(QObject * parent)
    : ProtocolInterface(parent)
{
}

QString WSProtocol::id() const
{
    return {WSProtocol_IID};
}

QString WSProtocol::name() const
{
    return {"Custom WS protocol"};
}

QString WSProtocol::description() const
{
    return {"some description"};
}

ProtocolInterface::IOMode WSProtocol::ioModes() const
{
    return static_cast<IOMode>(IOType::Text);
}
