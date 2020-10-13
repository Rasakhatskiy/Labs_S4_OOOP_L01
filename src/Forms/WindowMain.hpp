/*! File with interaction functions for main menu.
* \file WindowMain.hpp
* \author Maksym Rasakhatskyi
*/

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

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

private:
    /*! Pointer to user interface of the form.*/
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_HPP
