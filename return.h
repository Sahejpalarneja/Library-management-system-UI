#ifndef RETURN_H
#define RETURN_H

#include <QDialog>
#include<member.h>
#include<QFile>
#include<QTextStream>
#include"QMessageBox"
namespace Ui {
class Return;
}

class Return : public QDialog
{
    Q_OBJECT

public:
    explicit Return(QWidget *parent = nullptr);
    ~Return();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Return *ui;
};

#endif // RETURN_H
