#include "displaydata.h"
#include "ui_displaydata.h"

DisplayData::DisplayData(QString str,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayData)
{
    ui->setupUi(this);

    QWidget * container1 = new QWidget;
    QFormLayout *formLayout1 = new QFormLayout();

    QHBoxLayout * hBoxLayout1= new QHBoxLayout;
    QLabel *txtLabel = new QLabel;
    txtLabel->setText(str);
    hBoxLayout1->addWidget(txtLabel);
    formLayout1->addRow(hBoxLayout1);
    ui->scrollArea->setWidget(container1);
    container1->setLayout(formLayout1);
}

DisplayData::~DisplayData()
{
    delete ui;
}
void DisplayData::on_pushButton_clicked()
{


   // emit backToCustomVacation();
    this->close();
}
