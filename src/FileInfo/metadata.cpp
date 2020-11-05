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
    DWORD dwRtnCode = 0;
    PSID pSidOwner = NULL;
    BOOL bRtnBool = TRUE;
    LPTSTR AcctName = NULL;
    LPTSTR DomainName = NULL;
    DWORD dwAcctName = 1, dwDomainName = 1;
    SID_NAME_USE eUse = SidTypeUnknown;
    PSECURITY_DESCRIPTOR pSD = NULL;

    if (hFile == INVALID_HANDLE_VALUE)
    {
//        DWORD dwErrorCode = 0;
//        dwErrorCode = GetLastError();
//        _tprintf(TEXT("CreateFile error = %d\n"), dwErrorCode);
        return QString();
    }

    // Get the owner SID of the file.
    dwRtnCode = GetSecurityInfo(
        hFile,
        SE_FILE_OBJECT,
        OWNER_SECURITY_INFORMATION,
        &pSidOwner,
        NULL,
        NULL,
        NULL,
        &pSD);

    // Check GetLastError for GetSecurityInfo error condition.
    if (dwRtnCode != ERROR_SUCCESS)
    {
//        DWORD dwErrorCode = 0;
//        dwErrorCode = GetLastError();
//        _tprintf(TEXT("GetSecurityInfo error = %d\n"), dwErrorCode);
        return QString();
    }

    // First call to LookupAccountSid to get the buffer sizes.
    bRtnBool = LookupAccountSid(
        NULL,           // local computer
        pSidOwner,
        AcctName,
        (LPDWORD)&dwAcctName,
        DomainName,
        (LPDWORD)&dwDomainName,
        &eUse);

    // Reallocate memory for the buffers.
    AcctName = (LPTSTR)GlobalAlloc(
        GMEM_FIXED,
        dwAcctName);

    // Check GetLastError for GlobalAlloc error condition.
    if (AcctName == NULL)
    {
//        DWORD dwErrorCode = 0;
//        dwErrorCode = GetLastError();
//        _tprintf(TEXT("GlobalAlloc error = %d\n"), dwErrorCode);
        return QString();
    }

    DomainName = (LPTSTR)GlobalAlloc(
           GMEM_FIXED,
           dwDomainName);

    // Check GetLastError for GlobalAlloc error condition.
    if (DomainName == NULL)
    {
//        DWORD dwErrorCode = 0;
//        dwErrorCode = GetLastError();
//        _tprintf(TEXT("GlobalAlloc error = %d\n"), dwErrorCode);
        return QString();

    }

    // Second call to LookupAccountSid to get the account name.
    bRtnBool = LookupAccountSid(
        NULL,                   // name of local or remote computer
        pSidOwner,              // security identifier
        AcctName,               // account name buffer
        (LPDWORD)&dwAcctName,   // size of account name buffer
        DomainName,             // domain name
        (LPDWORD)&dwDomainName, // size of domain name buffer
        &eUse);                 // SID type

    // Check GetLastError for LookupAccountSid error condition.
    if (bRtnBool == FALSE)
    {
//        DWORD dwErrorCode = 0;
//        dwErrorCode = GetLastError();
//        if (dwErrorCode == ERROR_NONE_MAPPED)
//          _tprintf(TEXT
//              ("Account owner not found for specified SID.\n"));
//        else
//          _tprintf(TEXT("Error in LookupAccountSid.\n"));
        return QString();

    }
    else
    if (bRtnBool == TRUE)
    {
        return QString::fromWCharArray(AcctName);
    }

    return QString();
}

Metadata::Metadata(const QString& path)
{
    auto handle = openFileRead(path);
    auto times = getTime(handle);
    dateTimeCreation = times.first;
    dateTimeModification = times.second;
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
