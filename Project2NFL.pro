QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CustomVacation.cpp \
    adminwindow.cpp \
    database.cpp \
    displaydata.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    stadium.cpp \
    team.cpp \
    user.cpp \
    vacationinfo.cpp

HEADERS += \
    BSTMap.h \
    CustomVacation.h \
    GraphBFS.h \
    GraphDFS.h \
    adminwindow.h \
    DijkestraMST.h \
    database.h \
    displaydata.h \
    login.h \
    mainwindow.h \
    stadium.h \
    structures.h \
    team.h \
    user.h \
    vacationinfo.h

FORMS += \
    CustomVacation.ui \
    adminwindow.ui \
    displaydata.ui \
    login.ui \
    mainwindow.ui \
    vacationinfo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
