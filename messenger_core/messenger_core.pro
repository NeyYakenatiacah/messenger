 
QT -= gui

TARGET = messenger_core

TEMPLATE = lib

DEFINES += MESSENGER_CORE_LIBRARY

CONFIG += shared c++17

include(config.pri)

HEADERS += \
    messenger_core_export.h \
    interfaces/core_factory_interface.h \
    plugin-loader/core_plugin.h \
    plugin-loader/abstract_plugin_dispatcher.h \
    plugin-loader/core_plugin_dispatcher.h \
    interfaces/account_interface.h \
    interfaces/protocol_interface.h


SOURCES += \
    interfaces/core_factory_interface.cpp \
    plugin-loader/core_plugin.cpp \
    plugin-loader/abstract_plugin_dispatcher.cpp \
    plugin-loader/core_plugin_dispatcher.cpp \
    interfaces/account_interface.cpp \
    interfaces/protocol_interface.cpp
