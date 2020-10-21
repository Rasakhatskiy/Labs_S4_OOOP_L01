#ifndef INFOSAVER_HPP
#define INFOSAVER_HPP

#include<fstream>

#include <QList>
#include <QFileInfo>

/*!
 * \brief Class for saving information about files to binary file.
 */
class InfoSaver
{
private:
    /*! List of file info. */
    QList<QFileInfo> files;
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
     * \param fileInfo File info.
     */
    void add(QFileInfo fileInfo);

    /*!
     * \brief Creates file infos and adds them to list.
     * \param filePaths List of full file paths.
     */
    void add(QList<QString> filePaths);

    /*!
     * \brief Adds list of file info to list.
     * \param fileInfos File info list.
     */
    void add(QList<QFileInfo> fileInfos);

    /*!
     * \brief Saves list of file info to binary file. If file exists, rewrites it.
     * \param resultFilePath Full result file path.
     */
    void save(QString resultFilePath);
};

#endif // INFOSAVER_HPP
