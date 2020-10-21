#include "fileinfo.hpp"

void FileInfo::construct(const QFileInfo fileInfo)
{
    _fullpath = fileInfo.absolutePath();
    _dateOfCreation = fileInfo.birthTime();
    _dateOfModification = fileInfo.lastModified();
    _isFile = fileInfo.isFile();
    _isSymLink = fileInfo.isSymLink();
    _symlinkPath = fileInfo.symLinkTarget();
    _isDir = fileInfo.isDir();
}

FileInfo::FileInfo(QString fullpath)
{
    construct(QFileInfo(fullpath));
}

FileInfo::FileInfo(QFileInfo fileInfo)
{
    construct(fileInfo);
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






