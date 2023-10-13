#include "bulding.h"
#include "ui_bulding.h"
#include"northvillaform.h"
#include"southvillaform.h"
#include"apartmentform.h"
#include"adminform.h"
bulding::bulding(QString a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bulding)
{
    ui->setupUi(this);
        username=a;
}

bulding::~bulding()
{
    delete ui;
}


void bulding::on_pushButton_clicked()
{
    close();
    NorthVillaForm *NVF = new NorthVillaForm(username);
    NVF->show();

}

void bulding::on_pushButton_3_clicked()
{
    close();
    SouthVillaForm *SVF=new SouthVillaForm(username);
    SVF->show();
}

void bulding::on_pushButton_2_clicked()
{
    close();
    ApartmentForm *AF=new ApartmentForm(username);
    AF->show();

}

void bulding::on_pushButton_4_clicked()
{
    close();
    AdminForm *A2=new AdminForm(username);
    A2->show();
}
