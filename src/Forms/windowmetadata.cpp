#include "windowmetadata.hpp"
#include "ui_windowmetadata.h"

WindowMetadata::WindowMetadata(const QString& path, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowMetadata)
{
    ui->setupUi(this);

    try
    {
        this->path = path;
        Metadata metadata(path);
        setMetaData(metadata);
    }
    catch(...)
    {
        QMessageBox::warning(
            this,
            "Invalid input",
            "Cannot read file metadata");
    }
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

void WindowMetadata::on_button_save_clicked()
{
    Metadata toSave(
        ui->dateTimeEdit_creation->dateTime(),
        ui->dateTimeEdit_modification->dateTime(),
        (uint64_t)ui->spinBox_length->value(),
        ui->lineEdit_owner->text(),
        ui->lineEdit_extension->text());

    if (toSave.save(path))
    {
        QMessageBox::information(
            this,
            "Saved",
            "Metadata written");
    }
}
