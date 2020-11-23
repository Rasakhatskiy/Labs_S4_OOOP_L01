#include "fileinfo.hpp"

void FileInfo::construct(const QFileInfo fileInfo)
{
    _fullpath = fileInfo.absoluteFilePath();
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

FileInfo::FileInfo(
    QString fullpath,
    QDateTime dateOfCreation,
    QDateTime dateOfModification,
    bool isFile,
    bool isSymLink,
    QString symlinkPath,
    bool isDir) :
    _fullpath(fullpath),
    _dateOfCreation(dateOfCreation),
    _dateOfModification(dateOfModification),
    _isFile(isFile),
    _isSymLink(isSymLink),
    _symlinkPath(symlinkPath),
    _isDir(isDir)
{}

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



QDataStream &operator<<(QDataStream &out, const FileInfo &fileInfo)
{
    out << fileInfo.getFullpath()
        << fileInfo.getDateOfCreation()
        << fileInfo.getDateOfModification()
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
    bool isFile;
    bool isSymLink;
    QString symlinkPath;
    bool isDir;

    in  >> fullpath
        >> dateOfCreation
        >> dateOfModification
        >> isFile
        >> isSymLink
        >> symlinkPath
        >> isDir;

    fileInfo = FileInfo(
        fullpath,
        dateOfCreation,
        dateOfModification,
        isFile,
        isSymLink,
        symlinkPath,
        isDir);

    return in;
}
