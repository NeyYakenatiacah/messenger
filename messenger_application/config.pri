# Messenger basic library configuration file

# Shared config

include(../shared.pri)

CONFIG(debug,   debug|release) : DESTDIR = $${MESSENGER_BUILD_DIR}/debug

CONFIG(release, debug|release) : DESTDIR = $${MESSENGER_BUILD_DIR}/release

# Configure library

# Messenger libraries

INCLUDEPATH += ../messenger_core 

DEPENDPATH  += ../messenger_core

CONFIG(debug, debug|release) {

    LIBS += -L$${MESSENGER_BUILD_DIR}/debug

    LIBS += -lmessenger_core
}

CONFIG(release, debug|release) {

    LIBS += -L$${MESSENGER_BUILD_DIR}/release

    LIBS += -lmessenger_core
}
