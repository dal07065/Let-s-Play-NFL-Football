#include "login.h"
#include "ui_login.h"
#include <QIcon>
#include <QtDebug>


login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("Unicorn Admin Login");
    this->setWindowIcon(QIcon(":/img/img/UnicornBarfing.png"));

    admins = getUsers();
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();

    if(checkCorrectLogin(username, password))
    {
        emit userIsAdmin();
        this->close();
    }
    else
    {
        QMessageBox::information(this, "Error", "Username and Password is not Correct");
    }
}

bool login::checkCorrectLogin(QString username, QString password)
{
    for (int i = 0; i < admins.size(); i++)
    {
        if (admins[i]->correctLogin(username, password))
        {
            return true;
        }
    }
    return false;
}

QVector<user*> login::getUsers()
{
    QVector<user*>fromFile;

    QFile file(":/txt/txt/Users.txt");

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    if (!file.exists())
    {
        return fromFile;
    }

    QTextStream in(&file);
    QString username;
    QString password;

    while (!in.atEnd())
    {
        in >> username >> password;

        fromFile.push_back(new user(username, password));
    }

    file.close();

    return fromFile;
}
