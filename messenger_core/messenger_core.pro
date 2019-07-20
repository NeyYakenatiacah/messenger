 
QT -= gui

TARGET = messenger_core

TEMPLATE = lib

DEFINES += MESSENGER_CORE_LIBRARY

CONFIG += shared c++17

include(config.pri)

HEADERS += \
    core/loader/abstract_plugin_dispatcher.hpp \
    core/loader/plugin.hpp \
    core/loader/plugin_dispatcher.hpp \
    messenger_core_export.h \
    core/interface/account.hpp \
    core/interface/factory.hpp \
    core/interface/protocol.hpp \
    core/types/user_data.h


SOURCES += \
    src/interface/account.cpp \
    src/interface/factory.cpp \
    src/interface/protocol.cpp \
    src/loader/plugin.cpp \
    src/loader/abstract_plugin_dispatcher.cpp \
    src/loader/plugin_dispatcher.cpp \
    src/types/user_data.cpp
