#ifndef BULDING_H
#define BULDING_H

#include <QWidget>

namespace Ui {
class bulding;
}

class bulding : public QWidget
{
    Q_OBJECT

public:
    explicit bulding(QString,QWidget *parent = nullptr);
    ~bulding();
    QString username;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::bulding *ui;
};

#endif // BULDING_H
