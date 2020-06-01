#ifndef MEMBER_H
#define MEMBER_H

#include<QString>
#include<QFile>
#include"QTextStream"
#include<admin.h>
class Member:public Admin
{
public:
    Member();
    bool ChangePassword(QString username,QString password);
    bool Issue(QString username,QString name);
    void Record(QString username,QString name);
    bool Return(QString username,QString name,QString author);
};

#endif // MEMBER_H
