#ifndef FILEINFO_HPP
#define FILEINFO_HPP

#include <QFileInfo>
#include <QDateTime>

/*!
 * The FileInfo class made for saving info on disk
 * (you cannot do this with QFileInfo)
 */
class FileInfo
{
    /*! Full path of the file*/
    QString _fullpath;

    /*! Date of creation*/
    QDateTime _dateOfCreation;

    /*! Date of modification*/
    QDateTime _dateOfModification;

    /*! Is file file (O_o)*/
    bool _isFile;

    /*! Is file symlink */
    bool _isSymLink;

    /*! Path reffered by symlink */
    QString _symlinkPath;

    /*! Is file directory */
    bool _isDir;

    /*!
     * \brief Copies parameters from QFileInfo to FileInfo
     * \param fileInfo
     */
    void construct(const QFileInfo fileInfo);

public:
    /*!
     * \brief Constructs file info from file system entry.
     * \param fullpath Full path of the file.
     */
    FileInfo(QString fullpath);

    /*!
     * \brief Copies parameters from QFileInfo to FileInfo
     * \param fileInfo
     */
    FileInfo(QFileInfo fileInfo);

    /*!
     * \return Full path of file
     */
    QString getFullpath() const;

    /*!
     * \return Date of creation
     */
    QDateTime getDateOfCreation() const;

    /*!
     * \return Date of modification
     */
    QDateTime getDateOfModification() const;

    /*!
     * \brief isFile
     * \return Is file file
     */
    bool isFile() const;

    /*!
     * \brief isSymLink
     * \return Is file symlink
     */
    bool isSymLink() const;

    /*!
     * \brief getSymlinkPath
     * \return Path reffered by symlink
     */
    QString getSymlinkPath() const;

    /*!
     * \brief isDir
     * \return Is file directory
     */
    bool isDir() const;
};

#endif // FILEINFO_HPP
