#ifndef APARTMENTFORMEDIT_H
#define APARTMENTFORMEDIT_H

#include <QWidget>

namespace Ui {
class ApartmentFormEdit;
}

class ApartmentFormEdit : public QWidget
{
    Q_OBJECT

public:
    explicit ApartmentFormEdit(QString,QWidget *parent = nullptr);
    ~ApartmentFormEdit();
    QString username;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_showbtn_clicked();

private:
    Ui::ApartmentFormEdit *ui;
};

#endif // APARTMENTFORMEDIT_H
