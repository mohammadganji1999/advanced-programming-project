#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QWidget>

namespace Ui {
class SignUpForm;
}

class SignUpForm : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpForm(QWidget *parent = nullptr);
    ~SignUpForm();

private slots:
    void on_addbtn_clicked();

    void on_backbtn_clicked();

private:
    Ui::SignUpForm *ui;
};

#endif // SIGNUPFORM_H
