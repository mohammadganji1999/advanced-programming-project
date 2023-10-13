#ifndef USERSELLSHOW_H
#define USERSELLSHOW_H
#include"QString"
#include <QDialog>

namespace Ui {
class usersellshow;
}

class usersellshow : public QDialog
{
    Q_OBJECT

public:
    explicit usersellshow(QString,QWidget *parent = nullptr);
    ~usersellshow();
    QString username;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::usersellshow *ui;
};

#endif // USERSELLSHOW_H
