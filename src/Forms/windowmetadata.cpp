#include "windowmetadata.hpp"
#include "ui_windowmetadata.h"

WindowMetadata::WindowMetadata(const QString& path, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowMetadata)
{
    ui->setupUi(this);
    Metadata metadata(path);
    setMetaData(metadata);
}

WindowMetadata::~WindowMetadata()
{
    delete ui;
}

void WindowMetadata::on_pushButton_cancel_clicked()
{
    close();
}

void WindowMetadata::setMetaData(const Metadata &metadata)
{
    QDateTime dateTimeCreation(
        QDate(
            metadata.dateTimeCreation.year,
            metadata.dateTimeCreation.month,
            metadata.dateTimeCreation.day),
        QTime(
            metadata.dateTimeCreation.hour,
            metadata.dateTimeCreation.minute,
            metadata.dateTimeCreation.second));
    ui->dateTimeEdit_creation->setDateTime(dateTimeCreation);

    QDateTime dateTimeModification(
        QDate(
            metadata.dateTimeModification.year,
            metadata.dateTimeModification.month,
            metadata.dateTimeModification.day),
        QTime(
            metadata.dateTimeModification.hour,
            metadata.dateTimeModification.minute,
            metadata.dateTimeModification.second));
    ui->dateTimeEdit_modification->setDateTime(dateTimeModification);
}
