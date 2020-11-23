#include "infosaver.hpp"

InfoSaver::InfoSaver()
{

}

void InfoSaver::add(QString fullpath)
{
    this->files.append(FileInfo(fullpath));
}

void InfoSaver::add(QFileInfo fileInfo)
{
    this->files.append(FileInfo(fileInfo));
}

void InfoSaver::add(QList<QString> filePaths)
{
    std::for_each(filePaths.begin(), filePaths.end(),
        [] (const QString& qString) { return FileInfo(qString);});
}

void InfoSaver::add(QList<QFileInfo> fileInfos)
{
    std::for_each(fileInfos.begin(), fileInfos.end(),
        [] (const QFileInfo& qFileInfo) { return FileInfo(qFileInfo);});
}

void InfoSaver::save(QString resultFilePath)
{

    QFile file(resultFilePath);
    if(!file.open(QIODevice::WriteOnly))
    {
        throw std::invalid_argument("Unable to open file " + resultFilePath.toStdString());
        return;
    }

    QDataStream writer(&file);
    auto size = files.size();

    writer << size;
    for (int i = 0; i < size; ++i)
        writer << files[i];

    file.close();
}

void InfoSaver::open(const QString &filePath)
{
     QFile file(filePath);
     if(!file.open(QIODevice::ReadOnly))
     {
         throw std::invalid_argument("Unable to open file " + filePath.toStdString());
         return;
     }

    QDataStream reader(&file);
    int size;
    reader >> size;

    for (int i = 0; i < size; ++i)
    {
        FileInfo fileInfo;
        reader >> fileInfo;
        files.append(fileInfo);
    }

    file.close();
}



void InfoSaver::scan(QString scanDirPath)
{
    auto fileInfoScan = QFileInfo(scanDirPath);
    if (!fileInfoScan.exists() ||
        !fileInfoScan.isDir())
        throw std::invalid_argument("Unable to open file " + scanDirPath.toStdString());

    auto dirInfo = QDir(scanDirPath);
    auto allFiles = dirInfo.entryList(
       QDir::NoDotAndDotDot |
       QDir::System |
       QDir::Hidden  |
       QDir::AllDirs |
       QDir::Files,
       QDir::DirsFirst);

    for (auto &file : allFiles)
    {
        auto fileInfoTemp = QFileInfo(scanDirPath + "/" + file);
        auto fullpath = fileInfoTemp.absoluteFilePath();
        if (fileInfoTemp.isDir())
            scan(fullpath);
        else
        {
            auto info = FileInfo(fullpath);
            this->files.append(info);

        }
    }
}

void InfoSaver::print()
{
    for(auto &file : files)
        qDebug() << file.getFullpath();
}

QStringList InfoSaver::toQStringList()
{
    QStringList list;
    for (auto &file : files)
        list.append(file.getFullpath());
    return list;
}

QList<FileInfo> InfoSaver::getFileInfos() const
{
    return files;
}




















