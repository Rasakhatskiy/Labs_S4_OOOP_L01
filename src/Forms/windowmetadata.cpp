#include "windowmetadata.hpp"
#include "ui_windowmetadata.h"

WindowMetadata::WindowMetadata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowMetadata)
{
    ui->setupUi(this);
}

WindowMetadata::~WindowMetadata()
{
    delete ui;
}

void WindowMetadata::on_pushButton_cancel_clicked()
{
    close();
}
