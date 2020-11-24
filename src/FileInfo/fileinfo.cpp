#include "fileinfo.hpp"

void FileInfo::construct(const QFileInfo& fileInfo)
{
    _fullpath = fileInfo.absoluteFilePath();
    _dateOfCreation = fileInfo.birthTime();
    _dateOfModification = fileInfo.lastModified();
    _isFile = fileInfo.isFile();
    _isSymLink = fileInfo.isSymLink();
    _symlinkPath = fileInfo.symLinkTarget();
    _isDir = fileInfo.isDir();
    _length = fileInfo.size();
}

//FileInfo::FileInfo(const FileInfo &fileInfo)
//{
//    _fullpath = fileInfo._fullpath;
//    _dateOfCreation = fileInfo._dateOfCreation;
//    _dateOfModification = fileInfo._dateOfModification;
//    _isFile = fileInfo._isFile;
//    _isSymLink = fileInfo._isSymLink;
//    _symlinkPath = fileInfo._symlinkPath;
//    _isDir = fileInfo._isDir;
//    _length = fileInfo._length;
//}

FileInfo::FileInfo(const QString& fullpath)
{
    construct(QFileInfo(fullpath));
}

FileInfo::FileInfo(const QFileInfo& fileInfo)
{
    construct(fileInfo);
}

FileInfo::FileInfo(
    const QString& fullpath,
    const QDateTime& dateOfCreation,
    const QDateTime& dateOfModification,
    const uint64_t& length,
    const bool& isFile,
    const bool& isSymLink,
    const QString& symlinkPath,
    const bool& isDir)

{
    _fullpath = fullpath;
    _dateOfCreation = dateOfCreation;
    _dateOfModification = dateOfModification;
    _length = length;
    _isFile = isFile;
    _isSymLink = isSymLink;
    _symlinkPath = symlinkPath;
    _isDir = isDir;
}

QString FileInfo::getFullpath() const
{
    return _fullpath;
}

bool FileInfo::isFile() const
{
    return _isFile;
}

QDateTime FileInfo::getDateOfCreation() const
{
    return _dateOfCreation;
}

QDateTime FileInfo::getDateOfModification() const
{
    return _dateOfModification;
}

bool FileInfo::isSymLink() const
{
    return _isSymLink;
}

QString FileInfo::getSymlinkPath() const
{
    return _symlinkPath;
}

bool FileInfo::isDir() const
{
    return _isDir;
}

uint64_t FileInfo::getLength() const
{
    return _length;
}



QDataStream &operator<<(QDataStream &out, const FileInfo &fileInfo)
{
    out << fileInfo.getFullpath()
        << fileInfo.getDateOfCreation()
        << fileInfo.getDateOfModification()
        << fileInfo.getLength()
        << fileInfo.isFile()
        << fileInfo.isSymLink()
        << fileInfo.getSymlinkPath()
        << fileInfo.isDir();
    return out;
}

QDataStream &operator>>(QDataStream &in, FileInfo &fileInfo)
{
    QString fullpath;
    QDateTime dateOfCreation;
    QDateTime dateOfModification;
    uint64_t size;
    bool isFile;
    bool isSymLink;
    QString symlinkPath;
    bool isDir;

    in  >> fullpath
        >> dateOfCreation
        >> dateOfModification
        >> size
        >> isFile
        >> isSymLink
        >> symlinkPath
        >> isDir;

    fileInfo = FileInfo(
        fullpath,
        dateOfCreation,
        dateOfModification,
        size,
        isFile,
        isSymLink,
        symlinkPath,
        isDir);

    return in;
}
