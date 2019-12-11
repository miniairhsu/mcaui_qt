#-------------------------------------------------
#
# Project created by QtCreator 2019-12-09T11:27:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport network

TARGET = MCA
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
        mcawindow.cpp \
    network.cpp \
    udpclient.cpp \
    udpserver.cpp \
    dataprocessor.cpp \
    adprocessor.cpp \
    qcustomplot.cpp

HEADERS += \
        mcawindow.h \
    network.h \
    udpclient.h \
    udpserver.h \
    dataprocessor.h \
    adprocessor.h \
    dataheaders.h \
    qcustomplot.h

FORMS += \
        mcawindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += C:/Users/minia/Documents/academy/swlib/opencvLib_QT/install/include
DEPENDPATH += C:/Users/minia/Documents/academy/swlib/opencvLib_QT/install/include
INCLUDEPATH += C:/Users/minia/Documents/academy/swlib/eigen
LIBS += C:/Users/minia/Documents/academy/swlib/opencvLib_QT/install/x86/mingw/bin/libopencv_core410.dll
LIBS += C:/Users/minia/Documents/academy/swlib/opencvLib_QT/install/x86/mingw/bin/libopencv_highgui410.dll
LIBS += C:/Users/minia/Documents/academy/swlib/opencvLib_QT/install/x86/mingw/bin/libopencv_photo410.dll
LIBS += C:/Users/minia/Documents/academy/swlib/opencvLib_QT/install/x86/mingw/bin/libopencv_imgcodecs410.dll
LIBS += C:/Users/minia/Documents/academy/swlib/opencvLib_QT/install/x86/mingw/bin/opencv_ffmpeg410.dll
LIBS += C:/Users/minia/Documents/academy/swlib/opencvLib_QT/install/x86/mingw/bin/libopencv_dnn410.dll
LIBS += C:/Users/minia/Documents/academy/swlib/opencvLib_QT/install/x86/mingw/bin/libopencv_gapi410.dll
LIBS += C:/Users/minia/Documents/academy/swlib/opencvLib_QT/install/x86/mingw/bin/libopencv_calib3d410.dll
LIBS += C:/Users/minia/Documents/academy/swlib/opencvLib_QT/install/x86/mingw/bin/libopencv_stitching410.dll
LIBS += C:/Users/minia/Documents/academy/swlib/opencvLib_QT/install/x86/mingw/bin/libopencv_features2d410.dll
LIBS += C:/Users/minia/Documents/academy/swlib/opencvLib_QT/install/x86/mingw/bin/libopencv_objdetect410.dll













