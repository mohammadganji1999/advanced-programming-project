#ifndef USERRENTSHOW_H
#define USERRENTSHOW_H
#include "QString"
#include <QDialog>

namespace Ui {
class userrentshow;
}

class userrentshow : public QDialog
{
    Q_OBJECT

public:
    explicit userrentshow(QString,QWidget *parent = nullptr);
    ~userrentshow();
    QString username;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::userrentshow *ui;
};

#endif // USERRENTSHOW_H
