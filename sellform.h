#ifndef SELLFORM_H
#define SELLFORM_H

#include <QDialog>

namespace Ui {
class sellform;
}

class sellform : public QDialog
{
    Q_OBJECT

public:
    explicit sellform(QString,QWidget *parent = nullptr);
    ~sellform();
    QString username;

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::sellform *ui;
};

#endif // SELLFORM_H
