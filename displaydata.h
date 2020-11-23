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
    explicit DisplayData(QString str="" , QWidget *parent = nullptr);
    ~DisplayData();
signals:
   // void backToCustomVacation();
private slots:
    /**
     * @brief Function to let the tourist plan another trip
     *
     * After the tourist presses "Delete Trip", the current trip will be deleted,
     *  and tourist will be redirected to the plan trip page.
     */
    void on_pushButton_clicked();
private:

    Ui::DisplayData *ui;
};

#endif // DISPLAYDATA_H
