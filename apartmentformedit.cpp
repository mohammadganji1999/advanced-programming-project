#include "apartmentformedit.h"
#include "ui_apartmentformedit.h"
#include "apartment.h"
#include "building.h"
#include "fstream"
#include "QMessageBox"
ApartmentFormEdit::ApartmentFormEdit(QString a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ApartmentFormEdit)
{
    username=a;
    ui->setupUi(this);
}

ApartmentFormEdit::~ApartmentFormEdit()
{
    delete ui;
}

void ApartmentFormEdit::on_pushButton_2_clicked()
{
    close();
    Building *kh=new Building(username);
    kh->show();

}

void ApartmentFormEdit::on_pushButton_clicked()
{
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
        tmp.setPicture(QString::fromStdString(appic));
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
    int num = ui->spinBox->value();
    if(num>x1.size()){
        QMessageBox::information(this,"Error","Entered Number Is not Valid");
    }
    else {
        x1[num-1].setBasePrice(ui->baseprice->text().toInt());
        if(ui->eleveatorcmb==0)      x1[num-1].setelevator(1);
                else x1[num-1].setelevator(0);
        x1[num-1].h.setFloornumber(ui->floor_2->text().toInt());
        x1[num-1].h.setRooms(ui->room->text().toInt());
        x1[num-1].h.setAreaBuild(ui->buildarea->text().toInt());
        x1[num-1].h.setBusinessPlan(ui->BPcmb->currentText());
        QMessageBox::information(this,"","Changes has been Added");
    }
    std::ofstream file3("apartment.txt",std::ios::trunc);
    for(int k=0;k<j-1;k++){
        file3<<x1[k].getBuildingArea()<<'\t'<<x1[k].getBasePrice()<<'\t'<<x1[k].getelevator()<<'\t'<<x1[k].getFloor()<<'\t'<<x1[k].getPicture().toStdString()<<'\t'<<x1[k].getStreet().toStdString()<<'\t'<<
              x1[k].h.getFloornumber()<<'\t'<<x1[k].h.getPic().toStdString()<<'\t'<<x1[k].h.getRooms()<<'\t'<<x1[k].h.getAreaBuild()<<'\t'<<x1[k].h.getBusinessPlan().toStdString()
              <<'\t'<<x1[k].getRent()<<'\t'<<x1[k].getRequestRent()<<'\t'<<x1[k].getSell()<<'\t'<<x1[k].getRequestSell()<<'\t'<<username.toStdString()<<'\n';

    }
    file3.close();

}

void ApartmentFormEdit::on_showbtn_clicked()
{
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
