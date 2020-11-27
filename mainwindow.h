#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTableView>
#include <QVariant>
#include <QtDebug>
#include <QSqlTableModel>
#include <team.h>
#include <CustomVacation.h>

QT_BEGIN_NAMESPACE
using namespace unicorn;
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    // This function will change all of the adminFuncs features visiblility
    // to true.
    void userIsAdmin();

private slots:

    //void on_show_Data_clicked();

    void on_show_Teams_clicked();

    void on_show_NFC_Teams_clicked();
    void on_show_AFC_Teams_clicked();
    void on_show_NFCNorth_clicked();
    void on_show_Stadiums_clicked();
    void on_show_StadiumsByDate_clicked();
    void on_show_Selection_clicked();
    void on_show_openRoof_clicked();
    void on_show_SeatingCapacity_clicked();
    void on_show_Conference_clicked();
    void on_show_BermudaGrass_clicked();
    void on_show_Selection_S_clicked();

    void on_actionExit_triggered();

    void on_actionAdmin_triggered();

    void on_actionLogOut_triggered();


    void on_pushButton_clicked();

    void on_actionAdmin_Functions_triggered();

private:
    Ui::MainWindow *ui;
    QString teamName;
    QString stadiumName;
    QSqlDatabase data;
};
#endif // MAINWINDOW_H
