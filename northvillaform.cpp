#include "northvillaform.h"
#include "ui_northvillaform.h"
#include "north_villa.h"
#include "bulding.h"
#include "QFileDialog"
#include "QDir"
#include "fstream"
#include "iostream"
#include "QMessageBox"

NorthVillaForm::NorthVillaForm(QString a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NorthVillaForm)
{
    ui->setupUi(this);
        username=a;
}

NorthVillaForm::~NorthVillaForm()
{
    delete ui;
}

void NorthVillaForm::on_pushButton_clicked()
{


nv->setBuildingArea(ui->BuildAreaLed->text().toInt());
nv->setAreafrontyard(ui->FrontYardLed->text().toInt());
nv->setAreabackyard(ui->BackYardLed->text().toInt());
nv->setRoom(ui->RoomsLed->text().toInt());
nv->setBasePrice(ui->PriceLed->text().toInt());
nv->setAddress(ui->CityLed->text(),ui->streetLed->text(),ui->AlleyLed->text(),ui->plaqueLed->text());
nv->setRequestRent(false);
nv->setRequestSell(false);
nv->setRent(false);
nv->setSell(false);


std::ofstream file("northvilla.txt",std::ios::app);
file<<nv->getBuildingArea()<<'\t'<<nv->getAreafrontyard()<<"\t"<<nv->getAreabackyard()<<"\t"<<nv->getNroom()<<"\t"<<nv->getPicture().toStdString()
   <<"\t"<<nv->getBasePrice()<<"\t"<<nv->getStreet().toStdString()<<'\t'
  <<nv->getRent()<<'\t'<<nv->getRequestRent()<<'\t'<<nv->getSell()<<'\t'<<nv->getRequestSell()<<'\t'<<username.toStdString()<<"\n";
file.close();
QMessageBox::information(this,"","north villa added");
delete nv;

}

void NorthVillaForm::on_pushButton_3_clicked()
{
    close();
    bulding *b9=new bulding(username);
    b9->show();
}

void NorthVillaForm::on_pushButton_2_clicked()
{
    nv=new north_villa;
    QString filter="All file (*.*);;Image file (*.png);;Image file (*.jpg)";
    QString file_name=QFileDialog::getOpenFileName(this,"open a file ",QDir::homePath(),filter);
    nv->setPicture(file_name);

}
