/********************************************************************************
** Form generated from reading UI file 'screenafterlogin.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENAFTERLOGIN_H
#define UI_SCREENAFTERLOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ScreenAfterLogin
{
public:
    QLabel *date;
    QPushButton *LogSeizure;

    void setupUi(QDialog *ScreenAfterLogin)
    {
        if (ScreenAfterLogin->objectName().isEmpty())
            ScreenAfterLogin->setObjectName(QString::fromUtf8("ScreenAfterLogin"));
        ScreenAfterLogin->resize(400, 300);
        date = new QLabel(ScreenAfterLogin);
        date->setObjectName(QString::fromUtf8("date"));
        date->setGeometry(QRect(60, 10, 321, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        date->setFont(font);
        LogSeizure = new QPushButton(ScreenAfterLogin);
        LogSeizure->setObjectName(QString::fromUtf8("LogSeizure"));
        LogSeizure->setGeometry(QRect(230, 240, 141, 28));

        retranslateUi(ScreenAfterLogin);

        QMetaObject::connectSlotsByName(ScreenAfterLogin);
    } // setupUi

    void retranslateUi(QDialog *ScreenAfterLogin)
    {
        ScreenAfterLogin->setWindowTitle(QApplication::translate("ScreenAfterLogin", "Dialog", 0, QApplication::UnicodeUTF8));
        date->setText(QApplication::translate("ScreenAfterLogin", "Date", 0, QApplication::UnicodeUTF8));
        LogSeizure->setText(QApplication::translate("ScreenAfterLogin", "Log epileptic seizure", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ScreenAfterLogin: public Ui_ScreenAfterLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENAFTERLOGIN_H
