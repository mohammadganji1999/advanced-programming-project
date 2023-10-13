#include "sellform.h"
#include "ui_sellform.h"
#include"adminform.h"
#include<QVector>
#include<sellfile.h>
#include<apartment.h>
#include<south_villa.h>
#include<north_villa.h>
#include<fstream>
#include<iostream>
#include"QMessageBox"

sellform::sellform(QString a,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sellform)
{
    username = a;
    ui->setupUi(this);
}


sellform::~sellform()
{
    delete ui;
}

void sellform::on_pushButton_5_clicked()
{
    close();
    AdminForm *hgs=new AdminForm(username);
    hgs->show();
}

void sellform::on_pushButton_clicked()
{
    if(ui->comboBox->currentIndex()==0){

        std::ifstream file("northvilla.txt");
        int buildarea,frontyard,backyard,nroom;
        std::string pictur;
        int baseprice;
        std::string address,username2;
        ui->textEdit->clear();
        int rent,reqrent,sell,reqsell;


        ui->textEdit->append("  Building Area\tFrontyard\tBackyard\t\tNumber of Room\tBase Price\t\tStreet");
      int j=0;
        for( int i=1;file.eof()==false;i++){
            file>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
            j++;
        }
            file.close();
             std::ifstream file3("northvilla.txt");

        for(int k=0;k<j-1;k++){
            file3>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
            if(username.toStdString()==username2){
            QString SHow = QString::number(k+1)+"-"+QString::number(buildarea)+"\t\t"+QString::number(frontyard)+"\t"+QString::number(backyard)+"\t\t"+QString::number(nroom)+"\t\t"
                    +QString::number(baseprice)+"\t\t"+QString::fromStdString(address);
            ui->textEdit->append(SHow);}
        }
    file3.close();


    }
    else if(ui->comboBox->currentIndex()==1){

        std::ifstream file("southvilla.txt");
        int buildarea,frontyard,backyard,nroom;
        std::string pictur;
        int baseprice;
        std::string address,username2;
        ui->textEdit->clear();
        int rent,reqrent,sell,reqsell;


        ui->textEdit->append("  Building Area\tYard\t\tParking\t\tNumber of Room\tBase Price\t\tStreet");
      int j=0;
        for( int i=1;file.eof()==false;i++){
            file>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
            j++;
        }
            file.close();
             std::ifstream file3("southvilla.txt");

        for(int k=0;k<j-1;k++){
            file3>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
            if(username.toStdString()==username2){
            QString SHow = QString::number(k+1)+"-"+QString::number(buildarea)+"\t\t"+QString::number(frontyard)+"\t\t"+QString::number(backyard)+"\t\t"+QString::number(nroom)+"\t\t"
                    +QString::number(baseprice)+"\t\t"+QString::fromStdString(address);
            ui->textEdit->append(SHow);}
        }
    file3.close();

    }

    else {
        std::ifstream file("apartment.txt");
        ui->textEdit->clear();
        std::string user;
        std::string a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15;
        ui->textEdit->append("  Base price\tElevator\tFloor number\t\tNumber of rooms\tBuilding area\t\tUsage");
        int j=0;
          while(!file.eof()){
        file>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9>>a10>>a11>>a12>>a13>>a14>>a15>>user;
        j++;
          }

        file.close();
        std::ifstream file3("apartment.txt");

        for(int k=0;k<j-1;k++){
            file3>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9>>a10>>a11>>a12>>a13>>a14>>a15>>user;
             if(username.toStdString()==user){
                QString Show=QString::number(k+1)+"-"+QString::fromStdString(a2)+"\t"+QString::fromStdString(a3)+"\t"+QString::fromStdString(a7)+"\t\t"+QString::fromStdString(a9)+"\t\t"+
                QString::fromStdString(a10)+"\t\t"+QString::fromStdString(a11);
            ui->textEdit->append(Show);
        }
        }
        file3.close();
    }
}

void sellform::on_pushButton_4_clicked()
{
    if(ui->comboBox->currentIndex()==0){
        QVector<north_villa> x;
        north_villa tmp;
        std::ifstream file("northvilla.txt");
        int buildarea,frontyard,backyard,nroom;
        std::string pictur;
        int baseprice;
        std::string address,username2;
        int rent,reqrent,sell,reqsell;

        int i=1;
        for(;!file.eof();i++){
            file>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
            if(username.toStdString()==username2){
            tmp.setBuildingArea(buildarea);
            tmp.setAreafrontyard(frontyard);
            tmp.setAreabackyard(backyard);
            tmp.setRoom(nroom);
            tmp.setPicture(QString::fromStdString(pictur));
            tmp.setBasePrice(baseprice);
            tmp.setAddress("",QString::fromStdString(address),"","");
            x.push_back(tmp);
            }
        }
        x.pop_back();
        file.close();
        int num = ui->spinBox_2->value();
        if(num>x.size()){
            QMessageBox::warning(this,"Error","Entered Number Is Not Valid");
        }
        else {
            sellFile rf;
            rf.setType("North");
            rf.setAllprice(x[num-1].calPrice());
            rf.setCo(ui->condition->currentText());
            std::ofstream file4("sellfiles.txt",std::ios::app);

            file4<<rf.getType().toStdString()<<'\t'<<rf.getCo().toStdString()<<'\t'<<rf.finalprice()<<'\t'<<x[num-1].calArea()
            <<'\t'<<x[num-1].getStreet().toStdString()<<'\t'<<username.toStdString()<<"\tuser20"<<'\n';

        file4.close();
        QMessageBox::information(this,"","Sell file added successfully");
}
    }
    else if(ui->comboBox->currentIndex()==1){
        QVector<south_villa> x;
        south_villa tmp;
        std::ifstream file("southvilla.txt");
        int buildarea,frontyard,backyard,nroom;
        std::string pictur;
        int baseprice;
        std::string address,username2;
        int rent,reqrent,sell,reqsell;


        int i=1;
        for(;!file.eof();i++){
            file>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
            if(username.toStdString()==username2){
            tmp.setBuildingArea(buildarea);
            tmp.setAreaYard(frontyard);
            tmp.setAreaParking(backyard);
            tmp.setRoom(nroom);
            tmp.setPicture(QString::fromStdString(pictur));
            tmp.setBasePrice(baseprice);
            tmp.setAddress("",QString::fromStdString(address),"","");
            x.push_back(tmp);
            }
        }
        file.close();
        x.pop_back();
        int num = ui->spinBox_2->value();
        if(num>x.size()){
            QMessageBox::warning(this,"Error","Entered Number Is Not Valid");
        }
        else {
            sellFile rf;
            rf.setType("South");
            rf.setAllprice(x[num-1].calPrice());
            rf.setCo(ui->condition->currentText());
            std::ofstream file4("sellfiles.txt",std::ios::app);

            file4<<rf.getType().toStdString()<<'\t'<<rf.getCo().toStdString()<<'\t'<<rf.finalprice()<<'\t'<<x[num-1].calArea()
            <<'\t'<<x[num-1].getStreet().toStdString()<<'\t'<<username.toStdString()<<"\tuser20"<<'\n';

        file4.close();
        QMessageBox::information(this,"","Sell file added successfully");
        }
    }
    else{
        QVector<apartment> x1;
        apartment tmp;
        std::ifstream file("apartment.txt",std::ios::in);

        int buildarea,baseprice1;

        int elevator1;
        int apfloor1;
        std::string appic;
        std::string street;
        int floor;
        std::string hpic;
        int rooms,hbuildarea1;
        std::string bp;
        int rent,rqrent,sell,rqsell;
        std::string user;
        std::string a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15;
        int j=0;
        while(!file.eof()){
            file>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9>>a10>>a11>>a12>>a13>>a14>>a15>>user;
            buildarea = QString::fromStdString(a1).toInt();
            baseprice1 = QString::fromStdString(a2).toInt();
            elevator1 = QString::fromStdString(a3).toInt();
            apfloor1 =  QString::fromStdString(a4).toInt();
            appic = a5;
            street = a6;
            floor =  QString::fromStdString(a7).toInt();
            hpic = a8;
            rooms =  QString::fromStdString(a9).toInt();
            hbuildarea1 = QString::fromStdString(a10).toInt();
            bp = a11;
            rent = QString::fromStdString(a12).toInt();
            rqrent = QString::fromStdString(a13).toInt();
            sell = QString::fromStdString(a14).toInt();
            rqsell = QString::fromStdString(a15).toInt();
            tmp.setBuildingArea(buildarea);
            tmp.setBasePrice(baseprice1);
            tmp.setelevator(elevator1);
            tmp.setFloor(apfloor1);
            tmp.setPicture(QString::fromStdString(bp));
            tmp.setAddress("",QString::fromStdString(street),"","");
            tmp.h.setFloornumber(  floor);
            tmp.h.setPic(QString::fromStdString(hpic));
            tmp.h.setRooms(rooms);
            tmp.h.setAreaBuild(hbuildarea1);
            tmp.h.setBusinessPlan(QString::fromStdString(bp));
            tmp.setRent(rent);
            tmp.setRequestRent(rqrent);
            tmp.setSell(sell);
            tmp.setRequestSell(rqsell);
            x1.push_back(tmp);
            j++;
        }
        file.close();
        x1.pop_back();
        int num = ui->spinBox_2->value();
        if(num>x1.size()){
            QMessageBox::information(this,"Error","Entered Number Is not Valid");
        }
        else {
            sellFile rf;
            rf.setType("Apartment");
            rf.setAllprice(x1[num-1].CALPrice());
            rf.setCo(ui->condition->currentText());
            std::ofstream file4("sellfiles.txt",std::ios::app);

            file4<<rf.getType().toStdString()<<'\t'<<rf.getCo().toStdString()<<'\t'<<rf.finalprice()<<'\t'<<x1[num-1].h.getAreaBuild()
            <<'\t'<<x1[num-1].getStreet().toStdString()<<'\t'<<username.toStdString()<<"\tuser20"<<'\n';

        file4.close();

            QMessageBox::information(this,"","Sell file added successfully");

        }
    }
}
