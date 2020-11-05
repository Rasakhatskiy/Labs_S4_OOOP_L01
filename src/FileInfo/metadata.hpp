#ifndef METADATA_HPP
#define METADATA_HPP

#include <QString>
#include <QPair>
#include <QDateTime>

#include <windows.h>
#include <WinBase.h>
#include <tchar.h>
#include <strsafe.h>
#include <fileapi.h>
#include <timezoneapi.h>
#include <SDKDDKVer.h>
#include <AccCtrl.h>
#include <AclAPI.h>
#include "accctrl.h"
#include "aclapi.h"
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib,"user32.lib")


class Metadata
{
private:
    HANDLE openFileRead(const QString& path);
    QPair<QDateTime, QDateTime> getTime(HANDLE hFile);
    QString getOwner(HANDLE hFile);

public:
    QDateTime dateTimeCreation;
    QDateTime dateTimeModification;
    uint64_t length;
    QString owner;
    QString extension;


    Metadata(const QString& path);
    Metadata(
        const QDateTime& dateTimeCreation,
        const QDateTime& dateTimeModification,
        const uint64_t& length,
        const QString& owner,
        const QString& extension);
};

#endif // METADATA_HPP
