# Messenger core library configuration file

include(../shared.pri)

CONFIG(debug,   debug|release) : DESTDIR = $${MESSENGER_BUILD_DIR}/debug

CONFIG(release, debug|release) : DESTDIR = $${MESSENGER_BUILD_DIR}/release
