#include "search.h"
#include "ui_search.h"
#include"fstream"
#include"string"
#include"adminform.h"
#include"apartment.h"
#include"south_villa.h"
#include"north_villa.h"
#include"iostream"

search::search(QString a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search)
{
    username=a;
    ui->setupUi(this);
}

search::~search()
{
    delete ui;
}

void search::on_pushButton_2_clicked()
{
    close();
    AdminForm *dfhg=new AdminForm(username);
    dfhg->show();
}
