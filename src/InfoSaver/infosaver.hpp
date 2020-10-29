#ifndef INFOSAVER_HPP
#define INFOSAVER_HPP

#include<fstream>

#include <QList>
#include <QDir>
#include <QFileInfo>
#include <QtDebug>
#include "../FileInfo/fileinfo.hpp"

/*!
 * \brief Class for saving information about files to binary file.
 */
class InfoSaver
{
private:
    /*! List of file info. */
    QList<FileInfo> files;
public:
    /*! Default constructor. */
    InfoSaver();

    /*!
     * \brief Creates file info and adds it to list.
     * \param[in] fullpath Full path of the file.
     */
    void add(QString fullpath);

    /*!
     * \brief Adds given file info to list.
     * \param[in] fileInfo File info.
     */
    void add(QFileInfo fileInfo);

    /*!
     * \brief Creates file infos and adds them to list.
     * \param[in] filePaths List of full file paths.
     */
    void add(QList<QString> filePaths);

    /*!
     * \brief Adds list of file info to list.
     * \param[in] fileInfos File info list.
     */
    void add(QList<QFileInfo> fileInfos);

    /*!
     * \brief Saves list of file info to binary file. If file exists, rewrites it.
     * \param[in] resultFilePath Full result file path.
     */
    void save(QString resultFilePath);

    /*!
     * \brief Recursivaly scans directory for files and saves info about them.
     * \param[in] scanDirPath
     */
    void scan(QString scanDirPath);

    /*!
     * \brief Prints list to debug console.
     */
    void print();
};

#endif // INFOSAVER_HPP
