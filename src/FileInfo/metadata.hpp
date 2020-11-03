#ifndef METADATA_HPP
#define METADATA_HPP

#include <QString>
#include "DateTime.hpp"

class Metadata
{
public:
    DateTime dateTimeCreation;
    DateTime dateTimeModification;
    uint64_t length;
    QString owner;
    QString extension;


    Metadata(QString path);
};

#endif // METADATA_HPP
