#ifndef SOUTHVILLAFORM_H
#define SOUTHVILLAFORM_H
#include"south_villa.h"

#include <QWidget>

namespace Ui {
class SouthVillaForm;
}

class SouthVillaForm : public QWidget
{
    Q_OBJECT

public:
    explicit SouthVillaForm(QString,QWidget *parent = nullptr);
    ~SouthVillaForm();
    QString username;


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::SouthVillaForm *ui;
    south_villa *sv;
};

#endif // SOUTHVILLAFORM_H
