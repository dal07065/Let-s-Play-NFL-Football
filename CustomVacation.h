#ifndef CUSTOMVACATION_H
#define CUSTOMVACATION_H
#include <QWidget>

#include <QListWidgetItem>
#include<qtimer.h>
#include<QLabel>
#include<QMessageBox>
#include<QSpinBox>
#include <QFormLayout>
#include <QLineEdit>

#include "vacationinfo.h"
#include "displaydata.h"

using namespace unicorn;
namespace Ui {
class CustomVacation;
}



/**
 * @brief The CustomVacation class
 *
 * Class to plan the trip for fan
 */
class CustomVacation : public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief Class Constructor
     * @param parent: QWidget pointer
     *
     * Set the UI for the plan trip page
     */
    explicit CustomVacation(QWidget *parent = nullptr);

    /**
     * @brief Class Destructor
     */
    ~CustomVacation();

    /**
     * @brief Function to populate the list widget with all the teams
     *
     * A list of teams is populated in the widget for fan to choose for the trip
     */
    void populateListWidget();

    /**
     * @brief Function to update the souviner items shopping cart & the list of teams for the trip
     *
     * The current list of teams in the correct order of shortest distance
     * and the shopping carts with all the items and quantity will be displayed for fan
     */
    void updateCartDistance();

    /**
     * @brief Function to check if the teams selected for the trip are valid
     * @return true if there is a starting team and there is at least 1 team for the trip
     */
    bool teamsSelected();

    /**
     * @brief Function to set the id of the current user
     * @param i: id of current user
     */
    void setUserID(int i);

    /**
     * @brief Function to apply Dijkestra between two points
     * @param teams: teams selected
     */
    void applyDijkestraTwoPoints(vector<int> teams);

    /**
     * @brief Function to apply Dijkestra recursively
     * @param teams: teams selected
     */
    void applyDijkestraRecursively(vector<int> teams);


    /**
     * @brief Function to show the vacation info for fan
     *
     * Vacation info will be shown if there is a trip currently stored for fan
     */
    void showVacationInfo();
    void showDisplayData(QString  str);



private slots:
    void on_listWidgetFirst_itemDoubleClicked(QListWidgetItem *item);
    /**
     * @brief Function to plan a trip with all teams
     *
     * After the fan presses "All Teams Trip", all teams will be selected for the trip,
     * and "new england" will be selected as the starting team
     */
    void on_allTeamPlan_clicked();
    /**
     * @brief Function to reset the UI of the plan trip page
     *
     * The UI of the plan trip page will be set to its original state
     */
    void resetUI();

    /**
     * @brief Function to add a team into the trip
     *
     * After fan presses the ">>" for Cities, the selected team will
     * be moved to the selected teams widget
     */
    void pushButtonFirst_clicked();



    /**
     * @brief Function to remove a team from the trip
     *
     * After fan presses the "<<" for Cities, the selected team will
     * be removed from the selected teams widget and put back on the
     * list of team options to add to trip
     */
    void pushButtonSecond_clicked();

    /**
     * @brief Function to add a souviner item into the trip
     *
     * After fan presses the ">>" for Food, the selected souviner item will
     * be moved to the selected souviner widget
     */
    void pushButtonSouv1_clicked();

    /**
     * @brief Function to remove a souviner item from the trip
     *
     * After fan presses the "<<" for Food, the selected souviner item will
     * be removed from the selected souviner widget and put back on the
     * list of souviner options to add to trip
     */
    void pushButtonSouv2_clicked();

    /**
     * @brief Function to set the starting team for the plan trip page
     * @param item: currently selected item
     *
     * If the item is selected as the starting team, unselect all the other team
     */
    void populateStartTeam(QListWidgetItem* item);

    /**
     * @brief Function to update the total cost for the current trip
     */
    void updateTotal();



    /**
     * @brief Function to finalize the trip for fan
     *
     * After the fan presses "Book Your Trip", the trip information will be stored into database
     * and fan will be redirected to a view trip page
     */
    void on_bookYourTrip_clicked();


    /**
     * @brief Function to perform DFS
     *
     * @param vertex: to start dfs from
     */
    void performDFS(int vert);



    /**
     * @brief Function to perform BFS
     *
     * @param vertex: to start BFS from
     */
    void performBFS(int vert);



    /**
     * @brief Function to call performDFS function
     */
    void on_pushButton_clicked();


    /**
     * @brief Function to call performBFS function
     */
    void on_pushButton_2_clicked();


    /**
     * @brief Function to calculate MST
     */
    void on_pushButton_3_clicked();





private:
std::vector<Team> selectedTeams;
std::vector<int> associatedDistance;
    Ui::CustomVacation *ui;
    VacationInfo* currentVacation;
    DisplayData* dataToBeDisplayed;
    int userID; // id of the currrent user

};

#endif // CUSTOMVACATION_H
