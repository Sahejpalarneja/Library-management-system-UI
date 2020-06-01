#include "admin.h"
#include<string>
Admin::Admin()
{
    ;
}
Admin::Admin(QString username)
{
 this->username = username;

}
bool Admin::AddMember(QString username)
{
    QString Uname, Upass,line;
    QStringList list;
    QFile fhandle("/home/sahejpal/LIBRARY/Login.txt");
    if(fhandle.open(QIODevice::ReadOnly))
    {
        QTextStream in(&fhandle);
        while(!in.atEnd())
        {

            line = in.readLine();
            list = line.split(' ');
            Uname = list.value(0);
            Upass = list.value(1);
            if(Uname == username)
            {
                return false;            }
            }
    }
    QFile file("/home/sahejpal/LIBRARY/Login.txt");
    if(file.open(QIODevice::WriteOnly|QIODevice::Append))
    {
        Upass = username.toUpper();
        QTextStream out(&file);
        out<<username<<' '<<Upass<<endl;
    }
    file.close();
    return true;

}
bool Admin::RemoveMember(QString username)
{
    bool flag = false;
    QString temp,line,password;
    QStringList list;
    QFile fhandle("/home/sahejpal/LIBRARY/Login.txt");
    if(fhandle.open(QIODevice::ReadOnly))
    {
        QTextStream in(&fhandle);
        while(!in.atEnd())
        {
            QFile file("/home/sahejpal/LIBRARY/temp.txt");
            line = in.readLine();
            list = line.split(' ');
            temp = list.value(0);
            password = list.value(1);
            if(temp == username)
            {
                flag = true;
                continue;
            }
            else
            {
                if(file.open(QIODevice::WriteOnly|QIODevice::Append))
                {
                    QTextStream out(&file);
                    out<<temp<<' '<<password<<endl;
                }
            }
            file.close();
        }
    }
    fhandle.close();
    remove("/home/sahejpal/LIBRARY/Login.txt");
    rename("/home/sahejpal/LIBRARY/temp.txt","/home/sahejpal/LIBRARY/Login.txt");
    return flag;

}
bool Admin::AddBooks(QString name,QString author)
{
    bool flag = false;
    QString temp,temp2,line;
    int number;
    QStringList list;
    name = name.toUpper();
    author = author.toUpper();
    QFile fhandle("/home/sahejpal/LIBRARY/Books.txt");
    if(fhandle.open(QIODevice::ReadOnly))
    {
        QTextStream in(&fhandle);
        while(!in.atEnd())
        {
            line = in.readLine();
            list = line.split(':');
            temp = list.value(0);
            temp2 = list.value(1);
            number = (list.value(2)).toInt();
            QFile file("/home/sahejpal/LIBRARY/temp.txt");
            QTextStream out(&file);
            if(name == temp)
            {
                QFile file("/home/sahejpal/LIBRARY/temp.txt");
                QTextStream out(&file);
                number = number+1;
                if(file.open(QIODevice::Append))
                {
                    out<<temp<<':'<<temp2<<':'<<number<<endl;
                    flag = true;
                }
                file.close();
            }
            else
            {
                 QFile file("/home/sahejpal/LIBRARY/temp.txt");
                 QTextStream out(&file);
                 if(file.open(QIODevice::Append))
                   out<<temp<<':'<<temp2<<':'<<number<<endl;
            }
            file.close();
        }
    }
    fhandle.close();
    QFile file("/home/sahejpal/LIBRARY/temp.txt");
    QTextStream out(&file);
    if(!flag && file.open(QIODevice::Append))
    {

        out<<name<<':'<<author<<':'<<'1'<<endl;
        flag = false;

    }
    file.close();
    remove("/home/sahejpal/LIBRARY/Books.txt");
    rename("/home/sahejpal/LIBRARY/temp.txt","/home/sahejpal/LIBRARY/Books.txt");
    return flag;

}
