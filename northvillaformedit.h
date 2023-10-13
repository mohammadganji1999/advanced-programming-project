#ifndef NORTHVILLAFORMEDIT_H
#define NORTHVILLAFORMEDIT_H

#include <QWidget>

namespace Ui {
class NorthVillaFormEdit;
}

class NorthVillaFormEdit : public QWidget
{
    Q_OBJECT

public:
    explicit NorthVillaFormEdit(QString,QWidget *parent = nullptr);
    ~NorthVillaFormEdit();
    QString username;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::NorthVillaFormEdit *ui;
};

#endif // NORTHVILLAFORMEDIT_H
