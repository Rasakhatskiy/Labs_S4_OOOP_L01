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
    ui->dateTimeEdit_creation->setDateTime(metadata.dateTimeCreation);
    ui->dateTimeEdit_modification->setDateTime(metadata.dateTimeModification);
    ui->lineEdit_owner->setText(metadata.owner);
    ui->spinBox_length->setValue(metadata.length);
    ui->lineEdit_extension->setText(metadata.extension);
}
