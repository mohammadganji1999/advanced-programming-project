#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<signupform.h>
#include<signinform.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_upbtn_clicked()
{
    close();
    SignUpForm *a=new SignUpForm();
    a->show();
}

void MainWindow::on_inbtn_clicked()
{

    close();
    SignInForm *a=new SignInForm();
    a->show();
}

void MainWindow::on_pushButton_clicked()
{
    close();
}
