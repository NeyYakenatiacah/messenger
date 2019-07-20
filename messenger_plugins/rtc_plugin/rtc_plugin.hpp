#ifndef INNER_PROTOCOL_H
#define INNER_PROTOCOL_H

#include <core/interface/factory.hpp>
//#include <gui/interface/factory.hpp>

class RTCPlugin : public QObject, public core::Factory
{
    Q_OBJECT

    Q_PLUGIN_METADATA(IID CORE_FACTORY_IID)

    Q_INTERFACES(core::Factory)

public:

    explicit RTCPlugin();
    virtual ~RTCPlugin() override;

    // core::Factory interface

    QStringList objectIds() const override;

    QObject *createObjectInstance(const QString &id) const override;

};

#endif // INNER_PROTOCOL_H
