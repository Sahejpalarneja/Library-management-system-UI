#include "changepassword.h"
#include "ui_changepassword.h"
#include"QMessageBox"

ChangePassword::ChangePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
}

ChangePassword::~ChangePassword()
{
    delete ui;
}

void ChangePassword::on_pushButton_clicked()
{
    QString username,pass,pass2;
    bool flag = true;
    username = ui->lineEdit_username->text();
    pass = ui->lineEdit_pass->text();
    pass2 = ui->lineEdit_pass2->text();
    Member password;
    try {
        if(ui->lineEdit_username->text().isEmpty() || ui->lineEdit_pass->text().isEmpty()||ui->lineEdit_pass2->text().isEmpty())
            throw 1;
    } catch (int a) {
        QMessageBox::critical(this,tr("Critical!!"),tr("Please enter all the fields"));
       flag = false;
    }
    if(flag)
    {
        if(pass == pass2)
        {
            if(password.ChangePassword(username,pass))
                ui->Status->setText("Password has been Changed");
            else
                ui->Status->setText("User doesn't exist");
        }
        else
            QMessageBox::warning(this,tr("Warning!!"),tr("The passwords don't match"));
    }




}
