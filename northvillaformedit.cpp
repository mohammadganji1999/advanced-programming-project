#include "northvillaformedit.h"
#include "ui_northvillaformedit.h"
#include<north_villa.h>
#include<QVector>
#include<fstream>
#include<iostream>
#include"string"
#include"QMessageBox"
#include"building.h"

NorthVillaFormEdit::NorthVillaFormEdit(QString a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NorthVillaFormEdit)
{
    username =a;
    ui->setupUi(this);
}

NorthVillaFormEdit::~NorthVillaFormEdit()
{
    delete ui;
}

void NorthVillaFormEdit::on_pushButton_clicked()
{
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
    file.close();
    int num = ui->spinBox->value();
    if(num>x.size()-1){
        QMessageBox::warning(this,"Error","Entered Number Is Not Valid");
    }
    else {
       x[num-1].setBuildingArea(ui->BuildAreaLed->text().toInt());
       x[num-1].setAreafrontyard(ui->FrontYardLed->text().toInt());
       x[num-1].setAreabackyard(ui->BackYardLed->text().toInt());
       x[num-1].setRoom(ui->RoomsLed->text().toInt());
       x[num-1].setBasePrice(ui->PriceLed->text().toInt());
       x[num-1].setAddress("",ui->streetLed->text(),"","");
       QMessageBox::information(this,"","Changes has been added");
    }
    x.pop_back();
    std::ofstream file1("northvilla.txt");
    for(int d=0;d < x.size();d++)
    {
    file1<<x[d].getBuildingArea()<<'\t'<<x[d].getAreafrontyard()<<"\t"<< x[d].getAreabackyard()<<"\t"<<x[d].getNroom()<<"\t"<<x[d].getPicture().toStdString()
       <<"\t"<<x[d].getBasePrice()<<"\t"<<x[d].getStreet().toStdString()<<'\t'
      <<x[d].getRent()<<'\t'<<x[d].getRequestRent()<<'\t'<<x[d].getSell()<<'\t'<<x[d].getRequestSell()<<'\t'<<username.toStdString()<<"\n";
}
    file1.close();
}

void NorthVillaFormEdit::on_pushButton_2_clicked()
{
    std::ifstream file("northvilla.txt");
    int buildarea,frontyard,backyard,nroom;
    std::string pictur;
    int baseprice;
    std::string address,username2;
    ui->textEdit->clear();
    int rent,reqrent,sell,reqsell;


    ui->textEdit->append("  Building Area\tFrontyard\tBackyard\tNumber of Room\tBase Price\tStreet");
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
        QString SHow = QString::number(k+1)+"-"+QString::number(buildarea)+"\t\t"+QString::number(frontyard)+"\t\t"+QString::number(backyard)+"\t\t"+QString::number(nroom)+"\t\t"
                +QString::number(baseprice)+"\t\t"+QString::fromStdString(address);
        ui->textEdit->append(SHow);}
    }
file3.close();

}

void NorthVillaFormEdit::on_pushButton_3_clicked()
{
    close();
    Building *sadf = new Building(username);
    sadf->show();
}
