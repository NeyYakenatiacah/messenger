 
TEMPLATE = subdirs

SUBDIRS += \
	messenger_core \
        messenger_application \
        messenger_plugins \

# Sub directories

messenger_core.subdir = messenger_core

messenger_application.subdir = messenger_application

messenger_plugins.subdir = messenger_plugins

# Dependencies

messenger_application.depends = messenger_core

messenger_plugins.depends = messenger_core
