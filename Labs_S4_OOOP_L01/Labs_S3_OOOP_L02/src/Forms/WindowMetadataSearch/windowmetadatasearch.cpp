#include "windowmetadatasearch.hpp"
#include "ui_windowmetadatasearch.h"

WindowMetadataSearch::WindowMetadataSearch(
        const QString& path,
        QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowMetadataSearch),
    path(path)
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

    auto result = toSearch.doSearch(path, ui->radioButton_AND->isChecked());

    auto window = new WindowTree(result, this);
    window->show();
}

void WindowMetadataSearch::on_pushButton_cancel_clicked()
{
    close();
}
