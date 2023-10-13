#ifndef BUILDING_H
#define BUILDING_H

#include <QWidget>

namespace Ui {
class Building;
}

class Building : public QWidget
{
    Q_OBJECT

public:
    explicit Building(QString,QWidget *parent = nullptr);
    ~Building();
    QString username;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Building *ui;
};

#endif // BUILDING_H
