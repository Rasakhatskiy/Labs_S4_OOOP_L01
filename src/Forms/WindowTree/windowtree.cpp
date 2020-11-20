#include "windowtree.hpp"
#include "ui_windowtree.h"

WindowTree::WindowTree(const QStringList& data, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowTree)
{
    ui->setupUi(this);
    setupTree(data);
}

WindowTree::~WindowTree()
{
    delete ui;
}

void WindowTree::on_button_ok_clicked()
{
    close();
}

void WindowTree::setupTree(const QStringList &data)
{
    QVector<QVariant> vector;
    auto treeModel = new TreeModel(data, this);
    ui->treeView->setModel(treeModel);
    ui->treeView->header()->resizeSection(0, 600);
    ui->treeView->expandAll();
}
