#include "addmembers.h"
#include "ui_addmembers.h"
#include"QMessageBox"

AddMembers::AddMembers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMembers)
{
    ui->setupUi(this);
}

AddMembers::~AddMembers()
{
    delete ui;
}

void AddMembers::on_pushButton_clicked()
{
    QString username;
    bool flag = true;
    username = ui->lineEdit_username->text();
    Admin admin(username);
    try {
        if(ui->lineEdit_username->text().isEmpty())
            throw 1;
    } catch (int a)
    {
     QMessageBox::critical(this,tr("Critical"),tr("Please enter the value"));
     flag = false;
    }
    if(flag)
    {
        if(admin.AddMember(username))
        {
            QString pass =username.toUpper();
            ui->Status->setText("User has been added.\n Username:"+username+"\n Password:"+pass+"\n");
        }
        else
            QMessageBox::warning(this,tr("Error"),tr("The username alreay exists"));
    }
}
