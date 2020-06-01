#ifndef ISSUE_H
#define ISSUE_H

#include <QDialog>
#include<QFile>
#include<QTextStream>
#include<member.h>

namespace Ui {
class Issue;
}

class Issue : public QDialog
{
    Q_OBJECT

public:
    explicit Issue(QWidget *parent = nullptr);
    ~Issue();

private slots:
    void on_View_clicked();

    void on_pushButton_clicked();

private:
    Ui::Issue *ui;
};

#endif // ISSUE_H
