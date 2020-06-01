#ifndef MEMBERMENU_H
#define MEMBERMENU_H

#include <QDialog>
#include<changepassword.h>
#include<issue.h>
#include<return.h>
#include<requets.h>
namespace Ui {
class MemberMenu;
}

class MemberMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MemberMenu(QWidget *parent = nullptr);
    ~MemberMenu();

private slots:
    void on_Logout_clicked();

    void on_Change_clicked();

    void on_Issue_clicked();

    void on_Return_clicked();

    void on_Request_clicked();

    
private:
    Ui::MemberMenu *ui;
};

#endif // MEMBERMENU_H
