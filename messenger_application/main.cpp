#include <QApplication>
#include <QDebug>

#include <plugin-loader/core_plugin_dispatcher.h>

int main(int argc, char * argv[])
{
    QApplication a(argc, argv);

    CorePluginDispatcher dispatcher();

    return a.exec();
}
