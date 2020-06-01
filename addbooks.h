#ifndef ADDBOOKS_H
#define ADDBOOKS_H

#include <QDialog>
#include<admin.h>
namespace Ui {
class AddBooks;
}

class AddBooks : public QDialog
{
    Q_OBJECT

public:
    explicit AddBooks(QWidget *parent = nullptr);
    ~AddBooks();

private slots:
    void on_Add_clicked();

private:
    Ui::AddBooks *ui;
};

#endif // ADDBOOKS_H
