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
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(953, 816);
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
        tableView->setGeometry(QRect(270, 150, 641, 431));
        show_Data = new QPushButton(centralwidget);
        show_Data->setObjectName(QString::fromUtf8("show_Data"));
        show_Data->setGeometry(QRect(10, 340, 241, 51));
        show_Teams = new QPushButton(centralwidget);
        show_Teams->setObjectName(QString::fromUtf8("show_Teams"));
        show_Teams->setGeometry(QRect(10, 240, 241, 51));
        show_NFCNorth = new QPushButton(centralwidget);
        show_NFCNorth->setObjectName(QString::fromUtf8("show_NFCNorth"));
        show_NFCNorth->setGeometry(QRect(10, 290, 241, 51));
        show_AFC_Teams = new QPushButton(centralwidget);
        show_AFC_Teams->setObjectName(QString::fromUtf8("show_AFC_Teams"));
        show_AFC_Teams->setGeometry(QRect(10, 140, 241, 51));
        show_NFC_Teams = new QPushButton(centralwidget);
        show_NFC_Teams->setObjectName(QString::fromUtf8("show_NFC_Teams"));
        show_NFC_Teams->setGeometry(QRect(10, 190, 241, 51));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 390, 241, 51));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 200, 95));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/logo.png")));
        label->setScaledContents(true);
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
        show_Teams->setText(QCoreApplication::translate("MainWindow", "Show Teams", nullptr));
        show_NFCNorth->setText(QCoreApplication::translate("MainWindow", "Show NFC North", nullptr));
        show_AFC_Teams->setText(QCoreApplication::translate("MainWindow", "Show AFC Teams", nullptr));
        show_NFC_Teams->setText(QCoreApplication::translate("MainWindow", "Show NFC Teams", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Plan Vacation", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
