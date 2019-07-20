#-------------------------------------------------
#
# Project created by QtCreator 2018-01-01T17:20:00
#
#-------------------------------------------------

QT += core network

QT -= gui

TARGET = rtc_plugin

CONFIG += plugin shared c++17

TEMPLATE = lib

include(config.pri)

SOURCES += \
    rtc_plugin.cpp
#    websocket_protocol.cpp
    
HEADERS += \
    rtc_plugin.hpp
#    websocket_protocol.h
 
