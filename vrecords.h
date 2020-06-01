#ifndef VRECORDS_H
#define VRECORDS_H

#include <QDialog>
#include<QFile>
#include<QTextStream>

namespace Ui {
class VRecords;
}

class VRecords : public QDialog
{
    Q_OBJECT

public:
    explicit VRecords(QWidget *parent = nullptr);
    ~VRecords();

private slots:
    void on_pushButton_clicked();

private:
    Ui::VRecords *ui;
};

#endif // VRECORDS_H
