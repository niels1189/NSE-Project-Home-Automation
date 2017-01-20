/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label_status_login;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *txtUser;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *txtPass;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(443, 295);
        label_status_login = new QLabel(Dialog);
        label_status_login->setObjectName(QString::fromUtf8("label_status_login"));
        label_status_login->setGeometry(QRect(20, 190, 391, 91));
        label_status_login->setFrameShape(QFrame::Box);
        label_status_login->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 130, 93, 28));
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 49, 266, 57));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        txtUser = new QLineEdit(layoutWidget);
        txtUser->setObjectName(QString::fromUtf8("txtUser"));

        horizontalLayout_2->addWidget(txtUser);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        txtPass = new QLineEdit(layoutWidget);
        txtPass->setObjectName(QString::fromUtf8("txtPass"));
        txtPass->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(txtPass);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Dialog);
        QObject::connect(txtUser, SIGNAL(cursorPositionChanged(int,int)), label_status_login, SLOT(hide()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_status_login->setText(QApplication::translate("Dialog", "[+]Status", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Dialog", "Login", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Username", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Password", 0, QApplication::UnicodeUTF8));
        txtPass->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
