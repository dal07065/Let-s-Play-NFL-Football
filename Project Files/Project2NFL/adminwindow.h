#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QIcon>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileInfo>
#include <QMessageBox>

namespace Ui {
class adminWindow;
}

class adminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit adminWindow(QWidget *parent = nullptr);
    ~adminWindow();
    void loadTeams();

private:
    Ui::adminWindow *ui;
    QSqlDatabase data;

};

#endif // ADMINWINDOW_H
