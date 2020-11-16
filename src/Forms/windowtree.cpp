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

{
    auto fileInfoScan = QFileInfo(scanDirPath);
    if (!fileInfoScan.exists() ||
        !fileInfoScan.isDir())
        throw std::invalid_argument("Unable to open file " + scanDirPath.toStdString());

   auto dirInfo = QDir(scanDirPath);
   auto allFiles = dirInfo.entryList(
       QDir::NoDotAndDotDot |
       QDir::System |
       QDir::Hidden  |
       QDir::AllDirs |
       QDir::Files,
       QDir::DirsFirst);

    for (auto &file : allFiles)
    {
        auto fileInfoTemp = QFileInfo(scanDirPath + "/" + file);
        auto fullpath = fileInfoTemp.absoluteFilePath();
        if (fileInfoTemp.isDir())
            scan(fullpath);
        else
            this->files.append(fullpath);
    }
}
