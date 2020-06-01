#ifndef VREQUESTS_H
#define VREQUESTS_H

#include <QDialog>

namespace Ui {
class VRequests;
}

class VRequests : public QDialog
{
    Q_OBJECT

public:
    explicit VRequests(QWidget *parent = nullptr);
    ~VRequests();

private slots:
    void on_pushButton_clicked();

private:
    Ui::VRequests *ui;
};

#endif // VREQUESTS_H
