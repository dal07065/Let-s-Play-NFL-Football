/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminWindow
{
public:
    QLabel *label_2;
    QWidget *widget;
    QVBoxLayout *Layout_SelectTeam;
    QLabel *label;
    QComboBox *comboBox_Team_Selection;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *Layout_SelectSouvenir;
    QLabel *label_SelectSouvenir;
    QComboBox *comboBox_SelectSouvenir;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *doubleSpinBox_SelectSouvenir_Price;
    QPushButton *pushButton_SelectSouvenir_SetPrice;
    QPushButton *pushButton_SelectSouvenir_Delete;
    QVBoxLayout *Layout_SelectStadium;
    QLabel *label_SelectStadium;
    QComboBox *comboBox_SelectStadium;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_SelectStadium_Capacity;
    QSpinBox *spinBox_SelectStadium_SetCapacity;
    QPushButton *pushButton_SelectStadium_SetCapacity;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QLabel *label_NewSouvenir;
    QLineEdit *lineEdit_NewSouvenir_Name;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_NewSouvenir_Price;
    QDoubleSpinBox *doubleSpinBox_NewSouvenir_Price;
    QPushButton *pushButton_NewSouvenir_Add;
    QVBoxLayout *Layout_NewStadium;
    QLabel *label_NewStadium;
    QLineEdit *lineEdit_NewStadium;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_NewStadium_Capacity;
    QSpinBox *spinBox_NewStadium_Capacity;
    QPushButton *pushButton_NewStadium_Add;

    void setupUi(QDialog *adminWindow)
    {
        if (adminWindow->objectName().isEmpty())
            adminWindow->setObjectName(QString::fromUtf8("adminWindow"));
        adminWindow->resize(412, 419);
        label_2 = new QLabel(adminWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 10, 331, 51));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/img/img/Team Logo.png")));
        label_2->setScaledContents(true);
        widget = new QWidget(adminWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(90, 70, 231, 41));
        Layout_SelectTeam = new QVBoxLayout(widget);
        Layout_SelectTeam->setObjectName(QString::fromUtf8("Layout_SelectTeam"));
        Layout_SelectTeam->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        Layout_SelectTeam->addWidget(label);

        comboBox_Team_Selection = new QComboBox(widget);
        comboBox_Team_Selection->setObjectName(QString::fromUtf8("comboBox_Team_Selection"));

        Layout_SelectTeam->addWidget(comboBox_Team_Selection);

        widget1 = new QWidget(adminWindow);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(40, 127, 331, 241));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Layout_SelectSouvenir = new QVBoxLayout();
        Layout_SelectSouvenir->setObjectName(QString::fromUtf8("Layout_SelectSouvenir"));
        label_SelectSouvenir = new QLabel(widget1);
        label_SelectSouvenir->setObjectName(QString::fromUtf8("label_SelectSouvenir"));

        Layout_SelectSouvenir->addWidget(label_SelectSouvenir);

        comboBox_SelectSouvenir = new QComboBox(widget1);
        comboBox_SelectSouvenir->setObjectName(QString::fromUtf8("comboBox_SelectSouvenir"));

        Layout_SelectSouvenir->addWidget(comboBox_SelectSouvenir);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        doubleSpinBox_SelectSouvenir_Price = new QDoubleSpinBox(widget1);
        doubleSpinBox_SelectSouvenir_Price->setObjectName(QString::fromUtf8("doubleSpinBox_SelectSouvenir_Price"));
        doubleSpinBox_SelectSouvenir_Price->setMaximum(500.000000000000000);
        doubleSpinBox_SelectSouvenir_Price->setSingleStep(0.250000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_SelectSouvenir_Price);

        pushButton_SelectSouvenir_SetPrice = new QPushButton(widget1);
        pushButton_SelectSouvenir_SetPrice->setObjectName(QString::fromUtf8("pushButton_SelectSouvenir_SetPrice"));

        horizontalLayout_2->addWidget(pushButton_SelectSouvenir_SetPrice);


        Layout_SelectSouvenir->addLayout(horizontalLayout_2);

        pushButton_SelectSouvenir_Delete = new QPushButton(widget1);
        pushButton_SelectSouvenir_Delete->setObjectName(QString::fromUtf8("pushButton_SelectSouvenir_Delete"));

        Layout_SelectSouvenir->addWidget(pushButton_SelectSouvenir_Delete);


        horizontalLayout->addLayout(Layout_SelectSouvenir);

        Layout_SelectStadium = new QVBoxLayout();
        Layout_SelectStadium->setObjectName(QString::fromUtf8("Layout_SelectStadium"));
        label_SelectStadium = new QLabel(widget1);
        label_SelectStadium->setObjectName(QString::fromUtf8("label_SelectStadium"));

        Layout_SelectStadium->addWidget(label_SelectStadium);

        comboBox_SelectStadium = new QComboBox(widget1);
        comboBox_SelectStadium->setObjectName(QString::fromUtf8("comboBox_SelectStadium"));

        Layout_SelectStadium->addWidget(comboBox_SelectStadium);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_SelectStadium_Capacity = new QLabel(widget1);
        label_SelectStadium_Capacity->setObjectName(QString::fromUtf8("label_SelectStadium_Capacity"));

        horizontalLayout_4->addWidget(label_SelectStadium_Capacity);

        spinBox_SelectStadium_SetCapacity = new QSpinBox(widget1);
        spinBox_SelectStadium_SetCapacity->setObjectName(QString::fromUtf8("spinBox_SelectStadium_SetCapacity"));
        spinBox_SelectStadium_SetCapacity->setMaximum(1000000);

        horizontalLayout_4->addWidget(spinBox_SelectStadium_SetCapacity);


        Layout_SelectStadium->addLayout(horizontalLayout_4);

        pushButton_SelectStadium_SetCapacity = new QPushButton(widget1);
        pushButton_SelectStadium_SetCapacity->setObjectName(QString::fromUtf8("pushButton_SelectStadium_SetCapacity"));

        Layout_SelectStadium->addWidget(pushButton_SelectStadium_SetCapacity);


        horizontalLayout->addLayout(Layout_SelectStadium);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_NewSouvenir = new QLabel(widget1);
        label_NewSouvenir->setObjectName(QString::fromUtf8("label_NewSouvenir"));

        verticalLayout->addWidget(label_NewSouvenir);

        lineEdit_NewSouvenir_Name = new QLineEdit(widget1);
        lineEdit_NewSouvenir_Name->setObjectName(QString::fromUtf8("lineEdit_NewSouvenir_Name"));

        verticalLayout->addWidget(lineEdit_NewSouvenir_Name);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_NewSouvenir_Price = new QLabel(widget1);
        label_NewSouvenir_Price->setObjectName(QString::fromUtf8("label_NewSouvenir_Price"));

        horizontalLayout_5->addWidget(label_NewSouvenir_Price);

        doubleSpinBox_NewSouvenir_Price = new QDoubleSpinBox(widget1);
        doubleSpinBox_NewSouvenir_Price->setObjectName(QString::fromUtf8("doubleSpinBox_NewSouvenir_Price"));
        doubleSpinBox_NewSouvenir_Price->setMaximum(500.000000000000000);
        doubleSpinBox_NewSouvenir_Price->setSingleStep(0.250000000000000);

        horizontalLayout_5->addWidget(doubleSpinBox_NewSouvenir_Price);


        verticalLayout->addLayout(horizontalLayout_5);

        pushButton_NewSouvenir_Add = new QPushButton(widget1);
        pushButton_NewSouvenir_Add->setObjectName(QString::fromUtf8("pushButton_NewSouvenir_Add"));

        verticalLayout->addWidget(pushButton_NewSouvenir_Add);


        horizontalLayout_6->addLayout(verticalLayout);

        Layout_NewStadium = new QVBoxLayout();
        Layout_NewStadium->setObjectName(QString::fromUtf8("Layout_NewStadium"));
        label_NewStadium = new QLabel(widget1);
        label_NewStadium->setObjectName(QString::fromUtf8("label_NewStadium"));

        Layout_NewStadium->addWidget(label_NewStadium);

        lineEdit_NewStadium = new QLineEdit(widget1);
        lineEdit_NewStadium->setObjectName(QString::fromUtf8("lineEdit_NewStadium"));

        Layout_NewStadium->addWidget(lineEdit_NewStadium);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_NewStadium_Capacity = new QLabel(widget1);
        label_NewStadium_Capacity->setObjectName(QString::fromUtf8("label_NewStadium_Capacity"));

        horizontalLayout_3->addWidget(label_NewStadium_Capacity);

        spinBox_NewStadium_Capacity = new QSpinBox(widget1);
        spinBox_NewStadium_Capacity->setObjectName(QString::fromUtf8("spinBox_NewStadium_Capacity"));

        horizontalLayout_3->addWidget(spinBox_NewStadium_Capacity);


        Layout_NewStadium->addLayout(horizontalLayout_3);

        pushButton_NewStadium_Add = new QPushButton(widget1);
        pushButton_NewStadium_Add->setObjectName(QString::fromUtf8("pushButton_NewStadium_Add"));

        Layout_NewStadium->addWidget(pushButton_NewStadium_Add);


        horizontalLayout_6->addLayout(Layout_NewStadium);


        gridLayout->addLayout(horizontalLayout_6, 1, 0, 1, 1);


        retranslateUi(adminWindow);

        QMetaObject::connectSlotsByName(adminWindow);
    } // setupUi

    void retranslateUi(QDialog *adminWindow)
    {
        adminWindow->setWindowTitle(QCoreApplication::translate("adminWindow", "Dialog", nullptr));
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("adminWindow", "Select Team to Edit", nullptr));
        label_SelectSouvenir->setText(QCoreApplication::translate("adminWindow", "Select Souvenir to Edit Price", nullptr));
        pushButton_SelectSouvenir_SetPrice->setText(QCoreApplication::translate("adminWindow", "Set Price", nullptr));
        pushButton_SelectSouvenir_Delete->setText(QCoreApplication::translate("adminWindow", "Delete Souvenir", nullptr));
        label_SelectStadium->setText(QCoreApplication::translate("adminWindow", "Select Stadium:", nullptr));
        label_SelectStadium_Capacity->setText(QCoreApplication::translate("adminWindow", "Capacity", nullptr));
        pushButton_SelectStadium_SetCapacity->setText(QCoreApplication::translate("adminWindow", "Set New Capacity", nullptr));
        label_NewSouvenir->setText(QCoreApplication::translate("adminWindow", "Enter Name of New Souvenir:", nullptr));
        label_NewSouvenir_Price->setText(QCoreApplication::translate("adminWindow", "Price", nullptr));
        pushButton_NewSouvenir_Add->setText(QCoreApplication::translate("adminWindow", "Add New Souvenir", nullptr));
        label_NewStadium->setText(QCoreApplication::translate("adminWindow", "Enter Name of New Stadium:", nullptr));
        label_NewStadium_Capacity->setText(QCoreApplication::translate("adminWindow", "Capacity", nullptr));
        pushButton_NewStadium_Add->setText(QCoreApplication::translate("adminWindow", "Add New Stadium", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminWindow: public Ui_adminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
