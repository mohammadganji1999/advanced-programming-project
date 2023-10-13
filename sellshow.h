#ifndef SELLSHOW_H
#define SELLSHOW_H
#include"QString"

#include <QWidget>

namespace Ui {
class sellShow;
}

class sellShow : public QWidget
{
    Q_OBJECT

public:
    explicit sellShow(QString,QWidget *parent = nullptr);
    ~sellShow();
    QString username;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::sellShow *ui;
};

#endif // SELLSHOW_H
