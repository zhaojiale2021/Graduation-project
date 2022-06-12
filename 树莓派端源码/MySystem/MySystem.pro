#-------------------------------------------------
#
# Project created by QtCreator 2021-02-16T10:29:58
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MySystem
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
        main.cpp \
        widget.cpp \
    ultrasonic.cpp \
    xunji.cpp \
    CameraThread.cpp

HEADERS += \
        widget.h \
    ultrasonic.h \
    xunji.h \
    CameraThread.h

FORMS += \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv4 \
                /usr/local/include/opencv4/opencv2 \
                /usr/local/include/raspicam

LIBS += /usr/local/lib/libopencv_calib3d.so.4.5.3 \
        /usr/local/lib/libopencv_core.so.4.5.3 \
        /usr/local/lib/libopencv_features2d.so.4.5.3 \
        /usr/local/lib/libopencv_highgui.so.4.5.3\
        /usr/local/lib/libopencv_imgcodecs.so.4.5.3 \
        /usr/local/lib/libopencv_imgproc.so.4.5.3 \
        /usr/local/lib/libopencv_ml.so.4.5.3 \
        /usr/local/lib/libopencv_objdetect.so.4.5.3 \
        /usr/local/lib/libopencv_photo.so.4.5.3 \
        /usr/local/lib/libopencv_stitching.so.4.5.3 \
        /usr/local/lib/libopencv_video.so.4.5.3 \
        /usr/local/lib/libopencv_imgcodecs.so.4.5.3 \
        /usr/local/lib/libopencv_tracking.so.4.5.3 \
        /usr/local/lib/libopencv_videoio.so.4.5.3 \
        /usr/local/lib/libopencv_face.so.4.5.3
LIBS += -lwiringPi
LIBS += -lopencv_highgui
LIBS += -lopencv_core
LIBS += -lopencv_video
LIBS += -lopencv_videoio
LIBS += -lopencv_imgproc

LIBS += /usr/local/lib/lib*
