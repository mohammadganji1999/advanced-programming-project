#include "southvillaform.h"
#include "ui_southvillaform.h"
#include "bulding.h"
#include "fstream"
#include "iostream"
#include "QMessageBox"

SouthVillaForm::SouthVillaForm(QString a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SouthVillaForm)
{
        username=a;
    ui->setupUi(this);
}
SouthVillaForm::~SouthVillaForm()
{
    delete ui;
}
void SouthVillaForm::on_pushButton_2_clicked()
{
    sv=new south_villa;
    QString filter="All file (*.*);;Image file (*.png);;Image file (*.jpg)";
    QString file_name=QFileDialog::getOpenFileName(this,"open a file ",QDir::homePath(),filter);
    sv->setPicture(file_name);
}
void SouthVillaForm::on_pushButton_clicked()
{
    sv->setBuildingArea(ui->BuildAreaLed->text().toInt());
    sv->setAreaYard(ui->YardLed->text().toInt());
    sv->setAreaParking(ui->ParkingLed->text().toInt());
    sv->setRoom(ui->RoomsLed->text().toInt());
    sv->setBasePrice(ui->PriceLed->text().toInt());
    sv->setAddress(ui->CityLed->text(),ui->streetLed->text(),ui->AlleyLed->text(),ui->plaqueLed->text());
    sv->setRequestRent(false);
    sv->setRequestSell(false);
    sv->setRent(false);
    sv->setSell(false);


    std::ofstream file("southvilla.txt",std::ios::app);
    file<<sv->getBuildingArea()<<'\t'<<sv->getAreaYard()<<"\t"<<sv->getAreaParking()<<"\t"<<sv->getNroom()<<"\t"<<sv->getPicture().toStdString()
       <<"\t"<<sv->getBasePrice()<<"\t"<<sv->getStreet().toStdString()<<'\t'
      <<sv->getRent()<<'\t'<<sv->getRequestRent()<<'\t'<<sv->getSell()<<'\t'<<sv->getRequestSell()<<'\t'<<username.toStdString()<<"\n";
    file.close();
    QMessageBox::information(this,"","south villa added");
    delete sv;
}
void SouthVillaForm::on_pushButton_3_clicked()
{
    close();
    bulding *b20=new bulding(username);
    b20->show();
}
