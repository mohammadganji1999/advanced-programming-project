#include "userrentshow.h"
#include "ui_userrentshow.h"
#include"userform.h"
#include "rentfile.h"
#include"fstream"
#include"iostream"
#include"string"
#include"north_villa.h"
#include"south_villa.h"
#include"apartment.h"
userrentshow::userrentshow(QString a,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userrentshow)
{
    ui->setupUi(this);
    username=a;
}

userrentshow::~userrentshow()
{
    delete ui;
}

void userrentshow::on_pushButton_2_clicked()
{
    close();
    UserForm *ufo=new UserForm(username);
    ufo->show();
}

void userrentshow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    ui->textEdit->append("House Type\t\tMortgage\t\tRent\t\tPrice\t\tArea\t\tStreet");
    std::string a1,a2,a3,a4,a5,a6,a7,a8,a9;
    std::ifstream dile("rentfiles.txt");
    int j=0;
    while(!dile.eof()){
        dile>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9;
        j++;
    }
    dile.close();

    std::ifstream file("rentfiles.txt");
   for(int i=0;i<j-1;i++){
    std::string Type;
   double mrtgage,rentpay;
   int month;
    double fprice;
    int wholearea;
    std::string street,user,useruser;
    file>>Type>>mrtgage>>rentpay>>month>>fprice>>wholearea>>street>>user>>useruser;

    //north villa fields
    int buildarea,frontyard,backyard,nroom;
    std::string pictur;
    int baseprice;
    std::string address,username2;
    int rent,reqrent,sell,reqsell;
    std::ifstream hile("northvilla.txt");
    int h=0;
    while (!hile.eof()) {
        hile>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
        h++;
    }
hile.close();
    std::ifstream nile("northvilla.txt");
    for(int g=0;g<h-1;g++){
    nile>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
    int AREA = frontyard+backyard+buildarea;
    if(Type=="North"&&useruser==username.toStdString()&&AREA==wholearea&&street==address){
    QString Show=QString::fromStdString(Type)+"\t\t"+QString::number(mrtgage)+"\t\t"+QString::number(rentpay)+"\t\t"+QString::number(fprice,'f',3)+
            "\t\t"+QString::number(wholearea)+"\t\t"+QString::fromStdString(street);
    ui->textEdit->append(Show);
}
    }
        nile.close();
}
    file.close();



    ////////////////
    std::string a11,a12,a13,a14,a15,a16,a17,a18,a19;
    std::ifstream ile("rentfiles.txt");
    int j1=0;
    while(!ile.eof()){
        ile>>a11>>a12>>a13>>a14>>a15>>a16>>a17>>a18>>a19;
        j1++;
    }
    ile.close();

    std::ifstream tile("rentfiles.txt");
   for(int i=0;i<j1-1;i++){
    std::string Type;
   double mrtgage,rentpay;
   int month;
    double fprice;
    int wholearea;
    std::string street,user,useruser;
    tile>>Type>>mrtgage>>rentpay>>month>>fprice>>wholearea>>street>>user>>useruser;

    //south villa fields
    int buildarea,frontyard,backyard,nroom;
    std::string pictur;
    int baseprice;
    std::string address,username2;
    int rent,reqrent,sell,reqsell;
    std::ifstream jile("southvilla.txt");
    int h1=0;
    while (!jile.eof()) {
        jile>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
        h1++;
    }
jile.close();
    std::ifstream mile("southvilla.txt");
    for(int g=0;g<h1-1;g++){
    mile>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
    int AREA = frontyard+backyard+buildarea;
    if(Type=="South"&&useruser==username.toStdString()&&AREA==wholearea&&street==address){
    QString Show=QString::fromStdString(Type)+"\t\t"+QString::number(mrtgage)+"\t\t"+QString::number(rentpay)+"\t\t"+QString::number(fprice,'f',3)+
            "\t\t"+QString::number(wholearea)+"\t\t"+QString::fromStdString(street);
    ui->textEdit->append(Show);
}
    }
        mile.close();
}
    tile.close();


    /////////////
    std::string a21,a22,a23,a24,a25,a26,a27,a28,a29;
    std::ifstream rile("rentfiles.txt");
    int j2=0;
    while(!rile.eof()){
        rile>>a21>>a22>>a23>>a24>>a25>>a26>>a27>>a28>>a29;
        j2++;
    }
    rile.close();

    std::ifstream sile("rentfiles.txt");
   for(int i=0;i<j2-1;i++){
    std::string Type;
    double mrtgage,rentpay;
    int month;
    double fprice;
    int wholearea;
    std::string street,user,useruser;
    sile>>Type>>mrtgage>>rentpay>>month>>fprice>>wholearea>>street>>user>>useruser;

    std::ifstream kile("apartment.txt",std::ios::in);

    int buildarea,baseprice1;

    int elevator1;
    int apfloor1;
    std::string appic;
    std::string sstreet;
    int floor;
    std::string hpic;
    int rooms,hbuildarea1;
    std::string bp;
    int rent,rqrent,sell,rqsell;
    std::string usern;
    std::string a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15;
    int j=0;
    while(!kile.eof()){
        kile>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9>>a10>>a11>>a12>>a13>>a14>>a15>>usern;
        j++;
    }
    kile.close();
    std::ifstream wile("apartment.txt",std::ios::in);
    for(int f=0;f<j-1;f++){
         wile>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9>>a10>>a11>>a12>>a13>>a14>>a15>>usern;

        buildarea = QString::fromStdString(a1).toInt();
        baseprice1 = QString::fromStdString(a2).toInt();
        elevator1 = QString::fromStdString(a3).toInt();
        apfloor1 =  QString::fromStdString(a4).toInt();
        appic = a5;
        sstreet = a6;
        floor =  QString::fromStdString(a7).toInt();
        hpic = a8;
        rooms =  QString::fromStdString(a9).toInt();
        hbuildarea1 = QString::fromStdString(a10).toInt();
        bp = a11;
        rent = QString::fromStdString(a12).toInt();
        rqrent = QString::fromStdString(a13).toInt();
        sell = QString::fromStdString(a14).toInt();
        rqsell = QString::fromStdString(a15).toInt();
        int AREA = hbuildarea1;
         if(Type=="Apartment"&&useruser==username.toStdString()&&AREA==wholearea&&street==sstreet){
             QString Show=QString::fromStdString(Type)+"\t\t"+QString::number(mrtgage,'f',0)+"\t\t"+QString::number(rentpay,'f',0)+"\t\t"+QString::number(fprice,'f',3)+
                     "\t\t"+QString::number(wholearea)+"\t\t"+QString::fromStdString(street);
             ui->textEdit->append(Show);
         }
    }
   wile.close();
   }sile.close();
}



