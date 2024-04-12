QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TRANSLATIONS += q_de.ts q_us.ts

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    database_scheduler.cpp \
    dialog_getdatetime.cpp \
    dialog_starter.cpp \
    main.cpp \
    mainwindow.cpp \
    widget_edit.cpp \
    widget_neu_aufgabe.cpp \
    widget_studio.cpp

HEADERS += \
    database_scheduler.h \
    dialog_getdatetime.h \
    dialog_starter.h \
    mainwindow.h \
    widget_edit.h \
    widget_neu_aufgabe.h \
    widget_studio.h

FORMS += \
    dialog_getdatetime.ui \
    dialog_starter.ui \
    mainwindow.ui \
    widget_edit.ui \
    widget_neu_aufgabe.ui \
    widget_studio.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc

