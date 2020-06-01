#include "addbooks.h"
#include "ui_addbooks.h"
#include"QMessageBox"
AddBooks::AddBooks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBooks)
{
    ui->setupUi(this);
}

AddBooks::~AddBooks()
{
    delete ui;
}

void AddBooks::on_Add_clicked()
{
    QString name,author;
    bool flag= true;
    name =  ui->lineEdit_name->text();
    author = ui->lineEdit_author->text();
    Admin book;
    if(ui->lineEdit_name->text().isEmpty() || ui->lineEdit_author->text().isEmpty())
        try {
        throw 1;
    } catch (int a) {
    QMessageBox::critical(this,tr("Critical"),tr("Enter the name of the author and username"));
    flag = false;
    }
    if(flag)
    {
        if(book.AddBooks(name,author))
            ui->Status->setText("The Number has been updated");
        else
            ui->Status->setText("New Book has been added!!");
    }
}
