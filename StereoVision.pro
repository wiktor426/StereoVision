#-------------------------------------------------
#
# Project created by QtCreator 2013-12-01T12:39:40
#
#-------------------------------------------------

QT       += core gui
 QT += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StereoVision
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    stereovision.cpp \
    parametersforsgbm.cpp

HEADERS  += mainwindow.h \
    stereovision.h \
    parametersforsgbm.h

FORMS    += mainwindow.ui \
    parametersforsgbm.ui

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib

LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann
LIBS += -lopencv_nonfree
