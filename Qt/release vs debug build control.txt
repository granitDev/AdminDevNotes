### In your .pro file:
For example

Release:DESTDIR = release
Release:QMAKE_LFLAGS_WINDOWS += /MANIFESTUAC:level=\'requireAdministrator\'

Debug:DESTDIR = debug
