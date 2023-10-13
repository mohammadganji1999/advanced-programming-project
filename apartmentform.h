#ifndef APARTMENTFORM_H
#define APARTMENTFORM_H
#include"apartment.h"

#include <QWidget>

namespace Ui {
class ApartmentForm;
}

class ApartmentForm : public QWidget
{
    Q_OBJECT

public:
    explicit ApartmentForm(QString,QWidget *parent = nullptr);
    ~ApartmentForm();
     QString username;
private slots:
     void on_pushButton_clicked();

     void on_pushButton_4_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_2_clicked();

private:
    Ui::ApartmentForm *ui;
    apartment *ap;
};

#endif // APARTMENTFORM_H
