QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bicicletta.cpp \
    bmx.cpp \
    deepptr.cpp \
    container.cpp \
    controller.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp \
    mountainbike.cpp \
    qfinalinsert.cpp \
    qsecondpage.cpp \
    qwidgetveicolo.cpp \
    veicolo.cpp \
    monopattino.cpp \
    monopattinoelettrico.cpp \
    veicoloelettrico.cpp \
    view.cpp \
    ebike.cpp

HEADERS += \
    bicicletta.h \
    bmx.h \
    deepptr.h \
    container.h \
    controller.h \
    mainwindow.h \
    model.h \
    mountainbike.h \
    qfinalinsert.h \
    qsecondpage.h \
    qwidgetveicolo.h \
    veicolo.h \
    monopattino.h \
    monopattinoelettrico.h \
    veicoloelettrico.h \
    view.h \
    ebike.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
