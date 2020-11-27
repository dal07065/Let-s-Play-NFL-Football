#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QIcon>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileInfo>
#include <QMessageBox>
#include <vector>
#include <QString>
using std::vector;
#include <QPair>

#include "team.h"

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
    void loadTeamData(int index);

private slots:
    void on_comboBox_Team_Selection_activated(int index);

private:
    Ui::adminWindow *ui;
    QSqlDatabase data;
    vector<QPair<int, QString>> nameAndIndex;
};

#endif // ADMINWINDOW_H
