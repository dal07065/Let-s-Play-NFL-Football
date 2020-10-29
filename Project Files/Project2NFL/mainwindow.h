#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTableView>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_show_Data_clicked();


private:
    Ui::MainWindow *ui;
    QString teamName;
    QString stadiumName;
    QSqlDatabase data;
};
#endif // MAINWINDOW_H
