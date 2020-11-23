#ifndef METADATA_HPP
#define METADATA_HPP

#include <QString>
#include <QPair>
#include <QDateTime>
#include <QFileInfo>
#include <QStringList>
#include <QDir>
#include <QDebug>

#include <stdexcept>

#include <windows.h>
#include <WinBase.h>
#include <tchar.h>
#include <strsafe.h>
#include <fileapi.h>
#include <timezoneapi.h>
#include <SDKDDKVer.h>
#include <AccCtrl.h>
#include <AclAPI.h>
#include "accctrl.h"
#include "aclapi.h"
#include "fileinfo.hpp"
#include <sddl.h>
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib,"user32.lib")


class Metadata
{
private:
    /*!
     * \brief Opens file for read
     * \param[in] path of the file
     * \return HANDLE of file
     */
    HANDLE openFileRead(const QString& path);

    /*!
     * \brief Opens file for write
     * \param[in] path of the file
     * \return HANDLE of file
     */
    HANDLE openFileWrite(const QString& path);

    /*!
     * \brief Gets pair of date of creation and modification
     * \param hFile[in] HANDLE for file reading
     * \return Pair of <Date of creation, Date of modification>
     */
    QPair<QDateTime, QDateTime> getTime(HANDLE hFile);

    /*!
     * \brief Sets file time of creation and modification to given.
     * Sets date of last access as current time.
     * \param hFile[out] Handle for write.
     * \param pair Pair of <Date of creation, Date of modification>.
     * \return true if write was successful.
     */
    bool setTime(
        HANDLE hFile,
        QPair<QDateTime,
        QDateTime> pair);

    /*!
     * \brief gets name of owner from the file.
     * \param hFile[in] HANDLE of file for read.
     * \return name of owner or owner group
     */
    QString getOwner(HANDLE hFile);

    /*!
     * \brief changes owner of te file.
     * \param hFile[out] HANDLE of file for write.
     * \param ownerName[in] new owner name.
     * \return true if write was successful.
     */
    bool setOwner(
        HANDLE hFile,
        const QString& ownerName);


    bool matchesCriterion(
        const QString& path,
        const bool& isAND);

public:

    /*! Date and time of creation.*/
    QDateTime dateTimeCreation;

    /*! Date and time of modification.*/
    QDateTime dateTimeModification;

    /*! Length of file in bytes.*/
    uint64_t length;

    /*! Name of owner.*/
    QString owner;

    /*! File extension.*/
    QString extension;

    /*!
     * \brief saves the metadata values to file.
     * \param path[in] Path of desired file.
     * \return true if write was success.
     */
    bool save(const QString& path);


    /*!
     * \brief Metadata constructor reads metadata from file.
     * \param path[in] path of the file to read.
     */
    Metadata(const QString& path);

    /*!
     * \brief Metadata constructor.
     * \param dateTimeCreation[in] Date and time of creation.
     * \param dateTimeModification[in] Date and time of modification.
     * \param length[in] Length of file in bytes.
     * \param owner[in] Name of owner.
     * \param extension[in] File extension.
     */\
    Metadata(
        const QDateTime& dateTimeCreation,
        const QDateTime& dateTimeModification,
        const uint64_t& length,
        const QString& owner,
        const QString& extension);

    /*!
     * \brief static function to convert from QDateTime to SYSTEMTIME from win32 API.
     * \param dateTime[in] datetime to convert.
     * \return SYSTEMTIME datetime.
     */
    static SYSTEMTIME dateTimeFromQDateTime(const QDateTime& dateTime);

    /*!
     * \brief static function to search by this metadata.
     * \param startSearchPath[in] Directory path to start searching.
     * \param name[in] Name of the file to search, can be NULL - metadata search only.
     * \param isAND[in] if true all metadata options should match, else at least one.
     * \return list of found files paths.
     */
    QList<FileInfo> doSearch(
        const QString& startSearchPath,
        const bool& isAND);

};

#endif // METADATA_HPP
