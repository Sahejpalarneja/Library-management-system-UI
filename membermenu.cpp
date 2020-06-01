#include "membermenu.h"
#include "ui_membermenu.h"

MemberMenu::MemberMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MemberMenu)
{
    ui->setupUi(this);
}

MemberMenu::~MemberMenu()
{
    delete ui;
}

void MemberMenu::on_Logout_clicked()
{
    exit(0);
}

void MemberMenu::on_Change_clicked()
{
    ChangePassword password;
    password.setModal(true);
    password.exec();
}


void MemberMenu::on_Issue_clicked()
{
    Issue issue;
    issue.setModal(true);
    issue.exec();
}

void MemberMenu::on_Return_clicked()
{
    Return back;
    back.setModal(true);
    back.exec();

}

void MemberMenu::on_Request_clicked()
{
    Requets request;
    request.setModal(true);
    request.exec();
}

