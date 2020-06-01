#include "adminmenu.h"
#include "ui_adminmenu.h"

AdminMenu::AdminMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminMenu)
{
    ui->setupUi(this);
}

AdminMenu::~AdminMenu()
{
    delete ui;
}

void AdminMenu::on_Logout_clicked()
{
    exit(0);
}

void AdminMenu::on_Add_clicked()
{

    AddMembers member;
    member.setModal(true);
    member.exec();
}

void AdminMenu::on_Remove_clicked()
{

    Removemembers member;
    member.setModal(true);
    member.exec();
}

void AdminMenu::on_Books_clicked()
{
    AddBooks book;
    book.setModal(true);
    book.exec();
}

void AdminMenu::on_Requests_clicked()
{
    VRequests request;
    request.setModal(true);
    request.exec();
}


void AdminMenu::on_Record_clicked()
{
    VRecords record;
    record.setModal(true);
    record.exec();
}
