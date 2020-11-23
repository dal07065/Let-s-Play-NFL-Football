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
    // This function loads all of the NFL Teams from the database
    // into combo box comboBox_Team_Selection
    void loadTeams();

    // This function loads all stadium and souvenir data from the
    // database into the respective feilds
    void loadTeamData();

private:
    Ui::adminWindow *ui;
    QSqlDatabase data;

};

#endif // ADMINWINDOW_H
