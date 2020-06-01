#include "requets.h"
#include "ui_requets.h"

Requets::Requets(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Requets)
{
    ui->setupUi(this);
}

Requets::~Requets()
{
    delete ui;
}

void Requets::on_pushButton_clicked()
{ 
    bool flag = true;
    QString name,author;
    name = ui->lineEdit_name->text().toUpper();
    author = ui->lineEdit_author->text().toUpper();
    try {
        if(ui->lineEdit_name->text().isEmpty() ||ui->lineEdit_author->text().isEmpty() )
            throw 1;
    } catch (int a) {
        QMessageBox::critical(this,tr("Critical!!"),tr("Please enter all the fields"));
        flag =false;
    }
    if(flag)
    {
        QFile fhandle("Requests.txt");
        if(fhandle.open(QIODevice::WriteOnly|QIODevice::Append))
        {
            QTextStream out(&fhandle);
            out<<name<<':'<<author<<endl;
            QMessageBox::information(this,tr("Success"),tr("The Request has been registered"));
        }
    }

}
