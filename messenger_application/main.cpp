#include <QApplication>

#include <core/loader/plugin_dispatcher.hpp>

#include <QDir>
#include <QDebug>

int main(int argc, char * argv[])
{
    QApplication a(argc, argv);
    core::PluginDispatcher dispatcher{};
    qDebug() << QDir::currentPath();
    dispatcher.addPlugin("plugins/librtc_plugin.so");
    qDebug() << dispatcher.objectIds();
    return a.exec();
}
