/********************************************************************************
** Form generated from reading UI file 'windowmetadata.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWMETADATA_H
#define UI_WINDOWMETADATA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_WindowMetadata
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
    QPushButton *button_save;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *WindowMetadata)
    {
        if (WindowMetadata->objectName().isEmpty())
            WindowMetadata->setObjectName(QString::fromUtf8("WindowMetadata"));
        WindowMetadata->resize(413, 184);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/Forms/ico.ico"), QSize(), QIcon::Normal, QIcon::Off);
        WindowMetadata->setWindowIcon(icon);
        formLayout = new QFormLayout(WindowMetadata);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_dateCreation = new QLabel(WindowMetadata);
        label_dateCreation->setObjectName(QString::fromUtf8("label_dateCreation"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_dateCreation->sizePolicy().hasHeightForWidth());
        label_dateCreation->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_dateCreation);

        dateTimeEdit_creation = new QDateTimeEdit(WindowMetadata);
        dateTimeEdit_creation->setObjectName(QString::fromUtf8("dateTimeEdit_creation"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dateTimeEdit_creation->sizePolicy().hasHeightForWidth());
        dateTimeEdit_creation->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::FieldRole, dateTimeEdit_creation);

        label_dateModification = new QLabel(WindowMetadata);
        label_dateModification->setObjectName(QString::fromUtf8("label_dateModification"));
        sizePolicy.setHeightForWidth(label_dateModification->sizePolicy().hasHeightForWidth());
        label_dateModification->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_dateModification);

        dateTimeEdit_modification = new QDateTimeEdit(WindowMetadata);
        dateTimeEdit_modification->setObjectName(QString::fromUtf8("dateTimeEdit_modification"));
        sizePolicy1.setHeightForWidth(dateTimeEdit_modification->sizePolicy().hasHeightForWidth());
        dateTimeEdit_modification->setSizePolicy(sizePolicy1);

        formLayout->setWidget(1, QFormLayout::FieldRole, dateTimeEdit_modification);

        label_owner = new QLabel(WindowMetadata);
        label_owner->setObjectName(QString::fromUtf8("label_owner"));
        sizePolicy.setHeightForWidth(label_owner->sizePolicy().hasHeightForWidth());
        label_owner->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_owner);

        lineEdit_owner = new QLineEdit(WindowMetadata);
        lineEdit_owner->setObjectName(QString::fromUtf8("lineEdit_owner"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_owner->sizePolicy().hasHeightForWidth());
        lineEdit_owner->setSizePolicy(sizePolicy2);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_owner);

        label_length = new QLabel(WindowMetadata);
        label_length->setObjectName(QString::fromUtf8("label_length"));
        sizePolicy.setHeightForWidth(label_length->sizePolicy().hasHeightForWidth());
        label_length->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_length);

        spinBox_length = new QSpinBox(WindowMetadata);
        spinBox_length->setObjectName(QString::fromUtf8("spinBox_length"));
        spinBox_length->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_length->sizePolicy().hasHeightForWidth());
        spinBox_length->setSizePolicy(sizePolicy1);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBox_length);

        label_extension = new QLabel(WindowMetadata);
        label_extension->setObjectName(QString::fromUtf8("label_extension"));
        sizePolicy.setHeightForWidth(label_extension->sizePolicy().hasHeightForWidth());
        label_extension->setSizePolicy(sizePolicy);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_extension);

        lineEdit_extension = new QLineEdit(WindowMetadata);
        lineEdit_extension->setObjectName(QString::fromUtf8("lineEdit_extension"));
        sizePolicy2.setHeightForWidth(lineEdit_extension->sizePolicy().hasHeightForWidth());
        lineEdit_extension->setSizePolicy(sizePolicy2);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_extension);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        button_save = new QPushButton(WindowMetadata);
        button_save->setObjectName(QString::fromUtf8("button_save"));
        sizePolicy1.setHeightForWidth(button_save->sizePolicy().hasHeightForWidth());
        button_save->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(button_save);

        pushButton_cancel = new QPushButton(WindowMetadata);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        sizePolicy1.setHeightForWidth(pushButton_cancel->sizePolicy().hasHeightForWidth());
        pushButton_cancel->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_cancel);


        formLayout->setLayout(5, QFormLayout::FieldRole, horizontalLayout);


        retranslateUi(WindowMetadata);

        QMetaObject::connectSlotsByName(WindowMetadata);
    } // setupUi

    void retranslateUi(QDialog *WindowMetadata)
    {
        WindowMetadata->setWindowTitle(QCoreApplication::translate("WindowMetadata", "Edit Metadata", nullptr));
        label_dateCreation->setText(QCoreApplication::translate("WindowMetadata", "Date of creation:", nullptr));
        dateTimeEdit_creation->setDisplayFormat(QCoreApplication::translate("WindowMetadata", "dd-MM-yyyy HH:mm:ss", nullptr));
        label_dateModification->setText(QCoreApplication::translate("WindowMetadata", "Date of modification:", nullptr));
        dateTimeEdit_modification->setDisplayFormat(QCoreApplication::translate("WindowMetadata", "dd-MM-yyyy HH:mm:ss", nullptr));
        label_owner->setText(QCoreApplication::translate("WindowMetadata", "Owner:", nullptr));
        label_length->setText(QCoreApplication::translate("WindowMetadata", "File size:", nullptr));
        label_extension->setText(QCoreApplication::translate("WindowMetadata", "Extension", nullptr));
        button_save->setText(QCoreApplication::translate("WindowMetadata", "Save", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("WindowMetadata", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowMetadata: public Ui_WindowMetadata {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWMETADATA_H
