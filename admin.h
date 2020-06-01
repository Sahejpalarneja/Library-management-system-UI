#ifndef ADMIN_H
#define ADMIN_H
#include<QString>
#include<QFile>
#include"QTextStream"
class Admin
{
    QString username;
public:
    Admin();
    Admin(QString username);
    bool AddMember(QString username);
    bool RemoveMember(QString username);
    bool AddBooks(QString name,QString author);
};

#endif // ADMIN_H
