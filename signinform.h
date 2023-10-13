#ifndef SIGNINFORM_H
#define SIGNINFORM_H

#include <QWidget>

namespace Ui {
class SignInForm;
}

class SignInForm : public QWidget
{
    Q_OBJECT

public:
    explicit SignInForm(QWidget *parent = nullptr);
    ~SignInForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SignInForm *ui;
};

#endif // SIGNINFORM_H
