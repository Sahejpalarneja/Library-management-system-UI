#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QDialog>
#include<addmembers.h>
#include<removemembers.h>
#include<addbooks.h>
#include<vrequests.h>
#include<vrecords.h>
namespace Ui {
class AdminMenu;
}

class AdminMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AdminMenu(QWidget *parent = nullptr);
    ~AdminMenu();

private slots:
    void on_Logout_clicked();

    void on_Add_clicked();

    void on_Remove_clicked();

    void on_Books_clicked();

    void on_Requests_clicked();

    void on_Record_clicked();

private:
    Ui::AdminMenu *ui;
};

#endif // ADMINMENU_H
