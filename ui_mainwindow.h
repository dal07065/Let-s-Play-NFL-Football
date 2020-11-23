/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdmin;
    QAction *actionLogOut;
    QAction *actionExit;
    QAction *actionAdmin_Functions;
    QWidget *centralwidget;
    QTableView *tableView;
    QPushButton *show_Data;
    QPushButton *show_Teams;
    QPushButton *show_NFCNorth;
    QPushButton *show_AFC_Teams;
    QPushButton *show_NFC_Teams;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *show_Stadiums;
    QPushButton *show_StadiumsByDate;
    QPushButton *show_openRoof;
    QPushButton *show_SeatingCapacity;
    QPushButton *show_11;
    QPushButton *show_12;
    QPushButton *show_13;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1206, 816);
        actionAdmin = new QAction(MainWindow);
        actionAdmin->setObjectName(QString::fromUtf8("actionAdmin"));
        actionLogOut = new QAction(MainWindow);
        actionLogOut->setObjectName(QString::fromUtf8("actionLogOut"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAdmin_Functions = new QAction(MainWindow);
        actionAdmin_Functions->setObjectName(QString::fromUtf8("actionAdmin_Functions"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(270, 150, 901, 511));
        show_Data = new QPushButton(centralwidget);
        show_Data->setObjectName(QString::fromUtf8("show_Data"));
        show_Data->setGeometry(QRect(10, 550, 241, 51));
        show_Teams = new QPushButton(centralwidget);
        show_Teams->setObjectName(QString::fromUtf8("show_Teams"));
        show_Teams->setGeometry(QRect(10, 150, 111, 51));
        show_NFCNorth = new QPushButton(centralwidget);
        show_NFCNorth->setObjectName(QString::fromUtf8("show_NFCNorth"));
        show_NFCNorth->setGeometry(QRect(10, 270, 111, 51));
        show_AFC_Teams = new QPushButton(centralwidget);
        show_AFC_Teams->setObjectName(QString::fromUtf8("show_AFC_Teams"));
        show_AFC_Teams->setGeometry(QRect(10, 210, 111, 51));
        show_NFC_Teams = new QPushButton(centralwidget);
        show_NFC_Teams->setObjectName(QString::fromUtf8("show_NFC_Teams"));
        show_NFC_Teams->setGeometry(QRect(140, 210, 111, 51));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 610, 241, 51));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 200, 95));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/logo.png")));
        label->setScaledContents(true);
        show_Stadiums = new QPushButton(centralwidget);
        show_Stadiums->setObjectName(QString::fromUtf8("show_Stadiums"));
        show_Stadiums->setGeometry(QRect(140, 150, 111, 51));
        show_StadiumsByDate = new QPushButton(centralwidget);
        show_StadiumsByDate->setObjectName(QString::fromUtf8("show_StadiumsByDate"));
        show_StadiumsByDate->setGeometry(QRect(140, 270, 111, 51));
        show_openRoof = new QPushButton(centralwidget);
        show_openRoof->setObjectName(QString::fromUtf8("show_openRoof"));
        show_openRoof->setGeometry(QRect(10, 330, 111, 51));
        show_SeatingCapacity = new QPushButton(centralwidget);
        show_SeatingCapacity->setObjectName(QString::fromUtf8("show_SeatingCapacity"));
        show_SeatingCapacity->setGeometry(QRect(140, 330, 111, 51));
        show_11 = new QPushButton(centralwidget);
        show_11->setObjectName(QString::fromUtf8("show_11"));
        show_11->setGeometry(QRect(10, 400, 111, 51));
        show_12 = new QPushButton(centralwidget);
        show_12->setObjectName(QString::fromUtf8("show_12"));
        show_12->setGeometry(QRect(140, 400, 111, 51));
        show_13 = new QPushButton(centralwidget);
        show_13->setObjectName(QString::fromUtf8("show_13"));
        show_13->setGeometry(QRect(10, 460, 111, 51));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAdmin->setText(QCoreApplication::translate("MainWindow", "Admin...", nullptr));
        actionLogOut->setText(QCoreApplication::translate("MainWindow", "Log Out...", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionAdmin_Functions->setText(QCoreApplication::translate("MainWindow", "Admin Functions", nullptr));
        show_Data->setText(QCoreApplication::translate("MainWindow", "Show Data", nullptr));
        show_Teams->setText(QCoreApplication::translate("MainWindow", "3. Show Teams", nullptr));
        show_NFCNorth->setText(QCoreApplication::translate("MainWindow", "7. Show NFC North", nullptr));
        show_AFC_Teams->setText(QCoreApplication::translate("MainWindow", "5. Show AFC Teams", nullptr));
        show_NFC_Teams->setText(QCoreApplication::translate("MainWindow", "6. Show NFC Teams", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Plan Vacation", nullptr));
        label->setText(QString());
        show_Stadiums->setText(QCoreApplication::translate("MainWindow", "4. Show Stadiums", nullptr));
        show_StadiumsByDate->setText(QCoreApplication::translate("MainWindow", "8. Stadiums by Date", nullptr));
        show_openRoof->setText(QCoreApplication::translate("MainWindow", "9. Open Roof", nullptr));
        show_SeatingCapacity->setText(QCoreApplication::translate("MainWindow", "10. Seating Capacity", nullptr));
        show_11->setText(QCoreApplication::translate("MainWindow", "11", nullptr));
        show_12->setText(QCoreApplication::translate("MainWindow", "12", nullptr));
        show_13->setText(QCoreApplication::translate("MainWindow", "13", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
