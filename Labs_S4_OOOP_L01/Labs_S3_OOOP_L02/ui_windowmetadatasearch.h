/********************************************************************************
** Form generated from reading UI file 'windowmetadatasearch.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWMETADATASEARCH_H
#define UI_WINDOWMETADATASEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_WindowMetadataSearch
{
public:
    QFormLayout *formLayout;
    QLabel *label_dateCreation;
    QDateTimeEdit *dateTimeEdit_creation;
    QLabel *label_dateModification;
    QDateTimeEdit *dateTimeEdit_modification;
    QLabel *label_owner;
    QLineEdit *lineEdit_owner;
    QLabel *label_length;
    QSpinBox *spinBox_length;
    QLabel *label_extension;
    QLineEdit *lineEdit_extension;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_search;
    QPushButton *pushButton_cancel;
    QRadioButton *radioButton_AND;
    QRadioButton *radioButton_OR;

    void setupUi(QDialog *WindowMetadataSearch)
    {
        if (WindowMetadataSearch->objectName().isEmpty())
            WindowMetadataSearch->setObjectName(QString::fromUtf8("WindowMetadataSearch"));
        WindowMetadataSearch->resize(538, 264);
        formLayout = new QFormLayout(WindowMetadataSearch);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_dateCreation = new QLabel(WindowMetadataSearch);
        label_dateCreation->setObjectName(QString::fromUtf8("label_dateCreation"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_dateCreation->sizePolicy().hasHeightForWidth());
        label_dateCreation->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_dateCreation);

        dateTimeEdit_creation = new QDateTimeEdit(WindowMetadataSearch);
        dateTimeEdit_creation->setObjectName(QString::fromUtf8("dateTimeEdit_creation"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dateTimeEdit_creation->sizePolicy().hasHeightForWidth());
        dateTimeEdit_creation->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::FieldRole, dateTimeEdit_creation);

        label_dateModification = new QLabel(WindowMetadataSearch);
        label_dateModification->setObjectName(QString::fromUtf8("label_dateModification"));
        sizePolicy.setHeightForWidth(label_dateModification->sizePolicy().hasHeightForWidth());
        label_dateModification->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_dateModification);

        dateTimeEdit_modification = new QDateTimeEdit(WindowMetadataSearch);
        dateTimeEdit_modification->setObjectName(QString::fromUtf8("dateTimeEdit_modification"));
        sizePolicy1.setHeightForWidth(dateTimeEdit_modification->sizePolicy().hasHeightForWidth());
        dateTimeEdit_modification->setSizePolicy(sizePolicy1);

        formLayout->setWidget(1, QFormLayout::FieldRole, dateTimeEdit_modification);

        label_owner = new QLabel(WindowMetadataSearch);
        label_owner->setObjectName(QString::fromUtf8("label_owner"));
        sizePolicy.setHeightForWidth(label_owner->sizePolicy().hasHeightForWidth());
        label_owner->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_owner);

        lineEdit_owner = new QLineEdit(WindowMetadataSearch);
        lineEdit_owner->setObjectName(QString::fromUtf8("lineEdit_owner"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_owner->sizePolicy().hasHeightForWidth());
        lineEdit_owner->setSizePolicy(sizePolicy2);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_owner);

        label_length = new QLabel(WindowMetadataSearch);
        label_length->setObjectName(QString::fromUtf8("label_length"));
        sizePolicy.setHeightForWidth(label_length->sizePolicy().hasHeightForWidth());
        label_length->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_length);

        spinBox_length = new QSpinBox(WindowMetadataSearch);
        spinBox_length->setObjectName(QString::fromUtf8("spinBox_length"));
        spinBox_length->setEnabled(true);
        sizePolicy1.setHeightForWidth(spinBox_length->sizePolicy().hasHeightForWidth());
        spinBox_length->setSizePolicy(sizePolicy1);
        spinBox_length->setMaximum(999999999);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBox_length);

        label_extension = new QLabel(WindowMetadataSearch);
        label_extension->setObjectName(QString::fromUtf8("label_extension"));
        sizePolicy.setHeightForWidth(label_extension->sizePolicy().hasHeightForWidth());
        label_extension->setSizePolicy(sizePolicy);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_extension);

        lineEdit_extension = new QLineEdit(WindowMetadataSearch);
        lineEdit_extension->setObjectName(QString::fromUtf8("lineEdit_extension"));
        sizePolicy2.setHeightForWidth(lineEdit_extension->sizePolicy().hasHeightForWidth());
        lineEdit_extension->setSizePolicy(sizePolicy2);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_extension);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        button_search = new QPushButton(WindowMetadataSearch);
        button_search->setObjectName(QString::fromUtf8("button_search"));
        sizePolicy1.setHeightForWidth(button_search->sizePolicy().hasHeightForWidth());
        button_search->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(button_search);

        pushButton_cancel = new QPushButton(WindowMetadataSearch);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        sizePolicy1.setHeightForWidth(pushButton_cancel->sizePolicy().hasHeightForWidth());
        pushButton_cancel->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_cancel);


        formLayout->setLayout(12, QFormLayout::FieldRole, horizontalLayout);

        radioButton_AND = new QRadioButton(WindowMetadataSearch);
        radioButton_AND->setObjectName(QString::fromUtf8("radioButton_AND"));
        sizePolicy1.setHeightForWidth(radioButton_AND->sizePolicy().hasHeightForWidth());
        radioButton_AND->setSizePolicy(sizePolicy1);
        radioButton_AND->setChecked(false);

        formLayout->setWidget(6, QFormLayout::FieldRole, radioButton_AND);

        radioButton_OR = new QRadioButton(WindowMetadataSearch);
        radioButton_OR->setObjectName(QString::fromUtf8("radioButton_OR"));
        sizePolicy1.setHeightForWidth(radioButton_OR->sizePolicy().hasHeightForWidth());
        radioButton_OR->setSizePolicy(sizePolicy1);
        radioButton_OR->setChecked(true);

        formLayout->setWidget(7, QFormLayout::FieldRole, radioButton_OR);


        retranslateUi(WindowMetadataSearch);

        QMetaObject::connectSlotsByName(WindowMetadataSearch);
    } // setupUi

    void retranslateUi(QDialog *WindowMetadataSearch)
    {
        WindowMetadataSearch->setWindowTitle(QCoreApplication::translate("WindowMetadataSearch", "Dialog", nullptr));
        label_dateCreation->setText(QCoreApplication::translate("WindowMetadataSearch", "Date of creation:", nullptr));
        dateTimeEdit_creation->setDisplayFormat(QCoreApplication::translate("WindowMetadataSearch", "dd-MM-yyyy HH:mm", nullptr));
        label_dateModification->setText(QCoreApplication::translate("WindowMetadataSearch", "Date of modification:", nullptr));
        dateTimeEdit_modification->setDisplayFormat(QCoreApplication::translate("WindowMetadataSearch", "dd-MM-yyyy HH:mm", nullptr));
        label_owner->setText(QCoreApplication::translate("WindowMetadataSearch", "Owner:", nullptr));
        label_length->setText(QCoreApplication::translate("WindowMetadataSearch", "File size:", nullptr));
        label_extension->setText(QCoreApplication::translate("WindowMetadataSearch", "Extension", nullptr));
        button_search->setText(QCoreApplication::translate("WindowMetadataSearch", "Search", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("WindowMetadataSearch", "Cancel", nullptr));
        radioButton_AND->setText(QCoreApplication::translate("WindowMetadataSearch", "All match", nullptr));
        radioButton_OR->setText(QCoreApplication::translate("WindowMetadataSearch", "At least one matches", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowMetadataSearch: public Ui_WindowMetadataSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWMETADATASEARCH_H
