#ifndef REMOVEMEMBERS_H
#define REMOVEMEMBERS_H

#include <QDialog>
#include<admin.h>

namespace Ui {
class Removemembers;
}

class Removemembers : public QDialog
{
    Q_OBJECT

public:
    explicit Removemembers(QWidget *parent = nullptr);
    ~Removemembers();

private slots:
    void on_Remove_clicked();

private:
    Ui::Removemembers *ui;
};

#endif // REMOVEMEMBERS_H
