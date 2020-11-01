#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QIcon>

adminWindow::adminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Unicorn Admin Functions");
    this->setWindowIcon(QIcon(":/img/img/UnicornBarfing.png"));
}

adminWindow::~adminWindow()
{
    delete ui;
}
