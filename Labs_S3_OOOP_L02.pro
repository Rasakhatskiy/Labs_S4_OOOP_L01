QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/FileInfo/fileinfo.cpp \
    src/Forms/windowtree.cpp \
    src/InfoSaver/infosaver.cpp \
    src/Tree/treeitem.cpp \
    src/Tree/treemodel.cpp \
    src/main.cpp \
    src/Forms/WindowMain.cpp

HEADERS += \
    src/FileInfo/fileinfo.hpp \
    src/Forms/WindowMain.hpp \
    src/Forms/windowtree.hpp \
    src/Tree/treeitem.hpp \
    src/Tree/treemodel.hpp \
    src/InfoSaver/infosaver.hpp \

FORMS += \
    src/Forms/WindowMain.ui \
    src/Forms/windowtree.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    src/Forms/stylesheet.qss

RESOURCES += \
    src/resources.qrc
