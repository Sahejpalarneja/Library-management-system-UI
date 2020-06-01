#include "issue.h"
#include "ui_issue.h"
#include"QMessageBox"

Issue::Issue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Issue)
{
    ui->setupUi(this);
}

Issue::~Issue()
{
    delete ui;
}

void Issue::on_View_clicked()
{
    QString line;
    QFile fhandle("/home/sahejpal/LIBRARY/Books.txt");
    if(fhandle.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream in(&fhandle);
        ui->textBrowser->setText(in.readAll());
    }
}


void Issue::on_pushButton_clicked()
{
    QString name,username;
    bool flag = true;
    name = ui->lineEdit_name->text();
    username = ui->lineEdit_username->text();
    Member issue;
    try {
        if(ui->lineEdit_name->text().isEmpty())
            throw 1;
    } catch (int a) {
        QMessageBox::critical(this,tr("Critical!"),tr("Enter the name"));
        flag = false;
    }
    if(flag)
    {
        if(issue.Issue(username,name))
            QMessageBox::information(this,tr("Sucess"),tr("The book has been issued"));
        else
            QMessageBox::warning(this,tr("Error"),tr("The book is not avaiable"));
    }

}
