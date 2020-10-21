#include "Forms/WindowMain.hpp"
#include "InfoSaver/infosaver.hpp"

#include <QApplication>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <iostream>

/*! Main app function. Creates main form and sets stylesheet.*/
int main(int argc, char *argv[])
{

    InfoSaver saver;
    saver.add("D:\\Documents\\Sharaga v.2\\Vol 2\\OOOP\\QT_Demo\\main.cpp");
    saver.add("D:\\Documents\\Sharaga v.2\\Vol 2\\OOOP\\QT_Demo\\mainwindow.cpp");
    saver.add("D:\\Documents\\Sharaga v.2\\Vol 2\\OOOP\\QT_Demo\\mainwindow.hpp");
    saver.add("D:\\Documents\\Sharaga v.2\\Vol 2\\OOOP\\QT_Demo\\mainwindow.ui");

    saver.save("D:\\Temp\\test");


    QFileInfo fi("D:\\Documents\\Sharaga v.2\\Vol 2\\OOOP\\QT_Demo\\main.cpp");
    fi.

    // Create main window
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // Set stylesheet
    QFile styleFile(":/res/forms/stylesheet.qss");
    styleFile.open(QFile::ReadOnly);
    auto qstr = QString::fromLatin1(styleFile.readAll());
    a.setStyleSheet(qstr);
    styleFile.close();

    return a.exec();

}
