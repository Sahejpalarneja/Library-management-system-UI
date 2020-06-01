#include "member.h"

Member::Member()
{
    ;
}
bool Member::ChangePassword(QString username, QString password)
{
    QString Uname, Upass,line;
    bool flag =false;
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
            Uname = list.value(0);
            Upass = list.value(1);
            if(Uname == username)
            {
                if(file.open(QIODevice::WriteOnly|QIODevice::Append))
                   {
                    QTextStream out(&file);
                    out<<username<<' '<<password<<endl;
                    flag = true;
                   }
                file.close();
            }

            else
            {
                QFile file("/home/sahejpal/LIBRARY/temp.txt");
                QTextStream out(&file);
                if(file.open(QIODevice::Append))
                  out<<Uname<<' '<<Upass<<endl;
            }
           file.close();
       }
     }
    fhandle.close();
    remove("/home/sahejpal/LIBRARY/Login.txt");
    rename("/home/sahejpal/LIBRARY/temp.txt","/home/sahejpal/LIBRARY/Login.txt");
    return flag;
}
void Member::Record(QString username, QString name)
{
    QFile fhandle("/home/sahejpal/LIBRARY/Records.txt");
    if(fhandle.open(QIODevice::WriteOnly|QIODevice::Append))
    {
        QTextStream out(&fhandle);
        out<<username<<'-'<<name<<endl;
    }
}
bool Member::Issue(QString username,QString name)
{
    bool flag = false;
    QString temp,author,line;
    int number;
    QStringList list;
    name = name.toUpper();
    QFile fhandle("/home/sahejpal/LIBRARY/Books.txt");
    if(fhandle.open(QIODevice::ReadOnly))
    {
        QTextStream in(&fhandle);
        while(!in.atEnd())
        {
            line = in.readLine();
            list = line.split(':');
            temp = list.value(0);
            author = list.value(1);
            number = (list.value(2)).toInt();
            QFile file("/home/sahejpal/LIBRARY/temp.txt");
            QTextStream out(&file);
            if(name == temp)
            {
                if(number > 0)
                {
                    QFile file("/home/sahejpal/LIBRARY/temp.txt");
                    QTextStream out(&file);
                    number = number-1;
                    if(file.open(QIODevice::Append))
                    {
                        out<<temp<<':'<<author<<':'<<number<<endl;
                        flag = true;
                        Record(username,name);
                    }
                    file.close();
                }
                else
                    return false;
            }
            else
            {
                 QFile file("/home/sahejpal/LIBRARY/temp.txt");
                 QTextStream out(&file);
                 if(file.open(QIODevice::Append))
                   out<<temp<<':'<<author<<':'<<number<<endl;
            }
            file.close();
        }
    }
    fhandle.close();
    remove("/home/sahejpal/LIBRARY/Books.txt");
    rename("/home/sahejpal/LIBRARY/temp.txt","/home/sahejpal/LIBRARY/Books.txt");
    return flag;

}
bool Member::Return(QString username, QString name,QString author)
{
    name = name.toUpper();
    author = author.toUpper();
    bool flag = false;
    QString Uname,line,Ubook;
    QStringList list;
    QFile fhandle("/home/sahejpal/LIBRARY/Records.txt");
    if(fhandle.open(QIODevice::ReadOnly))
    {
        QTextStream in(&fhandle);
        while(!in.atEnd())
        {
            QFile file("/home/sahejpal/LIBRARY/temp2.txt");
            line = in.readLine();
            list = line.split('-');
            Uname = list.value(0);
            Ubook = list.value(1);
            if(Uname == username && Ubook == name)
            {
                Member member;
                member.AddBooks(name,author);
                flag = true;
            }
            else
            {
                QTextStream out(&file);
                if(file.open(QIODevice::Append))
                {
                    out<<Uname<<'-'<<Ubook<<endl;

                }

            }
             file.close();
        }
    }
    fhandle.close();
    remove("/home/sahejpal/LIBRARY/Records.txt");
    rename("/home/sahejpal/LIBRARY/temp2.txt","/home/sahejpal/LIBRARY/Records.txt");
    return flag;
}

