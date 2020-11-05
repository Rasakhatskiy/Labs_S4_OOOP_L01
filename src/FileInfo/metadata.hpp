#ifndef METADATA_HPP
#define METADATA_HPP

#include <QString>
#include <QPair>

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

#include "DateTime.hpp"

class Metadata
{
private:
    HANDLE openFileRead(const QString& path);
    QPair<DateTime, DateTime> getTime(HANDLE hFile);
    QString getOwner(HANDLE hFile);

public:
    DateTime dateTimeCreation;
    DateTime dateTimeModification;
    uint64_t length;
    QString owner;
    QString extension;


    Metadata(const QString& path);
    Metadata(
        const DateTime& dateTimeCreation,
        const DateTime& dateTimeModification,
        const uint64_t& length,
        const QString& owner,
        const QString& extension);
};

#endif // METADATA_HPP
