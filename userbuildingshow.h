#ifndef USERBUILDINGSHOW_H
#define USERBUILDINGSHOW_H
#include"QString"
#include <QWidget>

namespace Ui {
class UserBuildingShow;
}

class UserBuildingShow : public QWidget
{
    Q_OBJECT

public:
    explicit UserBuildingShow(QString a,QWidget *parent = nullptr);
    ~UserBuildingShow();

    QString
    username;
private slots:

    void on_pushButton_2_clicked();

    void on_ShowBtn_clicked();

    void on_pushButton_clicked();

private:
    Ui::UserBuildingShow *ui;
};

#endif // USERBUILDINGSHOW_H
