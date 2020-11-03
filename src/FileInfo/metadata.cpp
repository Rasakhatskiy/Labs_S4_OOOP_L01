#include "metadata.hpp"

HANDLE Metadata::openFileRead(const QString &path)
{
    return CreateFile(
        path.toStdWString().c_str(),
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        0,
        NULL);
}

QPair<DateTime, DateTime> Metadata::getTime(HANDLE hFile)
{
    FILETIME ftCreate, ftAccess, ftWrite;
    SYSTEMTIME stCreationUTC, stModificationUTC;
            //stLocalCreate, stLocalModify;

    // Retrieve the file times for the file.
    if (!GetFileTime(hFile, &ftCreate, &ftAccess, &ftWrite))
        return QPair<DateTime, DateTime>();

    // Convert the last-write time to local time.
    FileTimeToSystemTime(&ftCreate, &stCreationUTC);
    //SystemTimeToTzSpecificLocalTime(NULL, &stCreationUTC, &stLocalCreate);

    FileTimeToSystemTime(&ftWrite, &stModificationUTC);
    //SystemTimeToTzSpecificLocalTime(NULL, &stModificationUTC, &stLocalModify);

    DateTime dateCreation(
        stCreationUTC.wYear,
        stCreationUTC.wMonth,
        stCreationUTC.wDay,
        stCreationUTC.wHour,
        stCreationUTC.wMinute,
        stCreationUTC.wSecond);

    DateTime dateModification(
        stModificationUTC.wYear,
        stModificationUTC.wMonth,
        stModificationUTC.wDay,
        stModificationUTC.wHour,
        stModificationUTC.wMinute,
        stModificationUTC.wSecond);

    return QPair<DateTime, DateTime>(dateCreation, dateModification);
}

QString Metadata::getOwner(HANDLE hFile)
{

}

Metadata::Metadata(const QString& path)
{

}

Metadata::Metadata(
        const DateTime& dateTimeCreation,
        const DateTime& dateTimeModification,
        const uint64_t& length,
        const QString& owner,
        const QString& extension)
    :
           dateTimeCreation(dateTimeCreation),
           dateTimeModification(dateTimeModification),
           length(length),
           owner(owner),
           extension(extension)
{}
