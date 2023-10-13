#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include"QString"
namespace Ui {
class search;
}

class search : public QWidget
{
    Q_OBJECT

public:
    explicit search(QString,QWidget *parent = nullptr);
    ~search();
    QString username;

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::search *ui;
};

#endif // SEARCH_H
