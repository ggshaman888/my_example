QT += widgets serialport
requires(qtConfig(combobox))

TARGET = terminal
TEMPLATE = app

SOURCES += \
    consoleform.cpp \
    main.cpp \
    runprepare.cpp \
    setbaikal.cpp \
    settingsdialog.cpp \
    console.cpp

HEADERS += \
    consoleform.h \
    runprepare.h \
    setbaikal.h \
    settingsdialog.h \
    console.h

FORMS += \
    consoleform.ui \
    settingsdialog.ui

RESOURCES += \
    terminal.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/serialport/terminal
INSTALLS += target
