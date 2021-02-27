/********************************************************************************
** Form generated from reading UI file 'WindowMain.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWMAIN_H
#define UI_WINDOWMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *button_refreshDrives;
    QComboBox *comboBox_selectDrive;
    QLabel *label_selectDrive;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_open;
    QPushButton *button_browseSaveAs;
    QPushButton *button_openExplorer;
    QProgressBar *progressBar;
    QPushButton *button_startEditMetadata;
    QPushButton *button_SearchMetadata;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(608, 126);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/Forms/ico.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        button_refreshDrives = new QPushButton(centralwidget);
        button_refreshDrives->setObjectName(QString::fromUtf8("button_refreshDrives"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(button_refreshDrives->sizePolicy().hasHeightForWidth());
        button_refreshDrives->setSizePolicy(sizePolicy);

        gridLayout->addWidget(button_refreshDrives, 0, 2, 1, 1);

        comboBox_selectDrive = new QComboBox(centralwidget);
        comboBox_selectDrive->setObjectName(QString::fromUtf8("comboBox_selectDrive"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_selectDrive->sizePolicy().hasHeightForWidth());
        comboBox_selectDrive->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox_selectDrive, 0, 1, 1, 1);

        label_selectDrive = new QLabel(centralwidget);
        label_selectDrive->setObjectName(QString::fromUtf8("label_selectDrive"));
        sizePolicy1.setHeightForWidth(label_selectDrive->sizePolicy().hasHeightForWidth());
        label_selectDrive->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_selectDrive, 0, 0, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 5, 0, 1, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        button_open = new QPushButton(centralwidget);
        button_open->setObjectName(QString::fromUtf8("button_open"));
        sizePolicy.setHeightForWidth(button_open->sizePolicy().hasHeightForWidth());
        button_open->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(button_open);

        button_browseSaveAs = new QPushButton(centralwidget);
        button_browseSaveAs->setObjectName(QString::fromUtf8("button_browseSaveAs"));
        sizePolicy.setHeightForWidth(button_browseSaveAs->sizePolicy().hasHeightForWidth());
        button_browseSaveAs->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(button_browseSaveAs);

        button_openExplorer = new QPushButton(centralwidget);
        button_openExplorer->setObjectName(QString::fromUtf8("button_openExplorer"));
        sizePolicy.setHeightForWidth(button_openExplorer->sizePolicy().hasHeightForWidth());
        button_openExplorer->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(button_openExplorer);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 2);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy2);
        progressBar->setMaximum(100);
        progressBar->setValue(47);
        progressBar->setInvertedAppearance(false);

        gridLayout->addWidget(progressBar, 4, 1, 1, 2);

        button_startEditMetadata = new QPushButton(centralwidget);
        button_startEditMetadata->setObjectName(QString::fromUtf8("button_startEditMetadata"));
        sizePolicy.setHeightForWidth(button_startEditMetadata->sizePolicy().hasHeightForWidth());
        button_startEditMetadata->setSizePolicy(sizePolicy);

        gridLayout->addWidget(button_startEditMetadata, 7, 2, 1, 1);

        button_SearchMetadata = new QPushButton(centralwidget);
        button_SearchMetadata->setObjectName(QString::fromUtf8("button_SearchMetadata"));

        gridLayout->addWidget(button_SearchMetadata, 7, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Offline file ManaGer (OMG)", nullptr));
        button_refreshDrives->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        label_selectDrive->setText(QCoreApplication::translate("MainWindow", "Select Drive: ", nullptr));
        button_open->setText(QCoreApplication::translate("MainWindow", "Open created filesystem", nullptr));
        button_browseSaveAs->setText(QCoreApplication::translate("MainWindow", "Save as", nullptr));
        button_openExplorer->setText(QCoreApplication::translate("MainWindow", "Open drive in explorer", nullptr));
        button_startEditMetadata->setText(QCoreApplication::translate("MainWindow", "Edit metadata", nullptr));
        button_SearchMetadata->setText(QCoreApplication::translate("MainWindow", "Search by metadata", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWMAIN_H
