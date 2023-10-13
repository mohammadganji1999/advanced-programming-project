#include "userform.h"
#include "ui_userform.h"
#include "bulding.h"
#include "search.h"
#include "userinfo.h"
#include "fstream"
#include "iostream"
#include "signinform.h"
#include"userbuildingshow.h"
#include "userrentshow.h"
#include "usersellshow.h"
UserForm::UserForm(QString _user,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserForm)
{
    ui->setupUi(this);
        username=_user;
}

UserForm::~UserForm()
{
    delete ui;
}


void UserForm::on_pushButton_clicked()
{
    QVector<userinfo> AI;


    userinfo fill;
    QTime ent;
    QTime exi;

    std::string name,lastname,birth,user,pass;
    long int cur;
    int enhour,enmin,exhour,exmin;

     std::ifstream file("userinfo.txt");

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

    std::ofstream file1("userinfo.txt",std::ios::trunc);
    for(int i=0;i<AI.size()-1;i++){
        file1<<AI[i].getname().toStdString()<<'\t'<<AI[i].getlastname().toStdString()<<'\t'<<AI[i].getbirth().toStdString()<<'\t'<<AI[i].getuser().toStdString()
            <<'\t'<<AI[i].getpass().toStdString()<<'\t'<<AI[i].getcurrency()<<'\t'<<AI[i].getentertime().hour()<<'\t'<<AI[i].getentertime().minute()
           <<'\t'<<AI[i].getexittime().hour()<<'\t'<<AI[i].getexittime().minute()<<'\n';
    }
    file1.close();
    close();
    SignInForm *SIF2 = new SignInForm;
    SIF2->show();

}

void UserForm::on_pushButton_5_clicked()
{
    close();
    UserBuildingShow *a132=new UserBuildingShow(username);
    a132->show();
}

void UserForm::on_pushButton_3_clicked()
{
    close();
    userrentshow *urs=new userrentshow(username);
    urs->show();
}

void UserForm::on_pushButton_2_clicked()
{
    close();
    usersellshow *uss=new usersellshow(username);
    uss->show();
}
