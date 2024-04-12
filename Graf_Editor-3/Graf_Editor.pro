QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dlgoptionen.cpp \
    dlgsuchen_ersetzen.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    dlgoptionen.h \
    dlgsuchen_ersetzen.h \
    mainwindow.h

FORMS += \
    dlgoptionen.ui \
    dlgsuchen_ersetzen.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressourcen.qrc

TRANSLATIONS += translate_en.ts translate_ru.ts
