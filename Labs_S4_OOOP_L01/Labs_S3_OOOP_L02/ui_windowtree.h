/********************************************************************************
** Form generated from reading UI file 'windowtree.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWTREE_H
#define UI_WINDOWTREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WindowTree
{
public:
    QVBoxLayout *verticalLayout;
    QTreeView *treeView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_ok;

    void setupUi(QDialog *WindowTree)
    {
        if (WindowTree->objectName().isEmpty())
            WindowTree->setObjectName(QString::fromUtf8("WindowTree"));
        WindowTree->resize(1295, 674);
        verticalLayout = new QVBoxLayout(WindowTree);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeView = new QTreeView(WindowTree);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        verticalLayout->addWidget(treeView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        button_ok = new QPushButton(WindowTree);
        button_ok->setObjectName(QString::fromUtf8("button_ok"));

        horizontalLayout->addWidget(button_ok);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(WindowTree);

        QMetaObject::connectSlotsByName(WindowTree);
    } // setupUi

    void retranslateUi(QDialog *WindowTree)
    {
        WindowTree->setWindowTitle(QCoreApplication::translate("WindowTree", "Dialog", nullptr));
        button_ok->setText(QCoreApplication::translate("WindowTree", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowTree: public Ui_WindowTree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWTREE_H
