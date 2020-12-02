#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "user.h"
#include <QLineEdit>
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private:
    Ui::login *ui;

    // This is the data memeber that stores all of the current user names and passwords
    // that are parsed from the "User.txt" file
    QVector<user*> admins;

    //This is a function to check to see if the user entered in the correct username
    //and password.
    bool checkCorrectLogin(QString username, QString Password);

    // This function adds new user name and password to the "User.txt" file
    void saveUsersToFile();

    // This functions reads in all of the user names and passwords from "User.txt"
    // and returns them in a QVector of User pointers.
    QVector<user*> getUsers();
signals:
    // This function sends a signal to mainWindow that
    // the current user is an admin and causes mainWindow
    // to exicute the function userIsAdmin()
    void userIsAdmin();



private slots:
    void on_pushButton_Login_clicked();
};

#endif // LOGIN_H
