#include "signupform.h"
#include "ui_signupform.h"
#include <mainwindow.h>
#include "userinfo.h"
#include "admininfo.h"
#include <QMessageBox>
#include<QTextStream>
#include<iostream>
#include<fstream>
#include<string>


SignUpForm::SignUpForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUpForm)
{
    ui->setupUi(this);
}


SignUpForm::~SignUpForm()
{
    delete ui;
}

void SignUpForm::on_addbtn_clicked()
{
    bool check;
    if(ui->usercmb->currentIndex()==0){
        admininfo tmp;
        tmp.setname(ui->nameled->text());
        tmp.setlastname(ui->lastled->text());
        tmp.setbirth(ui->birthdayled->text());
        tmp.setuser(ui->usernameled->text());
        tmp.setpass(ui->passled->text());
        tmp.setcurrency(ui->accountled->text().toInt());

        std::ofstream file("admininfo.txt",std::ios::app);
         file.close();
        std::ifstream file1("admininfo.txt");

            bool exist = false;
            std::string name,lastname,birth,user,pass;
            long int cur;
            int enhour,enmin,exhour,exmin;
            while(!file1.eof()){
                file1>>name>>lastname>>birth>>user>>pass>>cur>>enhour>>enmin>>exhour>>exmin;
                if(tmp.getuser().toStdString()==user)
                    exist = true;
                break;
            }
            file1.close();
          if(!exist){
              std::ofstream file2("admininfo.txt",std::ios::app);

              file2<<tmp.getname().toStdString()<<'\t'<<tmp.getlastname().toStdString()<<'\t'<<tmp.getbirth().toStdString()<<'\t'<<tmp.getuser().toStdString()
                  <<'\t'<<tmp.getpass().toStdString()<<'\t'<<tmp.getcurrency()<<'\t'<<tmp.getentertime().hour()<<'\t'<<tmp.getentertime().minute()
                 <<'\t'<<tmp.getexittime().hour()<<'\t'<<tmp.getexittime().minute()<<'\n';
              file2.close();
              check =true;
          }
          else {
              QMessageBox::warning(this,"Error","The User Already Exists");
          }
        }

    else {
        userinfo temp;
        temp.setname(ui->nameled->text());
        temp.setlastname(ui->lastled->text());
        temp.setbirth(ui->birthdayled->text());
        temp.setuser(ui->usernameled->text());
        temp.setpass(ui->passled->text());
        temp.setcurrency(ui->accountled->text().toInt());
        std::ofstream file("userinfo.txt",std::ios::app);
         file.close();
        std::ifstream file1("userinfo.txt");

            bool exist = false;
            std::string name,lastname,birth,user,pass;
            long int cur;
            int enhour,enmin,exhour,exmin;
            while(!file1.eof()){
                file1>>name>>lastname>>birth>>user>>pass>>cur>>enhour>>enmin>>exhour>>exmin;
                if(temp.getuser().toStdString()==user)
                    exist = true;
                break;
            }
            file1.close();
          if(!exist){
              std::ofstream file2("userinfo.txt",std::ios::app);

              file2<<temp.getname().toStdString()<<'\t'<<temp.getlastname().toStdString()<<'\t'<<temp.getbirth().toStdString()<<'\t'<<temp.getuser().toStdString()
                  <<'\t'<<temp.getpass().toStdString()
       <<'\t'<<temp.getcurrency()<<'\t'<<temp.getentertime().hour()<<'\t'<<temp.getentertime().minute()
              <<'\t'<<temp.getexittime().hour()<<'\t'<<temp.getexittime().minute()<<'\n';
              file2.close();
              check =true;
          }

    else {
         QMessageBox::warning(this,"Error","The User Already Exists");
    }
          }
    if(check) {
        QMessageBox::information(this,"Message","You've been successfully signed up");
        close();
        MainWindow *sa = new MainWindow;
        sa->show();
    }
}

void SignUpForm::on_backbtn_clicked()
{
    close();
    MainWindow *ma = new MainWindow;
    ma->show();
}
