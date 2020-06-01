#ifndef REQUETS_H
#define REQUETS_H

#include <QDialog>
#include<member.h>
#include<QFile>
#include<QTextStream>
#include"QMessageBox"

namespace Ui {
class Requets;
}

class Requets : public QDialog
{
    Q_OBJECT

public:
    explicit Requets(QWidget *parent = nullptr);
    ~Requets();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Requets *ui;
};

#endif // REQUETS_H
