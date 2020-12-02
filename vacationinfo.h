#ifndef VACATIONINFO_H
#define VACATIONINFO_H

#include <QWidget>
#include "team.h"
#include <QListWidgetItem>
#include<qtimer.h>
#include<QLabel>
#include<QMessageBox>
#include<QSpinBox>
#include <QFormLayout>
#include <QLineEdit>
using namespace std;
using namespace unicorn;
namespace Ui {
class VacationInfo;
}
/**
 * @brief The VacationInfo class
 * is used to display the trip for tourist
 */
class VacationInfo : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Class Constructor
     * @param parent: QWidget pointer
     *
     * Function to set up the UI for the trip info page
     */
    explicit VacationInfo(QWidget *parent = nullptr);

    /**
     *  @brief Class Destructor
     */
    ~VacationInfo();

signals:
    void backToCustomVacation();
private slots:
    /**
     * @brief Function to let the fan plan another trip
     *
     * After the tourist presses "Delete Trip", the current trip will be deleted,
     *  and fan will be redirected to the plan trip page.
     */
    void on_pushButton_clicked();


private:
    Ui::VacationInfo *ui;
    int userID;
    int vacationID;
};

#endif // VACATIONINFO_H
