/********************************************************************************
** Form generated from reading UI file 'vacationinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VACATIONINFO_H
#define UI_VACATIONINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VacationInfo
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton;

    void setupUi(QWidget *VacationInfo)
    {
        if (VacationInfo->objectName().isEmpty())
            VacationInfo->setObjectName(QString::fromUtf8("VacationInfo"));
        VacationInfo->resize(759, 678);
        scrollArea = new QScrollArea(VacationInfo);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 731, 611));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 731, 611));
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton = new QPushButton(VacationInfo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 630, 181, 41));

        retranslateUi(VacationInfo);

        QMetaObject::connectSlotsByName(VacationInfo);
    } // setupUi

    void retranslateUi(QWidget *VacationInfo)
    {
        VacationInfo->setWindowTitle(QApplication::translate("VacationInfo", "Your Trip Summary", nullptr));
        pushButton->setText(QApplication::translate("VacationInfo", "Delete Trip", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VacationInfo: public Ui_VacationInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VACATIONINFO_H
