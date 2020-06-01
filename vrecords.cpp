#include "vrecords.h"
#include "ui_vrecords.h"

VRecords::VRecords(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VRecords)
{
    ui->setupUi(this);
}

VRecords::~VRecords()
{
    delete ui;
}

void VRecords::on_pushButton_clicked()
{
    QString line;
    QFile fhandle("/home/sahejpal/LIBRARY/Records.txt");
    if(fhandle.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream in(&fhandle);
        ui->textBrowser->setText(in.readAll());
    }

}
