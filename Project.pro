#-------------------------------------------------
#
# Project created by QtCreator 2019-07-04T17:38:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        adminform.cpp \
        admininfo.cpp \
        apartment.cpp \
        apartmentform.cpp \
        apartmentformedit.cpp \
        building.cpp \
        bulding.cpp \
        file.cpp \
        house.cpp \
        main.cpp \
        mainwindow.cpp \
        north_villa.cpp \
        northvillaform.cpp \
        northvillaformedit.cpp \
        rentfile.cpp \
        rentform.cpp \
        rentshow.cpp \
        search.cpp \
        sellfile.cpp \
        sellform.cpp \
        sellshow.cpp \
        signinform.cpp \
        signupform.cpp \
        south_villa.cpp \
        southvillaform.cpp \
        southvillaformedit.cpp \
        userbuildingshow.cpp \
        userform.cpp \
        userinfo.cpp \
        userrentshow.cpp \
        usersellshow.cpp

HEADERS += \
        adminform.h \
        admininfo.h \
        apartment.h \
        apartmentform.h \
        apartmentformedit.h \
        building.h \
        bulding.h \
        file.h \
        house.h \
        mainwindow.h \
        north_villa.h \
        northvillaform.h \
        northvillaformedit.h \
        rentfile.h \
        rentform.h \
        rentshow.h \
        search.h \
        sellfile.h \
        sellform.h \
        sellshow.h \
        signinform.h \
        signupform.h \
        south_villa.h \
        southvillaform.h \
        southvillaformedit.h \
        userbuildingshow.h \
        userform.h \
        userinfo.h \
        userrentshow.h \
        usersellshow.h

FORMS += \
        adminform.ui \
        apartmentform.ui \
        apartmentformedit.ui \
        building.ui \
        bulding.ui \
        mainwindow.ui \
        northvillaform.ui \
        northvillaformedit.ui \
        rentform.ui \
        rentshow.ui \
        search.ui \
        sellform.ui \
        sellshow.ui \
        signinform.ui \
        signupform.ui \
        southvillaform.ui \
        southvillaformedit.ui \
        userbuildingshow.ui \
        userform.ui \
        userrentshow.ui \
        usersellshow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
