#include <rtc_plugin.hpp>

RTCPlugin::RTCPlugin()
{

}

RTCPlugin::~RTCPlugin()
{

}

QStringList RTCPlugin::objectIds() const
{
    QStringList list;

    list << "this is id";

    return list;
}

QObject *RTCPlugin::createObjectInstance(const QString &id) const
{
    Q_UNUSED(id)

    return nullptr;
}
