#ifndef RENTSHOW_H
#define RENTSHOW_H
#include"QString"
#include <QWidget>

namespace Ui {
class rentShow;
}

class rentShow : public QWidget
{
    Q_OBJECT

public:
    explicit rentShow(QString,QWidget *parent = nullptr);
    ~rentShow();
    QString username;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::rentShow *ui;
};

#endif // RENTSHOW_H
