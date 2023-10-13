#ifndef SOUTHVILLAFORMEDIT_H
#define SOUTHVILLAFORMEDIT_H

#include <QWidget>

namespace Ui {
class SouthVillaFormEdit;
}

class SouthVillaFormEdit : public QWidget
{
    Q_OBJECT

public:
    explicit SouthVillaFormEdit(QString,QWidget *parent = nullptr);
    ~SouthVillaFormEdit();
    QString username;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::SouthVillaFormEdit *ui;
};

#endif // SOUTHVILLAFORMEDIT_H
