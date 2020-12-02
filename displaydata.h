#ifndef DISPLAYDATA_H
#define DISPLAYDATA_H

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
class DisplayData;
}

class DisplayData : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Class Constructor
     * @param parent: QWidget pointer
     *
     * Function to set up the UI for the trip info page
     */
    explicit DisplayData(QString str="" , QWidget *parent = nullptr);

    /**
     *  @brief Class Destructor
     */
    ~DisplayData();
signals:
    void backToCustomVacation();
private slots:
    /**
     * @brief Function to let the FAN plan another trip
     *
     * After the fan presses "Delete Trip", the current trip will be deleted,
     *  and fan will be redirected to the plan trip page.
     */
    void on_pushButton_clicked();
private:

    Ui::DisplayData *ui;
};

#endif // DISPLAYDATA_H
