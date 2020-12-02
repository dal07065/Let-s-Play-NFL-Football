#ifndef USER_H
#define USER_H
#include <QString>

class user
{   
private:
    // This is the data memeber that stores the username of a user
    QString username;
    // This is the data memeber that stores the password of a user
    QString password;

public:
    // Default constructor for the User object
    user();

    // Alternative Constructor for the User object. This constructor
    // allows for the username and password data to be passed
    // into it for initialization.
    user(QString username, QString password);

    // This function returns a QString containing the Users objects username
    QString getName();

    // This function returns a QString containing the Users objects password
    QString getPassword();

    // This function returns true if the passed in QStrings username and
    // password matches the User objects data members username and password
    bool correctLogin(QString username, QString password);
};

#endif // USER_H
