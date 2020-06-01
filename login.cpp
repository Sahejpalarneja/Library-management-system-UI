#include "login.h"
#include<QTextStream>
Login::Login()
{
    ;
}
Login::Login(QString username,QString password)
{
    this->username = username;
    this->password = password;
}
int Login::check(QString username, QString password)
{
    //bool flag = false;
    QString line,Uname,Upass;
    QStringList list;
    QFile fhandle("/home/sahejpal/LIBRARY/Login.txt");
    //return "pale";
    if(fhandle.open(QIODevice::ReadOnly))
    {

        QTextStream in(&fhandle);
        while(!in.atEnd())
        {

            line = in.readLine();
            list = line.split(' ');
            Uname = list.value(0);
            Upass = list.value(1);
            if(Uname == username && password ==Upass)
                return 1;
        }
    }
    fhandle.close();
    char *aname = new char[5];
    strcpy(aname,"admin");
    char *apass = new char[8];
    strcpy(apass,"password");
    if(username == aname && password == apass)
        return 0;
    else
        return -1;
    delete [] aname;
    delete [] apass;
}
