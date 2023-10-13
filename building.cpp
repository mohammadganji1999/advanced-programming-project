#include "building.h"
#include "ui_building.h"
#include"QMessageBox"
#include"apartmentformedit.h"
#include"northvillaformedit.h"
#include"southvillaformedit.h"
#include"adminform.h"
Building::Building(QString a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Building)
{
    ui->setupUi(this);
    username = a;
}

Building::~Building()
{
    delete ui;
}

void Building::on_pushButton_clicked()
{
 close();
 NorthVillaFormEdit *nvfe = new NorthVillaFormEdit(username);
 nvfe->show();
}

void Building::on_pushButton_2_clicked()
{
    close();
    ApartmentFormEdit *bas = new ApartmentFormEdit(username);
    bas->show();
}

void Building::on_pushButton_3_clicked()
{
    close();
    SouthVillaFormEdit *svfe = new SouthVillaFormEdit(username);
    svfe->show();
}

void Building::on_pushButton_4_clicked()
{
    close();
    AdminForm *A4=new AdminForm(username);
    A4->show();
}
