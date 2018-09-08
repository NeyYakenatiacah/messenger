#-------------------------------------------------
#
# Project created by QtCreator 2018-01-01T17:20:00
#
#-------------------------------------------------

QT += core network

QT -= gui

CONFIG += c++11

TARGET = msgr_protocol_plugin

CONFIG += plugin shared c++17

TEMPLATE = lib

# Include current config

include(config.pri)

SOURCES += \
    inner_protocol_plugin.cpp \
    websocket_protocol.cpp
    
HEADERS += \
    inner_protocol_plugin.h \
    websocket_protocol.h
 
