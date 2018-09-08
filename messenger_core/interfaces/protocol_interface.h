#ifndef PROTOCOL_INTERFACE_H
#define PROTOCOL_INTERFACE_H

#include <QObject>

#include <messenger_core_export.h>
#include "core_factory_interface.h"

class MESSENGER_CORE_EXPORT ProtocolInterface : public QObject
{
    Q_OBJECT
public:

    typedef quint16 IOMode;
    enum class IOType
    {
        Text =  1,
        File =  2,
        Audio = 4,
        Video = 8
    };

    enum class State
    {
        NotAuthorized = 1,
        Ready = 2
    };

    explicit ProtocolInterface(QObject *parent = nullptr);
    virtual ~ProtocolInterface();

    virtual QString id() const = 0;
    virtual QString name() const = 0;
    virtual QString description() const = 0;

    virtual IOMode ioModes() const = 0;

    virtual bool authorize(const QVariantMap&) = 0;

    // mb otdel'no audio/video/text/file
    virtual QByteArray readAll(IOType) = 0;
    virtual void sendData(IOType, const QByteArray&) = 0;

    virtual QVariantMap options() const;
    virtual void setOptions(const QVariantMap&) const;

    // getUserData
    // getContactList

signals:

    void stateChanged();
    void dataReceived(IOType);

public slots:

private:
    CoreFactoryInterface * m_factory;
};

#endif // PROTOCOL_INTERFACE_H
