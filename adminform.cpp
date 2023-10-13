#include "adminform.h"
#include "ui_adminform.h"
#include "bulding.h"
#include"search.h"
#include"admininfo.h"
#include"signinform.h"
#include"QTime"
#include<fstream>
#include<iostream>
#include "building.h"
#include"sellform.h"
#include"rentform.h"
#include"sellshow.h"
#include"rentshow.h"

AdminForm::AdminForm(QString _user,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminForm)
{
    username=_user;
    ui->setupUi(this);
}

AdminForm::~AdminForm()
{
    delete ui;
}

void AdminForm::on_pushButton_2_clicked()
{
    close();
    bulding *bul=new bulding(username);
    bul->show();
}

void AdminForm::on_pushButton_clicked()
{
    close();
    search *sea = new search(username);
    sea->show();
}


void AdminForm::on_pushButton_7_clicked()
{
    QVector<admininfo> AI;


    admininfo fill;
    QTime ent;
    QTime exi;

    std::string name,lastname,birth,user,pass;
    long int cur;
    int enhour,enmin,exhour,exmin;

     std::ifstream file("admininfo.txt");

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

        if(user==username.toStdString()){
            QTime cur;
           fill.setexittime(cur.currentTime());
        }
         AI.push_back(fill);
    } while(!file.eof());
    file.close();

    std::ofstream file1("admininfo.txt",std::ios::trunc);
    for(int i=0;i<AI.size()-1;i++){
        file1<<AI[i].getname().toStdString()<<'\t'<<AI[i].getlastname().toStdString()<<'\t'<<AI[i].getbirth().toStdString()<<'\t'<<AI[i].getuser().toStdString()
            <<'\t'<<AI[i].getpass().toStdString()<<'\t'<<AI[i].getcurrency()<<'\t'<<AI[i].getentertime().hour()<<'\t'<<AI[i].getentertime().minute()
           <<'\t'<<AI[i].getexittime().hour()<<'\t'<<AI[i].getexittime().minute()<<'\n';
    }
    file1.close();
    close();
    SignInForm *SIF = new SignInForm;
    SIF->show();

}

void AdminForm::on_pushButton_8_clicked()
{
    close();
    Building *BU = new Building(username);
    BU->show();
}

void AdminForm::on_pushButton_4_clicked()
{
    close();
    sellform *sf3=new sellform(username);
    sf3->show();
}

void AdminForm::on_pushButton_6_clicked()
{
    close();
    rentform *rf3=new rentform(username);
    rf3->show();
}

void AdminForm::on_pushButton_3_clicked()
{
    close();
    sellShow *rsd= new sellShow(username);
    rsd->show();
}

void AdminForm::on_pushButton_5_clicked()
{
    close();
    rentShow *dfg= new rentShow(username);
    dfg->show();
}
