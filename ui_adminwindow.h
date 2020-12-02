/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminWindow
{
public:
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox_Team_Selection;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_NewStadium;
    QLineEdit *lineEdit_NewStadium;
    QSplitter *splitter;
    QLabel *label_NewStadium_Capacity;
    QSpinBox *spinBox_NewStadium_Capacity;
    QHBoxLayout *horizontalLayout;
    QLabel *label_NewStadium_OpenDate;
    QSpinBox *spinBox_NewStadium_Date;
    QPushButton *pushButton_NewStadium_Add;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_SelectSouvenir;
    QComboBox *comboBox_SelectSouvenir;
    QHBoxLayout *horizontalLayout_3;
    QDoubleSpinBox *doubleSpinBox_SelectSouvenir_Price;
    QPushButton *pushButton_SelectSouvenir_SetPrice;
    QPushButton *pushButton_SelectSouvenir_Delete;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_NewSouvenir;
    QLineEdit *lineEdit_NewSouvenir_Name;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_NewSouvenir_Price;
    QDoubleSpinBox *doubleSpinBox_NewSouvenir_Price;
    QPushButton *pushButton_NewSouvenir_Add;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_SelectStadium;
    QComboBox *comboBox_SelectStadium;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_SelectStadium_Capacity;
    QSpinBox *spinBox_SelectStadium_SetCapacity;
    QPushButton *pushButton_SelectStadium_SetCapacity;

    void setupUi(QDialog *adminWindow)
    {
        if (adminWindow->objectName().isEmpty())
            adminWindow->setObjectName(QString::fromUtf8("adminWindow"));
        adminWindow->resize(583, 444);
        label_2 = new QLabel(adminWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(42, 12, 496, 90));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/img/img/Team Logo.png")));
        label_2->setScaledContents(true);
        layoutWidget = new QWidget(adminWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(190, 110, 201, 41));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Plain);
        label->setLineWidth(1);

        verticalLayout->addWidget(label);

        comboBox_Team_Selection = new QComboBox(layoutWidget);
        comboBox_Team_Selection->setObjectName(QString::fromUtf8("comboBox_Team_Selection"));

        verticalLayout->addWidget(comboBox_Team_Selection);

        layoutWidget1 = new QWidget(adminWindow);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setEnabled(true);
        layoutWidget1->setGeometry(QRect(290, 290, 241, 104));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_NewStadium = new QLabel(layoutWidget1);
        label_NewStadium->setObjectName(QString::fromUtf8("label_NewStadium"));
        label_NewStadium->setEnabled(true);
        label_NewStadium->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(label_NewStadium);

        lineEdit_NewStadium = new QLineEdit(layoutWidget1);
        lineEdit_NewStadium->setObjectName(QString::fromUtf8("lineEdit_NewStadium"));
        lineEdit_NewStadium->setEnabled(true);

        verticalLayout_2->addWidget(lineEdit_NewStadium);

        splitter = new QSplitter(layoutWidget1);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setEnabled(true);
        splitter->setOrientation(Qt::Horizontal);
        label_NewStadium_Capacity = new QLabel(splitter);
        label_NewStadium_Capacity->setObjectName(QString::fromUtf8("label_NewStadium_Capacity"));
        label_NewStadium_Capacity->setEnabled(true);
        splitter->addWidget(label_NewStadium_Capacity);
        spinBox_NewStadium_Capacity = new QSpinBox(splitter);
        spinBox_NewStadium_Capacity->setObjectName(QString::fromUtf8("spinBox_NewStadium_Capacity"));
        spinBox_NewStadium_Capacity->setEnabled(true);
        spinBox_NewStadium_Capacity->setMinimum(1);
        spinBox_NewStadium_Capacity->setMaximum(100000);
        splitter->addWidget(spinBox_NewStadium_Capacity);

        verticalLayout_2->addWidget(splitter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_NewStadium_OpenDate = new QLabel(layoutWidget1);
        label_NewStadium_OpenDate->setObjectName(QString::fromUtf8("label_NewStadium_OpenDate"));
        label_NewStadium_OpenDate->setEnabled(true);

        horizontalLayout->addWidget(label_NewStadium_OpenDate);

        spinBox_NewStadium_Date = new QSpinBox(layoutWidget1);
        spinBox_NewStadium_Date->setObjectName(QString::fromUtf8("spinBox_NewStadium_Date"));
        spinBox_NewStadium_Date->setEnabled(true);
        spinBox_NewStadium_Date->setMinimum(2020);
        spinBox_NewStadium_Date->setMaximum(9999);

        horizontalLayout->addWidget(spinBox_NewStadium_Date);


        verticalLayout_2->addLayout(horizontalLayout);

        pushButton_NewStadium_Add = new QPushButton(layoutWidget1);
        pushButton_NewStadium_Add->setObjectName(QString::fromUtf8("pushButton_NewStadium_Add"));
        pushButton_NewStadium_Add->setEnabled(true);

        verticalLayout_2->addWidget(pushButton_NewStadium_Add);

        layoutWidget2 = new QWidget(adminWindow);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(31, 171, 241, 101));
        verticalLayout_4 = new QVBoxLayout(layoutWidget2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_SelectSouvenir = new QLabel(layoutWidget2);
        label_SelectSouvenir->setObjectName(QString::fromUtf8("label_SelectSouvenir"));
        label_SelectSouvenir->setFrameShadow(QFrame::Raised);

        verticalLayout_4->addWidget(label_SelectSouvenir);

        comboBox_SelectSouvenir = new QComboBox(layoutWidget2);
        comboBox_SelectSouvenir->setObjectName(QString::fromUtf8("comboBox_SelectSouvenir"));

        verticalLayout_4->addWidget(comboBox_SelectSouvenir);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        doubleSpinBox_SelectSouvenir_Price = new QDoubleSpinBox(layoutWidget2);
        doubleSpinBox_SelectSouvenir_Price->setObjectName(QString::fromUtf8("doubleSpinBox_SelectSouvenir_Price"));
        doubleSpinBox_SelectSouvenir_Price->setMaximum(500.000000000000000);
        doubleSpinBox_SelectSouvenir_Price->setSingleStep(0.010000000000000);

        horizontalLayout_3->addWidget(doubleSpinBox_SelectSouvenir_Price);

        pushButton_SelectSouvenir_SetPrice = new QPushButton(layoutWidget2);
        pushButton_SelectSouvenir_SetPrice->setObjectName(QString::fromUtf8("pushButton_SelectSouvenir_SetPrice"));

        horizontalLayout_3->addWidget(pushButton_SelectSouvenir_SetPrice);


        verticalLayout_4->addLayout(horizontalLayout_3);

        pushButton_SelectSouvenir_Delete = new QPushButton(layoutWidget2);
        pushButton_SelectSouvenir_Delete->setObjectName(QString::fromUtf8("pushButton_SelectSouvenir_Delete"));

        verticalLayout_4->addWidget(pushButton_SelectSouvenir_Delete);

        layoutWidget3 = new QWidget(adminWindow);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(30, 290, 241, 101));
        verticalLayout_5 = new QVBoxLayout(layoutWidget3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_NewSouvenir = new QLabel(layoutWidget3);
        label_NewSouvenir->setObjectName(QString::fromUtf8("label_NewSouvenir"));
        label_NewSouvenir->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(label_NewSouvenir);

        lineEdit_NewSouvenir_Name = new QLineEdit(layoutWidget3);
        lineEdit_NewSouvenir_Name->setObjectName(QString::fromUtf8("lineEdit_NewSouvenir_Name"));

        verticalLayout_5->addWidget(lineEdit_NewSouvenir_Name);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_NewSouvenir_Price = new QLabel(layoutWidget3);
        label_NewSouvenir_Price->setObjectName(QString::fromUtf8("label_NewSouvenir_Price"));

        horizontalLayout_4->addWidget(label_NewSouvenir_Price);

        doubleSpinBox_NewSouvenir_Price = new QDoubleSpinBox(layoutWidget3);
        doubleSpinBox_NewSouvenir_Price->setObjectName(QString::fromUtf8("doubleSpinBox_NewSouvenir_Price"));
        doubleSpinBox_NewSouvenir_Price->setMaximum(500.000000000000000);
        doubleSpinBox_NewSouvenir_Price->setSingleStep(0.250000000000000);

        horizontalLayout_4->addWidget(doubleSpinBox_NewSouvenir_Price);


        verticalLayout_5->addLayout(horizontalLayout_4);

        pushButton_NewSouvenir_Add = new QPushButton(layoutWidget3);
        pushButton_NewSouvenir_Add->setObjectName(QString::fromUtf8("pushButton_NewSouvenir_Add"));

        verticalLayout_5->addWidget(pushButton_NewSouvenir_Add);

        layoutWidget4 = new QWidget(adminWindow);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(291, 171, 241, 101));
        verticalLayout_3 = new QVBoxLayout(layoutWidget4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_SelectStadium = new QLabel(layoutWidget4);
        label_SelectStadium->setObjectName(QString::fromUtf8("label_SelectStadium"));
        label_SelectStadium->setFrameShadow(QFrame::Raised);

        verticalLayout_3->addWidget(label_SelectStadium);

        comboBox_SelectStadium = new QComboBox(layoutWidget4);
        comboBox_SelectStadium->setObjectName(QString::fromUtf8("comboBox_SelectStadium"));

        verticalLayout_3->addWidget(comboBox_SelectStadium);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_SelectStadium_Capacity = new QLabel(layoutWidget4);
        label_SelectStadium_Capacity->setObjectName(QString::fromUtf8("label_SelectStadium_Capacity"));

        horizontalLayout_2->addWidget(label_SelectStadium_Capacity);

        spinBox_SelectStadium_SetCapacity = new QSpinBox(layoutWidget4);
        spinBox_SelectStadium_SetCapacity->setObjectName(QString::fromUtf8("spinBox_SelectStadium_SetCapacity"));
        spinBox_SelectStadium_SetCapacity->setMaximum(1000000);

        horizontalLayout_2->addWidget(spinBox_SelectStadium_SetCapacity);


        verticalLayout_3->addLayout(horizontalLayout_2);

        pushButton_SelectStadium_SetCapacity = new QPushButton(layoutWidget4);
        pushButton_SelectStadium_SetCapacity->setObjectName(QString::fromUtf8("pushButton_SelectStadium_SetCapacity"));

        verticalLayout_3->addWidget(pushButton_SelectStadium_SetCapacity);


        retranslateUi(adminWindow);

        QMetaObject::connectSlotsByName(adminWindow);
    } // setupUi

    void retranslateUi(QDialog *adminWindow)
    {
        adminWindow->setWindowTitle(QCoreApplication::translate("adminWindow", "Dialog", nullptr));
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("adminWindow", "Select Team to Edit", nullptr));
        label_NewStadium->setText(QCoreApplication::translate("adminWindow", "Enter Name of New Stadium:", nullptr));
        label_NewStadium_Capacity->setText(QCoreApplication::translate("adminWindow", "Capacity", nullptr));
        label_NewStadium_OpenDate->setText(QCoreApplication::translate("adminWindow", "Open Date (year)", nullptr));
        pushButton_NewStadium_Add->setText(QCoreApplication::translate("adminWindow", "Add New Stadium", nullptr));
        label_SelectSouvenir->setText(QCoreApplication::translate("adminWindow", "Select Souvenir to Edit Price", nullptr));
        pushButton_SelectSouvenir_SetPrice->setText(QCoreApplication::translate("adminWindow", "Set Price", nullptr));
        pushButton_SelectSouvenir_Delete->setText(QCoreApplication::translate("adminWindow", "Delete Souvenir", nullptr));
        label_NewSouvenir->setText(QCoreApplication::translate("adminWindow", "Enter Name of New Souvenir:", nullptr));
        label_NewSouvenir_Price->setText(QCoreApplication::translate("adminWindow", "Price", nullptr));
        pushButton_NewSouvenir_Add->setText(QCoreApplication::translate("adminWindow", "Add New Souvenir", nullptr));
        label_SelectStadium->setText(QCoreApplication::translate("adminWindow", "Select Stadium:", nullptr));
        label_SelectStadium_Capacity->setText(QCoreApplication::translate("adminWindow", "Capacity", nullptr));
        pushButton_SelectStadium_SetCapacity->setText(QCoreApplication::translate("adminWindow", "Set New Capacity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminWindow: public Ui_adminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
