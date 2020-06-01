#ifndef LOGIN_H
#define LOGIN_H

#include<iostream>
#include<QString>
#include<QFile>
class Login
{
    QString username,password;
public:
    Login();
    Login(QString username,QString password);
    int check(QString username, QString password);
};

#endif // LOGIN_H
