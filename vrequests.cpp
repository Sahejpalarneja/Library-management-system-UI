#include "vrequests.h"
#include "ui_vrequests.h"
#include<QFile>
#include<QTextStream>
VRequests::VRequests(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VRequests)
{
    ui->setupUi(this);
}

VRequests::~VRequests()
{
    delete ui;
}

void VRequests::on_pushButton_clicked()
{
    QString line,name,author;
    QStringList list;
    QFile fhandle("/home/sahejpal/LIBRARY/Requests.txt");
    if(fhandle.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream in(&fhandle);
        ui->textBrowser->setText(in.readAll());
   }

    fhandle.close();
}
