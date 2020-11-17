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
#include "windowtree.hpp"
#include "windowmetadatasearch.hpp"

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

    void on_button_startEditMetadata_clicked();

    void on_button_SearchMetadata_clicked();

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
     * \brief Calls OpenFileDialog and takes file path.
     * \return Path if selected, else NULL.
     */
    QString CallOpenFileDialog();

    /*!
     * \brief Calls OpenFileDialog and takes file path.
     * \return Path if selected, else NULL.
     */
    QString CallDirDialog();

};
#endif // MAINWINDOW_HPP
