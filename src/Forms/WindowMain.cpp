#include "WindowMain.hpp"
#include "ui_WindowMain.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_button_refreshDrives_clicked();
    ui->progressBar->setHidden(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button_refreshDrives_clicked()
{
    ui->comboBox_selectDrive->clear();
    _listStorageInfo.clear();
    for (auto &storage : QStorageInfo::mountedVolumes())
    {
        if (storage.isValid() &&
            storage.isReady() &&
            !storage.isReadOnly())
        {
            _listStorageInfo.append(storage);
            ui->comboBox_selectDrive->addItem(
                storage.rootPath() +
                " " +
                QString::number(storage.bytesTotal() / 1024 / 1024 / 1024) +
                " GB");
        }
    }
}

void MainWindow::on_button_openExplorer_clicked()
{
    auto index = ui->comboBox_selectDrive->currentIndex();
    if (index >= 0 &&
        index < _listStorageInfo.size())
    {
        QProcess myProcess(this);
        QString exe = "explorer";

        QStringList arguments;
        auto path = _listStorageInfo[index].rootPath();
        path[path.size() - 1] = '\\';
        arguments << path;

        myProcess.start(exe, arguments);
        myProcess.waitForFinished(-1);
    }
}

void MainWindow::on_button_browseSaveAs_clicked()
{
    QFileDialog dialog_saveAs(this);
    dialog_saveAs.setFileMode(QFileDialog::AnyFile);
    dialog_saveAs.setDirectory("D:\\");
    dialog_saveAs.setWindowTitle("Save as");
    dialog_saveAs.setNameFilter(tr("Binary file (*.bin *.data *.img)"));
    dialog_saveAs.setViewMode(QFileDialog::Detail);
    if (dialog_saveAs.exec())
        ui->lineEdit_pathSaveFileInfo->setText(dialog_saveAs.selectedFiles()[0]);
}

void MainWindow::on_button_browseModifyFile_clicked()
{
    QFileDialog dialog_saveAs(this);
    dialog_saveAs.setFileMode(QFileDialog::ExistingFile);
    dialog_saveAs.setDirectory("D:\\");
    dialog_saveAs.setWindowTitle("Save as");
    dialog_saveAs.setNameFilter(tr("Binary file (*.bin *.data *.img)"));
    dialog_saveAs.setViewMode(QFileDialog::Detail);
    if (dialog_saveAs.exec())
        ui->lineEdit_pathModifyMetadata->setText(dialog_saveAs.selectedFiles()[0]);
}

void MainWindow::on_button_startCreateFilesystem_clicked()
{
    auto sourcePath = isSourceValid();
    auto resultPath = isResultNameValid();

    if (sourcePath == NULL ||
        resultPath == NULL)
        return;

    auto infoSaver = InfoSaver();
    infoSaver.scan(sourcePath);
    infoSaver.save(resultPath);
}

QString MainWindow::isSourceValid()
{
    // Check if something if index valid. It must be valid
    auto index = ui->comboBox_selectDrive->currentIndex();
    if (index < 0 ||
        index >= _listStorageInfo.size())
        throw std::invalid_argument("Index " + std::to_string(index) + " does not exists");

    // Check if this drive exists.
    auto sourcePath = _listStorageInfo[index].rootPath();
    sourcePath[sourcePath.size() - 1] = '\\';
    if (!QFileInfo(sourcePath).exists())
    {
        QMessageBox::warning(
            this,
            "Invalid input",
            "Directory " + sourcePath + " does not exists");
        return NULL;
    }

    return sourcePath;
}

QString MainWindow::isResultNameValid()
{
    auto resultName = ui->lineEdit_pathSaveFileInfo->text();
    if (QFileInfo(resultName).exists())
    {
        auto result = QMessageBox::warning(
            this,
            "Invalid input",
            "File " + resultName + " already exists. Overwrite it?",
            QMessageBox::Yes|QMessageBox::No);

        if (result == QMessageBox::Yes)
        {
            // delete file
            QFile::remove(resultName);
        }
        else
        {
            return NULL;
        }
    }
    return resultName;
}
