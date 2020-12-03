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
#include <QDebug>
#include "team.h"

namespace Ui {
class adminWindow;
}


/**
 * @brief The adminWindow class
 *
 * Class to log in as admin and edit data
 */


class adminWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Class Constructor
     * @param parent: QWidget pointer
     *
     * Set the UI for the plan trip page
     */
    explicit adminWindow(QWidget *parent = nullptr);
    /**
     * @brief Class Destructor
     */
    ~adminWindow();
    /**
     * @brief This function loads all of the NFL Teams from the database into combo box comboBox_Team_Selection
     */
    void loadTeams();

    // This function loads all stadium and souvenir data from the
    // database into the respective feilds
    void loadTeamData(int index);

private slots:
   void on_comboBox_Team_Selection_activated(int index);

    void on_comboBox_SelectSouvenir_activated(const QString &arg1);

    void on_pushButton_SelectSouvenir_SetPrice_clicked();

    void on_pushButton_SelectSouvenir_Delete_clicked();

    void on_pushButton_NewSouvenir_Add_clicked();

    void on_pushButton_NewStadium_Add_clicked();

    void on_pushButton_SelectStadium_SetCapacity_clicked();

private:
    Ui::adminWindow *ui;
    QSqlDatabase data;
    vector<QPair<int, QString>> nameAndIndex;
};

#endif // ADMINWINDOW_H
