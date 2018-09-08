#ifndef WEBSOCKET_PROTOCOL_H
#define WEBSOCKET_PROTOCOL_H

#include <interfaces/protocol_interface.h>

class WSProtocol : public ProtocolInterface
{
    Q_OBJECT
public:
    WSProtocol();
};

#endif // WEBSOCKET_PROTOCOL_H
