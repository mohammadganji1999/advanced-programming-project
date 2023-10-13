#ifndef NORTHVILLAFORM_H
#define NORTHVILLAFORM_H
#include "north_villa.h"
#include <QWidget>

namespace Ui {
class NorthVillaForm;
}

class NorthVillaForm : public QWidget
{
    Q_OBJECT

public:
    explicit NorthVillaForm(QString,QWidget *parent = nullptr);
    ~NorthVillaForm();
    QString username;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::NorthVillaForm *ui;
    north_villa *nv;
};

#endif // NORTHVILLAFORM_H
