#include "user.h"

user::user()
{
    username = "guest";
    password = "guest";
}

user::user(QString username, QString password)
{
    this->username = username;
    this->password = password;
};

QString user::getName()
{
    return username;
}

QString user::getPassword()
{
    return password;
}

bool user::correctLogin(QString username, QString password)
{
    return (this->password == password) && (this->username == username);
}
