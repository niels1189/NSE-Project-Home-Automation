/********************************************************************************
** Form generated from reading UI file 'screenafterlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENAFTERLOGIN_H
#define UI_SCREENAFTERLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ScreenAfterLogin
{
public:
    QLabel *date;
    QPushButton *LogSeizure;
    QPushButton *setTemp;
    QPushButton *pushButton;

    void setupUi(QDialog *ScreenAfterLogin)
    {
        if (ScreenAfterLogin->objectName().isEmpty())
            ScreenAfterLogin->setObjectName(QStringLiteral("ScreenAfterLogin"));
        ScreenAfterLogin->resize(400, 300);
        date = new QLabel(ScreenAfterLogin);
        date->setObjectName(QStringLiteral("date"));
        date->setGeometry(QRect(60, 10, 321, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        date->setFont(font);
        LogSeizure = new QPushButton(ScreenAfterLogin);
        LogSeizure->setObjectName(QStringLiteral("LogSeizure"));
        LogSeizure->setGeometry(QRect(230, 240, 141, 28));
        setTemp = new QPushButton(ScreenAfterLogin);
        setTemp->setObjectName(QStringLiteral("setTemp"));
        setTemp->setGeometry(QRect(40, 110, 91, 41));
        pushButton = new QPushButton(ScreenAfterLogin);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 110, 91, 41));

        retranslateUi(ScreenAfterLogin);

        QMetaObject::connectSlotsByName(ScreenAfterLogin);
    } // setupUi

    void retranslateUi(QDialog *ScreenAfterLogin)
    {
        ScreenAfterLogin->setWindowTitle(QApplication::translate("ScreenAfterLogin", "Dialog", 0));
        date->setText(QApplication::translate("ScreenAfterLogin", "Date", 0));
        LogSeizure->setText(QApplication::translate("ScreenAfterLogin", "Log epileptic seizure", 0));
        setTemp->setText(QApplication::translate("ScreenAfterLogin", "Temperature", 0));
        pushButton->setText(QApplication::translate("ScreenAfterLogin", "Open Deur", 0));
    } // retranslateUi

};

namespace Ui {
    class ScreenAfterLogin: public Ui_ScreenAfterLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENAFTERLOGIN_H
