#include "southvillaformedit.h"
#include "ui_southvillaformedit.h"
#include "south_villa.h"
#include "building.h"
#include"fstream"
#include "iostream"
#include "QVector"
#include "QMessageBox"


SouthVillaFormEdit::SouthVillaFormEdit(QString a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SouthVillaFormEdit)
{
    ui->setupUi(this);
    username=a;
}

SouthVillaFormEdit::~SouthVillaFormEdit()
{
    delete ui;
}

void SouthVillaFormEdit::on_pushButton_2_clicked()
{
    std::ifstream file("southvilla.txt");
    int buildarea,frontyard,backyard,nroom;
    std::string pictur;
    int baseprice;
    std::string address,username2;
    ui->textEdit->clear();
    int rent,reqrent,sell,reqsell;


    ui->textEdit->append("  Building Area\tYard\t\tParking\t\tNumber of Room\tBase Price\tStreet");
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

void SouthVillaFormEdit::on_pushButton_clicked()
{
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
    int num = ui->spinBox->value();
    if(num>x.size()-1){
        QMessageBox::warning(this,"Error","Entered Number Is Not Valid");
    }
    else {
       x[num-1].setBuildingArea(ui->BuildAreaLed->text().toInt());
       x[num-1].setAreaYard(ui->FrontYardLed->text().toInt());
       x[num-1].setAreaParking(ui->BackYardLed->text().toInt());
       x[num-1].setRoom(ui->RoomsLed->text().toInt());
       x[num-1].setBasePrice(ui->PriceLed->text().toInt());
       x[num-1].setAddress("",ui->streetLed->text(),"","");
       QMessageBox::information(this,"","Changes has been added");
    }
    x.pop_back();
    std::ofstream file1("southvilla.txt");
    for(int d=0;d < x.size();d++)
    {
    file1<<x[d].getBuildingArea()<<'\t'<<x[d].getAreaYard()<<"\t"<< x[d].getAreaParking()<<"\t"<<x[d].getNroom()<<"\t"<<x[d].getPicture().toStdString()
       <<"\t"<<x[d].getBasePrice()<<"\t"<<x[d].getStreet().toStdString()<<'\t'
      <<x[d].getRent()<<'\t'<<x[d].getRequestRent()<<'\t'<<x[d].getSell()<<'\t'<<x[d].getRequestSell()<<'\t'<<username.toStdString()<<"\n";
}
    file1.close();

}

void SouthVillaFormEdit::on_pushButton_3_clicked()
{
    close();
    Building *bul1=new Building(username);
    bul1->show();
}
