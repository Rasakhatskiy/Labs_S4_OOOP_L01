#include "metadata.hpp"

Metadata::Metadata(const QString& path)
{
    auto handle = openFileRead(path);

    if (handle)
    {
        auto times = getTime(handle);
        dateTimeCreation = times.first;
        dateTimeModification = times.second;

        owner = getOwner(handle);

        auto info = QFileInfo(path);
        length = info.size();

        extension = info.completeSuffix();

        CloseHandle(handle);
    }
    else
    {
        throw std::invalid_argument("Cannot open file");
    }
}

Metadata::Metadata(
        const QDateTime& dateTimeCreation,
        const QDateTime& dateTimeModification,
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

HANDLE Metadata::openFileWrite(const QString &path)
{
    return CreateFile(
        path.toStdWString().c_str(),
        FILE_GENERIC_WRITE,
        FILE_SHARE_WRITE,
        NULL,
        OPEN_EXISTING,
        0,
        NULL);
}

QPair<QDateTime, QDateTime> Metadata::getTime(HANDLE hFile, QString path)
{
    FILETIME ftCreate, ftAccess, ftWrite;
    SYSTEMTIME stCreationUTC, stModificationUTC;
            //stLocalCreate, stLocalModify;

    // Retrieve the file times for the file.
    if (!GetFileTime(hFile, &ftCreate, &ftAccess, &ftWrite))
        return QPair<QDateTime, QDateTime>();

    // Convert the last-write time to local time.
    FileTimeToSystemTime(&ftCreate, &stCreationUTC);
    //SystemTimeToTzSpecificLocalTime(NULL, &stCreationUTC, &stLocalCreate);

    FileTimeToSystemTime(&ftWrite, &stModificationUTC);
    //SystemTimeToTzSpecificLocalTime(NULL, &stModificationUTC, &stLocalModify);

    QDateTime dateCreation(
        QDate(
            stCreationUTC.wYear,
            stCreationUTC.wMonth,
            stCreationUTC.wDay),
        QTime(
            stCreationUTC.wHour,
            stCreationUTC.wMinute,
            stCreationUTC.wSecond));

    QDateTime dateModification(
        QDate(
            stModificationUTC.wYear,
            stModificationUTC.wMonth,
            stModificationUTC.wDay),
        QTime(
            stModificationUTC.wHour,
            stModificationUTC.wMinute,
            stModificationUTC.wSecond));

    auto info = QFileInfo(path);

    return QPair<QDateTime, QDateTime>(info.birthTime(), info.lastModified());
}

bool Metadata::setTime(HANDLE hFile, QPair<QDateTime, QDateTime> pair)
{
    SYSTEMTIME timeCreation = dateTimeFromQDateTime(pair.first);
    SYSTEMTIME timeModification = dateTimeFromQDateTime(pair.second);
    SYSTEMTIME timeAccess;

    GetSystemTime(&timeAccess);

    FILETIME ftCreate, ftAccess, ftWrite;

    SystemTimeToFileTime(&timeCreation, &ftCreate);
    SystemTimeToFileTime(&timeModification, &ftWrite);
    SystemTimeToFileTime(&timeAccess, &ftAccess);

    return SetFileTime(
        hFile,
        &ftCreate,
        &ftAccess,
        &ftWrite);

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

bool Metadata::setOwner(HANDLE hFile, const QString &ownerName)
{
    PSID sid;
    ConvertStringSidToSid(ownerName.toStdWString().c_str(), &sid);

    SetSecurityInfo(
        hFile,
        SE_FILE_OBJECT,
        OWNER_SECURITY_INFORMATION,
        &sid,
        NULL,
        NULL,
        NULL);

    return true;
}

bool Metadata::save(const QString &path)
{
    auto handle = openFileWrite(path);
    if (!setTime(
        handle,
        QPair<QDateTime, QDateTime>(
            dateTimeCreation,
            dateTimeModification)))
        return false;

    if (!setOwner(handle, owner))
        return false;


    CloseHandle(handle);

    QFileInfo info(path);
    QString newPath = info.path() + info.baseName() + "." + extension;
    QFile::rename(path, newPath);

    return true;
}

SYSTEMTIME Metadata::dateTimeFromQDateTime(const QDateTime &dateTime)
{
    SYSTEMTIME timeCreation;
    timeCreation.wYear = dateTime.date().year();
    timeCreation.wMonth = dateTime.date().month();
    timeCreation.wDay = dateTime.date().day();
    timeCreation.wHour = dateTime.time().hour();
    timeCreation.wMinute = dateTime.time().minute();
    timeCreation.wSecond = dateTime.time().second();
    return timeCreation;
}

QList<FileInfo> Metadata::doSearch(
        const QString &startSearchPath,
        const bool &isAND)
{
    auto fileInfoScan = QFileInfo(startSearchPath);
    if (!fileInfoScan.exists() ||
        !fileInfoScan.isDir())
        throw std::invalid_argument("Unable to open file " + startSearchPath.toStdString());

    auto dirInfo = QDir(startSearchPath);
    auto allFiles = dirInfo.entryList(
       QDir::NoDotAndDotDot |
       QDir::System |
       QDir::Hidden  |
       QDir::AllDirs |
       QDir::Files,
       QDir::DirsFirst);

    QList<FileInfo> result;
    for (auto &file : allFiles)
    {
        auto fileInfoTemp = QFileInfo(startSearchPath + "/" + file);
        auto fullpath = fileInfoTemp.absoluteFilePath();
        qDebug() << fullpath;
        if (fileInfoTemp.isDir())
            result.append(doSearch(fullpath, isAND));
        else
            if (matchesCriterion(fullpath, isAND))
                result.append(FileInfo(fullpath));
    }
    return result;
}

bool Metadata::matchesCriterion(
        const QString& path,
        const bool& isAND)
{
    auto info = QFileInfo(path);
    auto file = openFileRead(path);
    auto dates = getTime(file, path);
    auto owner = getOwner(file);
//    qDebug() << this->dateTimeCreation.toString("yyyy-MM-dd HH-mm-ss.zzz");
//    qDebug() << dates.first.toString("yyyy-MM-dd HH-mm-ss.zzz");
//    qDebug() << "============\n";
    CloseHandle(file);
    if (isAND)
        return
            (this->dateTimeCreation.toString("yyyy-MM-dd HH-mm") == dates.first.toString("yyyy-MM-dd HH-mm")) &&
            (this->dateTimeModification.toString("yyyy-MM-dd HH-mm") == dates.second.toString("yyyy-MM-dd HH-mm")) &&
            ((qint64)this->length == info.size()) &&
            (this->owner == owner) &&
            (this->extension == info.completeSuffix());
    else
        return
            (this->dateTimeCreation.toString("yyyy-MM-dd HH-mm") == dates.first.toString("yyyy-MM-dd HH-mm")) ||
            (this->dateTimeModification.toString("yyyy-MM-dd HH-mm") == dates.second.toString("yyyy-MM-dd HH-mm")) ||
            ((qint64)this->length == info.size()) ||
            (this->owner == owner) ||
            (this->extension == info.completeSuffix());
}
