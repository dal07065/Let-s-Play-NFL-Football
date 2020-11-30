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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QAction *actionLoad_Team;
    QAction *actionReset_Database;
    QWidget *centralwidget;
    QTableView *tableView;
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
    QPushButton *show_Conference;
    QPushButton *show_BermudaGrass;
    QPushButton *show_Selection_S;
    QLabel *numberLabel;
    QComboBox *teamComboBox;
    QPushButton *show_Selection;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1240, 804);
        actionAdmin = new QAction(MainWindow);
        actionAdmin->setObjectName(QString::fromUtf8("actionAdmin"));
        actionLogOut = new QAction(MainWindow);
        actionLogOut->setObjectName(QString::fromUtf8("actionLogOut"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAdmin_Functions = new QAction(MainWindow);
        actionAdmin_Functions->setObjectName(QString::fromUtf8("actionAdmin_Functions"));
        actionLoad_Team = new QAction(MainWindow);
        actionLoad_Team->setObjectName(QString::fromUtf8("actionLoad_Team"));
        actionReset_Database = new QAction(MainWindow);
        actionReset_Database->setObjectName(QString::fromUtf8("actionReset_Database"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(270, 150, 951, 531));
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
        pushButton->setGeometry(QRect(10, 630, 241, 51));
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
        show_Conference = new QPushButton(centralwidget);
        show_Conference->setObjectName(QString::fromUtf8("show_Conference"));
        show_Conference->setGeometry(QRect(10, 400, 111, 51));
        show_BermudaGrass = new QPushButton(centralwidget);
        show_BermudaGrass->setObjectName(QString::fromUtf8("show_BermudaGrass"));
        show_BermudaGrass->setGeometry(QRect(140, 400, 111, 51));
        show_Selection_S = new QPushButton(centralwidget);
        show_Selection_S->setObjectName(QString::fromUtf8("show_Selection_S"));
        show_Selection_S->setGeometry(QRect(10, 560, 241, 51));
        numberLabel = new QLabel(centralwidget);
        numberLabel->setObjectName(QString::fromUtf8("numberLabel"));
        numberLabel->setGeometry(QRect(760, 90, 451, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(20);
        font.setBold(false);
        font.setWeight(50);
        numberLabel->setFont(font);
        numberLabel->setLayoutDirection(Qt::RightToLeft);
        teamComboBox = new QComboBox(centralwidget);
        teamComboBox->setObjectName(QString::fromUtf8("teamComboBox"));
        teamComboBox->setGeometry(QRect(30, 470, 201, 22));
        show_Selection = new QPushButton(centralwidget);
        show_Selection->setObjectName(QString::fromUtf8("show_Selection"));
        show_Selection->setGeometry(QRect(10, 500, 241, 51));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1240, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionAdmin);
        menuFile->addAction(actionLogOut);
        menuFile->addAction(actionExit);
        menuFile->addAction(actionAdmin_Functions);
        menuFile->addAction(actionLoad_Team);
        menuFile->addAction(actionReset_Database);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAdmin->setText(QApplication::translate("MainWindow", "Admin Login", nullptr));
        actionLogOut->setText(QApplication::translate("MainWindow", "Log Out...", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionAdmin_Functions->setText(QApplication::translate("MainWindow", "Admin Functions", nullptr));
        actionLoad_Team->setText(QApplication::translate("MainWindow", "Load Team", nullptr));
        actionReset_Database->setText(QApplication::translate("MainWindow", "Reset Database", nullptr));
        show_Teams->setText(QApplication::translate("MainWindow", "3. Show Teams", nullptr));
        show_NFCNorth->setText(QApplication::translate("MainWindow", "7. Show NFC North", nullptr));
        show_AFC_Teams->setText(QApplication::translate("MainWindow", "5. Show AFC Teams", nullptr));
        show_NFC_Teams->setText(QApplication::translate("MainWindow", "6. Show NFC Teams", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Plan Vacation", nullptr));
        label->setText(QString());
        show_Stadiums->setText(QApplication::translate("MainWindow", "4. Show Stadiums", nullptr));
        show_StadiumsByDate->setText(QApplication::translate("MainWindow", "8. Stadiums by Date", nullptr));
        show_openRoof->setText(QApplication::translate("MainWindow", "9. Open Roof", nullptr));
        show_SeatingCapacity->setText(QApplication::translate("MainWindow", "10. Seating Capacity", nullptr));
        show_Conference->setText(QApplication::translate("MainWindow", "11. Teams by Conference", nullptr));
        show_BermudaGrass->setText(QApplication::translate("MainWindow", "12. Bermuda Grass", nullptr));
        show_Selection_S->setText(QApplication::translate("MainWindow", "Show Selected Team's  Souvenirs", nullptr));
        numberLabel->setText(QString());
        show_Selection->setText(QApplication::translate("MainWindow", "Show Selected Team", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
