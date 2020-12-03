/********************************************************************************
** Form generated from reading UI file 'displaydata.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYDATA_H
#define UI_DISPLAYDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DisplayData
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton;

    void setupUi(QWidget *DisplayData)
    {
        if (DisplayData->objectName().isEmpty())
            DisplayData->setObjectName(QString::fromUtf8("DisplayData"));
        DisplayData->resize(759, 678);
        scrollArea = new QScrollArea(DisplayData);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 731, 611));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 731, 611));
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton = new QPushButton(DisplayData);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 630, 181, 41));

        retranslateUi(DisplayData);

        QMetaObject::connectSlotsByName(DisplayData);
    } // setupUi

    void retranslateUi(QWidget *DisplayData)
    {
        DisplayData->setWindowTitle(QApplication::translate("DisplayData", "Displaying Data", nullptr));
        pushButton->setText(QApplication::translate("DisplayData", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DisplayData: public Ui_DisplayData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYDATA_H
