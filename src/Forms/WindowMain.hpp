/*! File with interaction functions for main menu.
* \file WindowMain.hpp
* \author Maksym Rasakhatskyi
*/

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QMessageBox>
#include <QFileInfo>
#include <QStorageInfo>
#include <QFileDialog>
#include <QProcess>
#include "../InfoSaver/infosaver.hpp"

QT_BEGIN_NAMESPACE
/*! UI namespace*/
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*! Main window class.*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*! Main window constructor.*/
    MainWindow(QWidget *parent = nullptr);

    /*! Main window destructor.*/
    ~MainWindow();

private slots:
    void on_button_refreshDrives_clicked();

    void on_button_openExplorer_clicked();

    void on_button_browseSaveAs_clicked();

    void on_button_browseModifyFile_clicked();

    void on_button_startCreateFilesystem_clicked();

private:
    /*! Pointer to user interface of the form.*/
    Ui::MainWindow *ui;

    /*! List of drives. */
    QList<QStorageInfo> _listStorageInfo;

    /*!
     * \brief Checks if selected source drive name is valid.
     * \return Source path if drive is valid, else null.
     */
    QString isSourceValid();

    /*!
     * \brief Checks if result file already exists and asks user if he sure to rewrite.
     * \return Result name if user agreed or file does not exist. Null if file axists and user not agreed.
     */
    QString isResultNameValid();
};
#endif // MAINWINDOW_HPP
