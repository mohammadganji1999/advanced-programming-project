#include "usersellshow.h"
#include "ui_usersellshow.h"
#include"userform.h"
#include"fstream"
#include"iostream"
#include"string"
#include"north_villa.h"
#include"south_villa.h"
#include"apartment.h"
#include"sellfile.h"
usersellshow::usersellshow(QString a,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::usersellshow)
{
    ui->setupUi(this);
    username =a;
}

usersellshow::~usersellshow()
{
    delete ui;
}

void usersellshow::on_pushButton_2_clicked()
{
    close();
    UserForm *ufo2=new UserForm(username);
    ufo2->show();
}

void usersellshow::on_pushButton_clicked()
{

    ui->textEdit->clear();
std::ofstream file10("sellfiles.txt",std::ios::app);
file10.close();
ui->textEdit->append("House Type\t\tCondition\t\tPrice\t\tArea\t\tStreet");
std::string a1,a2,a3,a4,a5,a6,a7;
std::ifstream dile("sellfiles.txt");
int j=0;
while(!dile.eof()){
dile>>a1>>a2>>a3>>a4>>a5>>a6>>a7;
j++;
}
dile.close();

std::ifstream file("sellfiles.txt");
for(int i=0;i<j-1;i++){
std::string Type,CON;
double fprice;
int wholearea;
std::string street,user,useruser;
file>>Type>>CON>>fprice>>wholearea>>street>>user>>useruser;

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

std::ifstream nile("northvilla.txt");
for(int g=0;g<h-1;g++){
nile>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
int AREA = frontyard+backyard+buildarea;
if(Type=="North"&&username.toStdString()==useruser&&AREA==wholearea&&street==address){
QString Show=QString::fromStdString(Type)+"\t\t"+QString::fromStdString(CON)+"\t\t"+QString::number(fprice,'f',3)+
"\t\t"+QString::number(wholearea)+"\t\t"+QString::fromStdString(street);
ui->textEdit->append(Show);
}
}
nile.close();
}
file.close();
///////////////////////////



{
std::string a1,a2,a3,a4,a5,a6,a7;
std::ifstream dile("sellfiles.txt");
int j=0;
while(!dile.eof()){
dile>>a1>>a2>>a3>>a4>>a5>>a6>>a7;
j++;
}
dile.close();

std::ifstream file("sellfiles.txt");
for(int i=0;i<j-1;i++){
std::string Type,CON;
double fprice;
int wholearea;
std::string street,user,useruser;
file>>Type>>CON>>fprice>>wholearea>>street>>user>>useruser;

//south villa fields
int buildarea,frontyard,backyard,nroom;
std::string pictur;
int baseprice;
std::string address,username2;
int rent,reqrent,sell,reqsell;
std::ifstream hile("southvilla.txt");
int h=0;
while (!hile.eof()) {
hile>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
h++;
}

std::ifstream nile("southvilla.txt");
for(int g=0;g<h-1;g++){
nile>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
int AREA = frontyard+backyard+buildarea;
if(Type=="South"&&username.toStdString()==useruser&&AREA==wholearea&&street==address){
QString Show=QString::fromStdString(Type)+"\t\t"+QString::fromStdString(CON)+"\t\t"+QString::number(fprice,'f',3)+
"\t\t"+QString::number(wholearea)+"\t\t"+QString::fromStdString(street);
ui->textEdit->append(Show);
}
}
nile.close();
}
file.close();

}
///////////
{

    std::string a1,a2,a3,a4,a5,a6,a7;
    std::ifstream dile("sellfiles.txt");
    int j=0;
    while(!dile.eof()){
        dile>>a1>>a2>>a3>>a4>>a5>>a6>>a7;
        j++;
    }
    dile.close();

    std::ifstream sile("sellfiles.txt");
   for(int i=0;i<j-1;i++){
       std::string Type,CON;
       double fprice;
       int wholearea;
       std::string street,user,useruser;
       sile>>Type>>CON>>fprice>>wholearea>>street>>user>>useruser;


    std::ifstream file("apartment.txt",std::ios::in);

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
    while(!file.eof()){
        file>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9>>a10>>a11>>a12>>a13>>a14>>a15>>usern;
        j++;
    }
    file.close();
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
             QString Show=QString::fromStdString(Type)+"\t\t"+QString::fromStdString(CON)+"\t\t"+QString::number(fprice,'f',3)+
                     "\t\t"+QString::number(wholearea)+"\t\t"+QString::fromStdString(street);
             ui->textEdit->append(Show);
         }
    }
   wile.close();
   }sile.close();

}

}



