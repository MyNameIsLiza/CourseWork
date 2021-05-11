QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    algorithms.cpp \
    auxiliary.cpp \
    creategraphwindow.cpp \
    edge.cpp \
    graph.cpp \
    mixedgraph.cpp \
    orientedgraph.cpp \
    disorientedgraph.cpp \
    main.cpp \
    mainwindow.cpp \
    mygraphicview.cpp \
    vertex.cpp

HEADERS += \
    algorithms.h \
    auxiliary.h \
    creategraphwindow.h \
    edge.h \
    graph.h \
    mixedgraph.h \
    orientedgraph.h \
    disorientedgraph.h \
    mainwindow.h \
    mygraphicview.h \
    vertex.h

FORMS += \
    algorithms.ui \
    creategraphwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
