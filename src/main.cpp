#include "Forms/WindowMain.hpp"

#include <QApplication>
#include <QFile>

/*! Main app function. Creates main form and sets stylesheet.*/
int main(int argc, char *argv[])
{
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
