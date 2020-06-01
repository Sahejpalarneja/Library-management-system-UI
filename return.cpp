#include "return.h"
#include "ui_return.h"

Return::Return(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Return)
{
    ui->setupUi(this);
}

Return::~Return()
{
    delete ui;
}

void Return::on_pushButton_clicked()
{
    bool flag = true;
    QString username,name,author;
    username = ui->lineEdit_username->text();
    name = ui->lineEdit_name->text();
    author = ui->lineEdit_author->text();
    Member member;
    try {
        if(ui->lineEdit_username->text().isEmpty() || ui->lineEdit_name->text().isEmpty() || ui->lineEdit_author->text().isEmpty())
            throw 1;
    } catch (int a) {
        QMessageBox::critical(this,tr("Critical!!"),tr(" Please enter all the fields"));
        flag = false;
}
    if(flag)
    {
        if(member.Return(username,name,author))
            QMessageBox::information(this,tr("Success!"),tr("The book has been returned"));
        else
            QMessageBox::warning(this,tr("Error"),tr("Book does not exist in the records"));
    }

}
