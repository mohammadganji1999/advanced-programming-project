#include "apartmentform.h"
#include "ui_apartmentform.h"
#include"QDir"
#include"QFileDialog"
#include"iostream"
#include"fstream"
#include"QMessageBox"
#include"QString"
#include"bulding.h"



ApartmentForm::ApartmentForm(QString user,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ApartmentForm)
{
    username=user;
    ui->setupUi(this);
}

ApartmentForm::~ApartmentForm()
{
    delete ui;
}

void ApartmentForm::on_pushButton_4_clicked()
{
    ap = new apartment;
    QString filter="All file (*.*);;Image file (*.png);;Image file (*.jpg)";
    QString file_name=QFileDialog::getOpenFileName(this,"open a file ",QDir::currentPath(),filter);
    ap->setPicture(file_name);
}


void ApartmentForm::on_pushButton_clicked()
{
    ap->setBasePrice(ui->baseprice->text().toInt());
    bool elevator;
    if(ui->eleveatorcmb->currentIndex()==0) elevator=true;
    else elevator=false;
    ap->setBuildingArea(ui->apartarea->text().toInt());
    ap->setelevator(elevator);
    ap->setFloor(ui->floor->text().toInt());
    ap->setAddress(ui->city->text(),ui->street->text(),ui->alley->text(),ui->plak->text());
    ap->h.setFloornumber(ui->floor_2->text().toInt());
    ap->h.setRooms(ui->room->text().toInt());
    ap->h.setAreaBuild(ui->buildarea->text().toInt());
    ap->h.setBusinessPlan(ui->BPcmb->currentText());
    ap->setRequestRent(false);
    ap->setRequestSell(false);
    ap->setRent(false);
    ap->setSell(false);

    std::ofstream file("apartment.txt",std::ios::app);

    file<<ap->getBuildingArea()<<'\t'<<ap->getBasePrice()<<'\t'<<ap->getelevator()<<'\t'<<ap->getFloor()<<'\t'<<ap->getPicture().toStdString()<<'\t'<<ap->getStreet().toStdString()<<'\t'<<
          ap->h.getFloornumber()<<'\t'<<ap->h.getPic().toStdString()<<'\t'<<ap->h.getRooms()<<'\t'<<ap->h.getAreaBuild()<<'\t'<<ap->h.getBusinessPlan().toStdString()
          <<'\t'<<ap->getRent()<<'\t'<<ap->getRequestRent()<<'\t'<<ap->getSell()<<'\t'<<ap->getRequestSell()<<'\t'<<username.toStdString()<<'\n';

    file.close();
    QMessageBox::information(this,"","Apartment Has been Successfully Added");

    delete ap;

}


void ApartmentForm::on_pushButton_3_clicked()
{
    QString filter="All file (*.*);;Image file (*.png);;Image file (*.jpg)";
    QString file_name=QFileDialog::getOpenFileName(this,"open a file ",QDir::currentPath(),filter);
    ap->h.setPic(file_name);
}

void ApartmentForm::on_pushButton_2_clicked()
{
    close();
    bulding *b23=new bulding(username);
    b23->show();
}
