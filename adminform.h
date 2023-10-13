#ifndef ADMINFORM_H
#define ADMINFORM_H
#include<QString>

#include <QWidget>

namespace Ui {
class AdminForm;
}

class AdminForm : public QWidget
{
    Q_OBJECT

public:
    explicit AdminForm(QString,QWidget *parent = nullptr);
    ~AdminForm();
    QString username;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::AdminForm *ui;
};

#endif // ADMINFORM_H
