/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_userName;
    QLineEdit *lineEdit_Username;
    QLabel *label_password;
    QLineEdit *lineEdit_Password;
    QPushButton *pushButton_Login;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(400, 300);
        label = new QLabel(login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 301, 61));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/Team Logo.png")));
        label->setScaledContents(true);
        groupBox = new QGroupBox(login);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 90, 311, 181));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 30, 271, 115));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_userName = new QLabel(widget);
        label_userName->setObjectName(QString::fromUtf8("label_userName"));

        verticalLayout->addWidget(label_userName);

        lineEdit_Username = new QLineEdit(widget);
        lineEdit_Username->setObjectName(QString::fromUtf8("lineEdit_Username"));

        verticalLayout->addWidget(lineEdit_Username);

        label_password = new QLabel(widget);
        label_password->setObjectName(QString::fromUtf8("label_password"));

        verticalLayout->addWidget(label_password);

        lineEdit_Password = new QLineEdit(widget);
        lineEdit_Password->setObjectName(QString::fromUtf8("lineEdit_Password"));
        lineEdit_Password->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEdit_Password);

        pushButton_Login = new QPushButton(widget);
        pushButton_Login->setObjectName(QString::fromUtf8("pushButton_Login"));

        verticalLayout->addWidget(pushButton_Login);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", nullptr));
        label->setText(QString());
        groupBox->setTitle(QApplication::translate("login", "Sign-In:", nullptr));
        label_userName->setText(QApplication::translate("login", "Username:", nullptr));
        lineEdit_Username->setText(QString());
        label_password->setText(QApplication::translate("login", "Password: ", nullptr));
        pushButton_Login->setText(QApplication::translate("login", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
