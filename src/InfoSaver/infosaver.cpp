#include "infosaver.hpp"

InfoSaver::InfoSaver()
{

}

void InfoSaver::add(QString fullpath)
{
    this->files.append(QFileInfo(fullpath));
}

void InfoSaver::add(QFileInfo fileInfo)
{
    this->files.append(fileInfo);
}

void InfoSaver::add(QList<QString> filePaths)
{
    for(auto &i : filePaths)
        this->files.append(QFileInfo(i));
}

void InfoSaver::add(QList<QFileInfo> fileInfos)
{
    this->files.append(fileInfos);
}

void InfoSaver::save(QString resultFilePath)
{
    std::ofstream file(resultFilePath.toStdString(), std::ios::out | std::ios::binary);

    if(!file)
        throw std::invalid_argument("Unable to open file " + resultFilePath.toStdString());

    size_t size = this->files.size();
    file.write((char*)&size, sizeof(size));

    file.write((char*)&this->files[0], size * sizeof(QFileInfo));
    file.close();
    if(!file.good())
        throw std::runtime_error("Writing error: " + resultFilePath.toStdString());
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
        auto path = scanDirPath + "\\" + file;
        auto fileInfoTemp = QFileInfo(path);
        if (fileInfoTemp.isDir())
            scan(path);
        else
            this->files.append(fileInfoTemp);
    }
}

void InfoSaver::print()
{
    for(auto &string : files)
        qDebug() << string.absoluteFilePath();
}




















