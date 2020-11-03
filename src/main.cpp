#include "Forms/WindowMain.hpp"
#include "InfoSaver/infosaver.hpp"

#include <QApplication>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <iostream>
#include <string>
#include <QStorageInfo>

#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <fileapi.h>
#include <timezoneapi.h>
#include <SDKDDKVer.h>


BOOL GetLastWriteTime(HANDLE hFile, LPTSTR lpszString, DWORD dwSize)
{
    FILETIME ftCreate, ftAccess, ftWrite;
    SYSTEMTIME stUTC, stLocal;
    DWORD dwRet;

    // Retrieve the file times for the file.
    if (!GetFileTime(hFile, &ftCreate, &ftAccess, &ftWrite))
        return FALSE;

    // Convert the last-write time to local time.
    FileTimeToSystemTime(&ftWrite, &stUTC);
    SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);

    qDebug() << "Created on: "
             << stUTC.wDay
             << stUTC.wMonth
             << stUTC.wYear
             << stUTC.wHour
             << stUTC.wMinute;

    // Build a string showing the date and time.
    dwRet = StringCchPrintf(lpszString, dwSize,
        TEXT("%02d/%02d/%d  %02d:%02d"),
        stLocal.wMonth, stLocal.wDay, stLocal.wYear,
        stLocal.wHour, stLocal.wMinute);

    if( S_OK == dwRet )
        return TRUE;
    else return FALSE;
}

/*! Main app function. Creates main form and sets stylesheet.*/
int main(int argc, char *argv[])
{

//    auto file = CreateFileA(
//                "D:\\Results.txt",
//                GENERIC_READ,
//                FILE_SHARE_WRITE,
//                0,
//                OPEN_EXISTING,
//                0x02000000,
//                0);


    HANDLE hFile;
    TCHAR szBuf[MAX_PATH];

//    if( argc != 2 )
//    {
//        printf("This sample takes a file name as a parameter\n");
//        return 0;
//    }
    hFile = CreateFile(
            L"D:\\Results.txt",
            GENERIC_READ,
            FILE_SHARE_READ,
            NULL,
            OPEN_EXISTING,
            0,
            NULL);

    if(hFile == INVALID_HANDLE_VALUE)
    {
        qDebug() << "CreateFile failed with\n" << GetLastError();
        return 0;
    }
    if(GetLastWriteTime( hFile, szBuf, MAX_PATH ))
    {
        QString s = (LPSTR)szBuf;
        qDebug() << "Last write time is: " << szBuf;
    }

    CloseHandle(hFile);


    //qDebug() << lpszString;

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
