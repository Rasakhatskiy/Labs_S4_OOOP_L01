#include "Forms/WindowMain.hpp"
#include "InfoSaver/infosaver.hpp"

#include <QApplication>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <iostream>
#include <QStorageInfo>

/*! Main app function. Creates main form and sets stylesheet.*/
int main(int argc, char *argv[])
{
    foreach (const QStorageInfo &storage, QStorageInfo::mountedVolumes()) {
          if (storage.isValid() && storage.isReady()) {
              if (!storage.isReadOnly()) {
                  qDebug() << "name:" << storage.name();
                  qDebug() << "drive letter:" << storage.rootPath();
                  qDebug() << "fileSystemType:" << storage.fileSystemType();
                  qDebug() << "size:" << storage.bytesTotal()/1000/1000 << "MB";
                  qDebug() << "availableSize:" << storage.bytesAvailable()/1000/1000 << "MB";
                  qDebug() << "\n\n";
              }
          }
      }



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
