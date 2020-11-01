/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
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
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 800);
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
        tableView->setGeometry(QRect(630, 150, 961, 531));
        show_Data = new QPushButton(centralwidget);
        show_Data->setObjectName(QString::fromUtf8("show_Data"));
        show_Data->setGeometry(QRect(440, 390, 131, 51));
        show_Teams = new QPushButton(centralwidget);
        show_Teams->setObjectName(QString::fromUtf8("show_Teams"));
        show_Teams->setGeometry(QRect(440, 180, 131, 51));
        show_NFCNorth = new QPushButton(centralwidget);
        show_NFCNorth->setObjectName(QString::fromUtf8("show_NFCNorth"));
        show_NFCNorth->setGeometry(QRect(440, 240, 131, 51));
        show_AFC_Teams = new QPushButton(centralwidget);
        show_AFC_Teams->setObjectName(QString::fromUtf8("show_AFC_Teams"));
        show_AFC_Teams->setGeometry(QRect(230, 180, 131, 51));
        show_NFC_Teams = new QPushButton(centralwidget);
        show_NFC_Teams->setObjectName(QString::fromUtf8("show_NFC_Teams"));
        show_NFC_Teams->setGeometry(QRect(230, 230, 131, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1600, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionAdmin);
        menuFile->addAction(actionLogOut);
        menuFile->addAction(actionExit);
        menuFile->addAction(actionAdmin_Functions);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAdmin->setText(QApplication::translate("MainWindow", "Admin...", nullptr));
        actionLogOut->setText(QApplication::translate("MainWindow", "Log Out...", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionAdmin_Functions->setText(QApplication::translate("MainWindow", "Admin Functions", nullptr));
        show_Data->setText(QApplication::translate("MainWindow", "Show Data", nullptr));
        show_Teams->setText(QApplication::translate("MainWindow", "Show Teams", nullptr));
        show_NFCNorth->setText(QApplication::translate("MainWindow", "Show NFC North", nullptr));
        show_AFC_Teams->setText(QApplication::translate("MainWindow", "Show AFC Teams", nullptr));
        show_NFC_Teams->setText(QApplication::translate("MainWindow", "Show NFC Teams", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
