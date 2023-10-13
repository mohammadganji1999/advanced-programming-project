#ifndef RENTFORM_H
#define RENTFORM_H
#include"QString"
#include <QDialog>

namespace Ui {
class rentform;
}

class rentform : public QDialog
{
    Q_OBJECT

public:
    explicit rentform(QString,QWidget *parent = nullptr);
    ~rentform();
    QString username;

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::rentform *ui;
};

#endif // RENTFORM_H
