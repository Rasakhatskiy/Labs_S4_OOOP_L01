#include "windowmetadatasearch.hpp"
#include "ui_windowmetadatasearch.h"

WindowMetadataSearch::WindowMetadataSearch(
        const QString& path,
        const bool &isAND,
        QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowMetadataSearch),
    path(path),
    isAND(isAND)
{
    ui->setupUi(this);
}

WindowMetadataSearch::~WindowMetadataSearch()
{
    delete ui;
}

void WindowMetadataSearch::on_button_search_clicked()
{
    Metadata toSearch(
        ui->dateTimeEdit_creation->dateTime(),
        ui->dateTimeEdit_modification->dateTime(),
        (uint64_t)ui->spinBox_length->value(),
        ui->lineEdit_owner->text(),
        ui->lineEdit_extension->text());

    auto result = toSearch.doSearch(path, isAND);
}

QStringList WindowMetadataSearch::search(QString scanDirPath)
{

}
