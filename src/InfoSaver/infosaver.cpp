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
