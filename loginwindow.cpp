#include "loginwindow.h"
#include "ui_loginwindow.h"
#include"QMessageBox"
#include<QPixmap>
#include<login.h>


LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}



void LoginWindow::on_LoginButton_clicked()
{
    QString username,password;
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();
    Login user(username,password);
    if(user.check(username,password) == 1)
    {

        MemberMenu menu;
        menu.setModal(true);
        menu.exec();
    }
    else if(user.check(username,password) == 0)
    {
        AdminMenu menu;
        menu.setModal(true);
        menu.exec();
    }

    else
    {
        QMessageBox::warning(this,tr("Error"),tr("Password or useraname is wrong"));
    }

}
