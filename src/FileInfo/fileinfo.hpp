#ifndef FILEINFO_HPP
#define FILEINFO_HPP

#include <QFileInfo>
#include <QDateTime>
#include <QDataStream>
#include <QString>

/*!

 */

/*!
 * \brief Class made for saving info on disk
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

    /*! File length.*/
    uint64_t _length;

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
    void construct(const QFileInfo& fileInfo);

public:
    /*!
     * \brief default constructor
     */
    FileInfo() = default;

    /*!
     * \brief Copy constructor
     * \param[in] Copy from
     */
//    FileInfo(const FileInfo& fileInfo);

    /*!
     * \brief Constructs file info from file system entry.
     * \param fullpath Full path of the file.
     */
    FileInfo(const QString& fullpath);

    /*!
     * \brief Copies parameters from QFileInfo to FileInfo
     * \param fileInfo
     */
    FileInfo(const QFileInfo& fileInfo);

    /*!
     * \brief Constructor by fields
     * \param[in] fullpath
     * \param[in] dateOfCreation
     * \param[in] dateOfModification
     * \param[in] lenght
     * \param[in] isFile
     * \param[in] isSymLink
     * \param[in] symlinkPath
     * \param[in] isDir
     */
    FileInfo(
        const QString& fullpath,
        const QDateTime& dateOfCreation,
        const QDateTime& dateOfModification,
        const uint64_t& length,
        const bool& isFile,
        const bool& isSymLink,
        const QString& symlinkPath,
        const bool& isDir);

    /*!
     * \brief Returns full path of file.
     * \return Full path of file.
     */
    QString getFullpath() const;

    /*!
     * \brief Returns date of creation.
     * \return Date of creation
     */
    QDateTime getDateOfCreation() const;

    /*!
     * \brief Returns date of modification.
     * \return Date of modification
     */
    QDateTime getDateOfModification() const;

    /*!
     * \brief is file
     * \return Is file file
     */
    bool isFile() const;

    /*!
     * \brief is symLink
     * \return Is file symlink
     */
    bool isSymLink() const;

    /*!
     * \brief Returns symlink path.
     * \return Path reffered by symlink.
     */
    QString getSymlinkPath() const;

    /*!
     * \brief is dir.
     * \return Is file directory.
     */
    bool isDir() const;

    /*!
     * \brief returns file length.
     * \return file length in bytes.
     */
    uint64_t getLength() const;

};

/*! Serialization operator.*/
QDataStream &operator<<(QDataStream &, const FileInfo &);

/*! Serialization operator.*/
QDataStream &operator>>(QDataStream &, FileInfo &);

#endif // FILEINFO_HPP
