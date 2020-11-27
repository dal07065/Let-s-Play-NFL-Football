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
 * Class to plan the trip for tourist
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
     * A list of teams is populated in the widget for tourist to choose for the trip
     */
    void populateListWidget();

    /**
     * @brief Function to update the food items shopping cart & the list of teams for the trip
     *
     * The current list of teams in the correct order of shortest distance
     * and the shopping carts with all the items and quantity will be displayed for tourist
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
     * @brief Function to show the vacation info for tourist
     *
     * Vacation info will be shown if there is a trip currently stored for tourist
     */
    void showVacationInfo();
    void showDisplayData(QString  str);


private slots:
void on_listWidgetFirst_itemDoubleClicked(QListWidgetItem *item);

/**
 * @brief Function to reset the UI of the plan trip page
 *
 * The UI of the plan trip page will be set to its original state
 */
void resetUI();

/**
 * @brief Function to add a team into the trip
 *
 * After tourist presses the ">>" for Cities, the selected team will
 * be moved to the selected teams widget
 */
void pushButtonFirst_clicked();

/**
 * @brief Function to remove a team from the trip
 *
 * After tourist presses the "<<" for Cities, the selected team will
 * be removed from the selected teams widget and put back on the
 * list of team options to add to trip
 */
void pushButtonSecond_clicked();

/**
 * @brief Function to add a food item into the trip
 *
 * After tourist presses the ">>" for Food, the selected food item will
 * be moved to the selected food widget
 */
void pushButtonSouv1_clicked();

/**
 * @brief Function to remove a food item from the trip
 *
 * After tourist presses the "<<" for Food, the selected food item will
 * be removed from the selected food widget and put back on the
 * list of food options to add to trip
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
 * @brief Function to plan a trip with all teams
 *
 * After the tourist presses "All Cities Trip", all teams will be selected for the trip,
 * and "Berlin" will be selected as the starting team
 */
void on_thirteenTeamPlan_clicked();

/**
 * @brief Function to finalize the trip for tourist
 *
 * After the tourist presses "Book Your Trip", the trip information will be stored into database
 * and tourist will be redirected to a view trip page
 */
void on_bookYourTrip_clicked();

/**
 * @brief Function to plan a trip with a specific number of teams
 *
 * After the tourist has selected the number of teams they want to visit, the list of teams in the
 * correct order of shortest distance will be generated for tourist, with "Paris" as the starting team
 */
void on_NumberTripPushButton_clicked();

void performDFS(int vert);
void performBFS(int vert);

void on_pushButton_clicked();

void on_pushButton_2_clicked();

private:
std::vector<Team> selectedTeams;
    Ui::CustomVacation *ui;
    VacationInfo* currentVacation;
    DisplayData* dataToBeDisplayed;
    int userID; // id of the currrent user

};

#endif // CUSTOMVACATION_H
