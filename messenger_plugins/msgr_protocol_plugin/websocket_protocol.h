#ifndef WEBSOCKET_PROTOCOL_H
#define WEBSOCKET_PROTOCOL_H

#include <interfaces/protocol_interface.h>

constexpr char WSProtocol_IID[] = "Messenger.Protocol.WebSocket";

class WSProtocol : public ProtocolInterface
{
    Q_OBJECT
public:
    explicit WSProtocol(QObject * parent = nullptr);

    // ProtocolInterface interface

    QString id() const override;
    QString name() const override;
    QString description() const override;

    IOMode ioModes() const override;

    bool authorize(const QVariantMap &) override;

    QByteArray readAll(IOType) override;
    void sendData(IOType, const QByteArray &) override;

private:

};

#endif // WEBSOCKET_PROTOCOL_H
