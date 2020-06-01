#include "removemembers.h"
#include "ui_removemembers.h"
#include"QMessageBox"

Removemembers::Removemembers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Removemembers)
{
    ui->setupUi(this);
}

Removemembers::~Removemembers()
{
    delete ui;
}

void Removemembers::on_Remove_clicked()
{
    QString username;
    bool flag = true;
    username = ui->lineEdit_username->text();
    Admin member(username);
    if(ui->lineEdit_username->text().isEmpty())
        try {
        throw 1;

    } catch (int a) {
        QMessageBox::critical(this,tr("Critical"),tr("Please enter the username"));
        flag = false;
    }
    if(flag)
    {
        if(member.RemoveMember(username))
            ui->Status->setText("User has been removed!!");
        else
            ui->Status->setText("Username does not exists");
    }
}
