#-------------------------------------------------
#
# Project created by QtCreator 2018-02-21T10:36:49
# Modified by TL
#-------------------------------------------------

# The .pro file is Qt's configuration project file.
# As Qt adds specific file formats and C++ keywords, an
# intermediate build step is performed, parsing all files
# to generate final files.

# This process is done by `qmake` - an executable from the
# Qt SDK. It also generate the final Makefiles for your project.

# A basic .pro file generally contains:
# 1. Qt modules used (core, gui, and so on)
QT       += core gui

# There are some great features that come with Qt and C++14.
# They will be shown in all its projects.
# For `GCC` and `Clang` compilers, you must add the following line of code:
CONFIG += c++14
# to the .pro file to enable C++14 on a Qt project

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# 2. Target name (todo, todo.exe, and so on)
TARGET = todo
# 3. Project template (app, lib, and so on)
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

# 4. Sources, Headers, and Forms (GUI define file)
SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

# ================= Next files in project====================
# The `mainwindow.h` and `mainwindow.cpp` files are headers/sources for
# the `mainwindow` class.
# The `mainwindow.ui` file is your UI design file in XML format.
