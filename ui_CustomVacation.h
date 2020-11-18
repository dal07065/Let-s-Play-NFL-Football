/********************************************************************************
** Form generated from reading UI file 'CustomVacation.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMVACATION_H
#define UI_CUSTOMVACATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomVacation
{
public:
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButtonFirst;
    QPushButton *pushButtonSecond;
    QListWidget *listWidgetFirst;
    QListWidget *listWidgetSecond;
    QLabel *label_4;
    QLabel *label_5;
    QListWidget *souvAvailable;
    QLabel *label_6;
    QListWidget *souvSelected;
    QPushButton *pushButtonSouv1;
    QPushButton *pushButtonSouv2;
    QLabel *label_7;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *thirteenTeamPlan;
    QPushButton *bookYourTrip;
    QLabel *hiddenLabel;
    QLabel *result_lbl;
    QSpinBox *numberOfCitiesSpinBox;
    QPushButton *NumberTripPushButton;

    void setupUi(QWidget *CustomVacation)
    {
        if (CustomVacation->objectName().isEmpty())
            CustomVacation->setObjectName(QString::fromUtf8("CustomVacation"));
        CustomVacation->resize(953, 816);
        label_2 = new QLabel(CustomVacation);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(430, 30, 101, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label = new QLabel(CustomVacation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 151, 31));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);
        pushButtonFirst = new QPushButton(CustomVacation);
        pushButtonFirst->setObjectName(QString::fromUtf8("pushButtonFirst"));
        pushButtonFirst->setGeometry(QRect(450, 120, 61, 32));
        pushButtonSecond = new QPushButton(CustomVacation);
        pushButtonSecond->setObjectName(QString::fromUtf8("pushButtonSecond"));
        pushButtonSecond->setGeometry(QRect(450, 150, 61, 32));
        listWidgetFirst = new QListWidget(CustomVacation);
        listWidgetFirst->setObjectName(QString::fromUtf8("listWidgetFirst"));
        listWidgetFirst->setGeometry(QRect(20, 90, 401, 111));
        listWidgetFirst->setStyleSheet(QString::fromUtf8(""));
        listWidgetSecond = new QListWidget(CustomVacation);
        listWidgetSecond->setObjectName(QString::fromUtf8("listWidgetSecond"));
        listWidgetSecond->setGeometry(QRect(530, 90, 391, 111));
        label_4 = new QLabel(CustomVacation);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 70, 141, 16));
        label_5 = new QLabel(CustomVacation);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(530, 70, 281, 16));
        souvAvailable = new QListWidget(CustomVacation);
        souvAvailable->setObjectName(QString::fromUtf8("souvAvailable"));
        souvAvailable->setGeometry(QRect(20, 230, 401, 111));
        label_6 = new QLabel(CustomVacation);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 210, 141, 16));
        souvSelected = new QListWidget(CustomVacation);
        souvSelected->setObjectName(QString::fromUtf8("souvSelected"));
        souvSelected->setGeometry(QRect(530, 230, 391, 111));
        pushButtonSouv1 = new QPushButton(CustomVacation);
        pushButtonSouv1->setObjectName(QString::fromUtf8("pushButtonSouv1"));
        pushButtonSouv1->setGeometry(QRect(450, 250, 61, 32));
        pushButtonSouv2 = new QPushButton(CustomVacation);
        pushButtonSouv2->setObjectName(QString::fromUtf8("pushButtonSouv2"));
        pushButtonSouv2->setGeometry(QRect(450, 280, 61, 32));
        label_7 = new QLabel(CustomVacation);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(530, 210, 161, 16));
        scrollArea_2 = new QScrollArea(CustomVacation);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(530, 380, 391, 351));
        scrollArea_2->setFrameShape(QFrame::NoFrame);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 391, 351));
        verticalLayoutWidget_2 = new QWidget(scrollAreaWidgetContents_3);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 371, 341));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea_2->setWidget(scrollAreaWidgetContents_3);
        scrollArea = new QScrollArea(CustomVacation);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(30, 380, 381, 361));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 381, 361));
        scrollArea->setWidget(scrollAreaWidgetContents);
        thirteenTeamPlan = new QPushButton(CustomVacation);
        thirteenTeamPlan->setObjectName(QString::fromUtf8("thirteenTeamPlan"));
        thirteenTeamPlan->setGeometry(QRect(60, 340, 161, 28));
        bookYourTrip = new QPushButton(CustomVacation);
        bookYourTrip->setObjectName(QString::fromUtf8("bookYourTrip"));
        bookYourTrip->setGeometry(QRect(730, 760, 181, 41));
        hiddenLabel = new QLabel(CustomVacation);
        hiddenLabel->setObjectName(QString::fromUtf8("hiddenLabel"));
        hiddenLabel->setEnabled(true);
        hiddenLabel->setGeometry(QRect(650, 570, 21, 16));
        result_lbl = new QLabel(CustomVacation);
        result_lbl->setObjectName(QString::fromUtf8("result_lbl"));
        result_lbl->setGeometry(QRect(40, 720, 311, 31));
        numberOfCitiesSpinBox = new QSpinBox(CustomVacation);
        numberOfCitiesSpinBox->setObjectName(QString::fromUtf8("numberOfCitiesSpinBox"));
        numberOfCitiesSpinBox->setGeometry(QRect(530, 340, 42, 22));
        NumberTripPushButton = new QPushButton(CustomVacation);
        NumberTripPushButton->setObjectName(QString::fromUtf8("NumberTripPushButton"));
        NumberTripPushButton->setGeometry(QRect(580, 340, 171, 28));

        retranslateUi(CustomVacation);

        QMetaObject::connectSlotsByName(CustomVacation);
    } // setupUi

    void retranslateUi(QWidget *CustomVacation)
    {
        CustomVacation->setWindowTitle(QApplication::translate("CustomVacation", "Plan Your Trip", nullptr));
        label_2->setText(QApplication::translate("CustomVacation", "Plan Your Trip!", nullptr));
        label->setText(QApplication::translate("CustomVacation", "Welcome, guest", nullptr));
        pushButtonFirst->setText(QApplication::translate("CustomVacation", ">>", nullptr));
        pushButtonSecond->setText(QApplication::translate("CustomVacation", "<<", nullptr));
        label_4->setText(QApplication::translate("CustomVacation", "Teams Available", nullptr));
        label_5->setText(QApplication::translate("CustomVacation", "Destination Teams (check preferred start team)", nullptr));
        label_6->setText(QApplication::translate("CustomVacation", "Souvenir Available", nullptr));
        pushButtonSouv1->setText(QApplication::translate("CustomVacation", ">>", nullptr));
        pushButtonSouv2->setText(QApplication::translate("CustomVacation", "<<", nullptr));
        label_7->setText(QApplication::translate("CustomVacation", "Souvenir added to your cart", nullptr));
        thirteenTeamPlan->setText(QApplication::translate("CustomVacation", "All Teams Trip", nullptr));
        bookYourTrip->setText(QApplication::translate("CustomVacation", "Book your Trip", nullptr));
        hiddenLabel->setText(QString());
        result_lbl->setText(QString());
        NumberTripPushButton->setText(QApplication::translate("CustomVacation", "Number of Cities Trip", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomVacation: public Ui_CustomVacation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMVACATION_H
