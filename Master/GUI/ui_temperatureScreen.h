/********************************************************************************
** Form generated from reading UI file 'temperatureScreen.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPERATURESCREEN_H
#define UI_TEMPERATURESCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_temperaturescreen
{
public:
    QLCDNumber *lcdNumber;
    QDial *dial;
    QLCDNumber *lcdNumber_2;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QPushButton *pushButton;

    void setupUi(QDialog *temperaturescreen)
    {
        if (temperaturescreen->objectName().isEmpty())
            temperaturescreen->setObjectName(QString::fromUtf8("temperaturescreen"));
        temperaturescreen->resize(400, 300);
        lcdNumber = new QLCDNumber(temperaturescreen);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(240, 80, 131, 51));
        lcdNumber->setAutoFillBackground(true);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("value", QVariant(21));
        lcdNumber->setProperty("intValue", QVariant(21));
        dial = new QDial(temperaturescreen);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(40, 150, 311, 141));
        dial->setMinimum(16);
        dial->setMaximum(28);
        dial->setSingleStep(1);
        dial->setValue(21);
        dial->setSliderPosition(21);
        dial->setInvertedAppearance(false);
        dial->setInvertedControls(false);
        dial->setWrapping(false);
        dial->setNotchesVisible(true);
        lcdNumber_2 = new QLCDNumber(temperaturescreen);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(30, 80, 131, 51));
        lcdNumber_2->setAutoFillBackground(true);
        textBrowser = new QTextBrowser(temperaturescreen);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 40, 101, 31));
        textBrowser_2 = new QTextBrowser(temperaturescreen);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(240, 40, 91, 31));
        pushButton = new QPushButton(temperaturescreen);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 10, 75, 23));

        retranslateUi(temperaturescreen);
        QObject::connect(dial, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));

        QMetaObject::connectSlotsByName(temperaturescreen);
    } // setupUi

    void retranslateUi(QDialog *temperaturescreen)
    {
        temperaturescreen->setWindowTitle(QApplication::translate("temperaturescreen", "Dialog", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("temperaturescreen", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Temp:</p></body></html>", 0, QApplication::UnicodeUTF8));
        textBrowser_2->setHtml(QApplication::translate("temperaturescreen", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Set Temp:</p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("temperaturescreen", "<-", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class temperaturescreen: public Ui_temperaturescreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPERATURESCREEN_H
