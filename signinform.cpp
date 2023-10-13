#include "signinform.h"
#include "ui_signinform.h"
#include "mainwindow.h"
#include "userinfo.h"
#include "adminform.h"
#include "admininfo.h"
#include "userform.h"
#include "fstream"
#include "iostream"
#include "QMessageBox"
#include<QVector>


SignInForm::SignInForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignInForm)
{
    ui->setupUi(this);
}

SignInForm::~SignInForm()
{
    delete ui;
}

void SignInForm::on_pushButton_clicked()
{

    QVector<admininfo> ai;
    QVector<userinfo> au;

    QString username,password;
    username=ui->userled->text();
    password=ui->passled->text();

        QString _user;
        QString _usera;

    if(ui->usercombo->currentIndex()==0){
        admininfo fill;
        QTime ent;
        QTime exi;

        std::ofstream br("admininfo.txt",std::ios::app);
        br.close();
        std::ifstream file("admininfo.txt");

        std::string name,lastname,birth,user,pass;
        long int cur;
        int enhour,enmin,exhour,exmin;
        bool exist=false;
       do{

            file>>name>>lastname>>birth>>user>>pass>>cur>>enhour>>enmin>>exhour>>exmin;
            fill.setname(QString::fromStdString(name));
            fill.setlastname(QString::fromStdString(lastname));
            fill.setbirth(QString::fromStdString(birth));
            fill.setuser(QString::fromStdString(user));
            fill.setpass(QString::fromStdString(pass));
            fill.setcurrency(cur);
            ent.setHMS(enhour,enmin,0);
            exi.setHMS(exhour,exmin,0);
            fill.setentertime(ent);
            fill.setexittime(exi);


            if(user==username.toStdString() && pass==password.toStdString()){
                _user=username;
                QString re = "Welcome "+QString::fromStdString(name);
                QMessageBox::information(this,"Welcome",re);
                exist=true;
                QTime cur;
               fill.setentertime(cur.currentTime());
            }
             ai.push_back(fill);
        } while(!file.eof());
        file.close();
        if(!exist){
            QMessageBox::warning(this,"ERROR","this user doesnt exist. ");
        }
        else {
            ai.pop_back();
        std::ofstream file1("admininfo.txt",std::ios::trunc);
        for(int i=0;i<ai.size();i++){
            file1<<ai[i].getname().toStdString()<<'\t'<<ai[i].getlastname().toStdString()<<'\t'<<ai[i].getbirth().toStdString()<<'\t'<<ai[i].getuser().toStdString()
                <<'\t'<<ai[i].getpass().toStdString()<<'\t'<<ai[i].getcurrency()<<'\t'<<ai[i].getentertime().hour()<<'\t'<<ai[i].getentertime().minute()
               <<'\t'<<ai[i].getexittime().hour()<<'\t'<<ai[i].getexittime().minute()<<'\n';
        }
        file1.close();
            AdminForm *P22=new AdminForm(_user);
            close();
            P22->show();
        }
    }

    else {

         std::ofstream br("userinfo.txt",std::ios::app);
         br.close();
        std::ifstream file("userinfo.txt");

        std::string name,lastname,birth,user,pass;
        long int cur;
        int enhour,enmin,exhour,exmin;
        userinfo fill;
        QTime ent;
        QTime exi;
        bool exist=false;
        do{

            file>>name>>lastname>>birth>>user>>pass>>cur>>enhour>>enmin>>exhour>>exmin;
            fill.setname(QString::fromStdString(name));
            fill.setlastname(QString::fromStdString(lastname));
            fill.setbirth(QString::fromStdString(birth));
            fill.setuser(QString::fromStdString(user));
            fill.setpass(QString::fromStdString(pass));
            fill.setcurrency(cur);
            ent.setHMS(enhour,enmin,0);
            exi.setHMS(exhour,exmin,0);
            fill.setentertime(ent);
            fill.setexittime(exi);

            if(user==username.toStdString() && pass==password.toStdString()){
                _usera = username;
                QString re = "Welcome "+QString::fromStdString(name);
                QMessageBox::information(this,"Welcome",re);
                exist=true;
                QTime cur;
               fill.setentertime(cur.currentTime());
            }
             au.push_back(fill);
        }while(!file.eof());
        file.close();
        if(!exist){
            QMessageBox::warning(this,"ERROR","this user doesnt exist. ");
        }
        else {
            au.pop_back();
        std::ofstream file1("userinfo.txt",std::ios::trunc);
        for(int i=0;i<au.size();i++){
            file1<<au[i].getname().toStdString()<<'\t'<<au[i].getlastname().toStdString()<<'\t'<<au[i].getbirth().toStdString()<<'\t'<<au[i].getuser().toStdString()
                <<'\t'<<au[i].getpass().toStdString()<<'\t'<<au[i].getcurrency()<<'\t'<<au[i].getentertime().hour()<<'\t'<<au[i].getentertime().minute()
               <<'\t'<<au[i].getexittime().hour()<<'\t'<<au[i].getexittime().minute()<<'\n';
        }
        file1.close();

            UserForm *p1=new UserForm(_usera);
            close();
            p1->show();
        }
}
}

void SignInForm::on_pushButton_2_clicked()
{
    close();
    MainWindow *l=new MainWindow();
    l->show();
}
