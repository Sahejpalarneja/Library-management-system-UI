#ifndef ADDMEMBERS_H
#define ADDMEMBERS_H

#include <QDialog>
#include"admin.h"

namespace Ui {
class AddMembers;
}

class AddMembers : public QDialog
{
    Q_OBJECT

public:
    explicit AddMembers(QWidget *parent = nullptr);
    ~AddMembers();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddMembers *ui;
};

#endif // ADDMEMBERS_H
