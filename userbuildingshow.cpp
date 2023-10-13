#include "userbuildingshow.h"
#include "ui_userbuildingshow.h"
#include"userform.h"
#include"fstream"
#include"iostream"
#include"QMessageBox"
#include"QPixmap"
#include"apartment.h"
#include"south_villa.h"
#include"north_villa.h"
#include"QVector"
#include"rentfile.h"
#include"sellfile.h"
#include"QtDebug"

struct ad{
    int WholeArea;
    std::string Street,User;
    double FinalPrice;
};
UserBuildingShow::UserBuildingShow(QString a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserBuildingShow)
{
    ui->setupUi(this);
    username=a;
}

UserBuildingShow::~UserBuildingShow()
{
    delete ui;
}


void UserBuildingShow::on_pushButton_2_clicked()
{

    close();
    UserForm *uyi=new UserForm(username);
    uyi->show();

}


void UserBuildingShow::on_ShowBtn_clicked()
{
    if(ui->filecmb->currentIndex()==0){
        if(ui->housecmb->currentIndex()==0){
                    ui->txted->clear();
        std::ofstream file10("rentfiles.txt",std::ios::app);
        file10.close();
        ui->txted->append("House Type\t\tMortgage\t\tRent\t\tPrice\t\tArea\t\tStreet");
        std::string a1,a2,a3,a4,a5,a6,a7,a8,a9;
        std::ifstream dile("rentfiles.txt");
        int j=0;
        while(!dile.eof()){
            dile>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9;
            j++;
        }
        dile.close();

        std::ifstream file("rentfiles.txt");
       for(int i=0;i<j-1;i++){
        std::string Type;
       double mrtgage,rentpay;
       int month;
        double fprice;
        int wholearea;
        std::string street,user,useruser;
        file>>Type>>mrtgage>>rentpay>>month>>fprice>>wholearea>>street>>user>>useruser;

        //north villa fields
        int buildarea,frontyard,backyard,nroom;
        std::string pictur;
        int baseprice;
        std::string address,username2;
        int rent,reqrent,sell,reqsell;
        std::ifstream hile("northvilla.txt");
        int h=0;
        while (!hile.eof()) {
            hile>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
            h++;
        }

        std::ifstream nile("northvilla.txt");
        for(int g=0;g<h-1;g++){
        nile>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
        int AREA = frontyard+backyard+buildarea;
        if(Type=="North"&&reqrent==0&&reqsell==0&&sell==0&&rent==0&&AREA==wholearea&&street==address){
        QString Show=QString::fromStdString(Type)+"\t\t"+QString::number(mrtgage)+"\t\t"+QString::number(rentpay)+"\t\t"+QString::number(fprice,'f',3)+
                "\t\t"+QString::number(wholearea)+"\t\t"+QString::fromStdString(street);
        ui->txted->append(Show);
    }
        }
            nile.close();
    }
        file.close();

    }
        else if(ui->housecmb->currentIndex()==1){
                    ui->txted->clear();
            std::ofstream file10("rentfiles.txt",std::ios::app);
            file10.close();
            ui->txted->append("House Type\t\tMortgage\t\tRent\t\tPrice\t\tArea\t\tStreet");
            std::string a1,a2,a3,a4,a5,a6,a7,a8,a9;
            std::ifstream dile("rentfiles.txt");
            int j=0;
            while(!dile.eof()){
                dile>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9;
                j++;
            }
            dile.close();

            std::ifstream file("rentfiles.txt");
           for(int i=0;i<j-1;i++){
            std::string Type;
           double mrtgage,rentpay;
           int month;
            double fprice;
            int wholearea;
            std::string street,user,useruser;
            file>>Type>>mrtgage>>rentpay>>month>>fprice>>wholearea>>street>>user>>useruser;

            //south villa fields
            int buildarea,frontyard,backyard,nroom;
            std::string pictur;
            int baseprice;
            std::string address,username2;
            int rent,reqrent,sell,reqsell;
            std::ifstream hile("southvilla.txt");
            int h=0;
            while (!hile.eof()) {
                hile>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
                h++;
            }

            std::ifstream nile("southvilla.txt");
            for(int g=0;g<h-1;g++){
            nile>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
            int AREA = frontyard+backyard+buildarea;
            if(Type=="South"&&reqrent==0&&reqsell==0&&sell==0&&rent==0&&AREA==wholearea&&street==address){
            QString Show=QString::fromStdString(Type)+"\t\t"+QString::number(mrtgage)+"\t\t"+QString::number(rentpay)+"\t\t"+QString::number(fprice,'f',3)+
                    "\t\t"+QString::number(wholearea)+"\t\t"+QString::fromStdString(street);
            ui->txted->append(Show);
        }
            }
                nile.close();
        }
            file.close();

        }

        else {
            ui->txted->clear();
            std::ofstream file10("rentfiles.txt",std::ios::app);
            file10.close();
            ui->txted->append("House Type\t\tMortgage\t\tRent\t\tPrice\t\tArea\t\tStreet");
            std::string a1,a2,a3,a4,a5,a6,a7,a8,a9;
            std::ifstream dile("rentfiles.txt");
            int j=0;
            while(!dile.eof()){
                dile>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9;
                j++;
            }
            dile.close();

            std::ifstream sile("rentfiles.txt");
           for(int i=0;i<j-1;i++){
            std::string Type;
            double mrtgage,rentpay;
            int month;
            double fprice;
            int wholearea;
            std::string street,user,useruser;
            sile>>Type>>mrtgage>>rentpay>>month>>fprice>>wholearea>>street>>user>>useruser;

            std::ifstream file("apartment.txt",std::ios::in);

            int buildarea,baseprice1;

            int elevator1;
            int apfloor1;
            std::string appic;
            std::string sstreet;
            int floor;
            std::string hpic;
            int rooms,hbuildarea1;
            std::string bp;
            int rent,rqrent,sell,rqsell;
            std::string usern;
            std::string a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15;
            int j=0;
            while(!file.eof()){
                file>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9>>a10>>a11>>a12>>a13>>a14>>a15>>usern;
                j++;
            }
            file.close();
            std::ifstream wile("apartment.txt",std::ios::in);
            for(int f=0;f<j-1;f++){
                 wile>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9>>a10>>a11>>a12>>a13>>a14>>a15>>usern;

                buildarea = QString::fromStdString(a1).toInt();
                baseprice1 = QString::fromStdString(a2).toInt();
                elevator1 = QString::fromStdString(a3).toInt();
                apfloor1 =  QString::fromStdString(a4).toInt();
                appic = a5;
                sstreet = a6;
                floor =  QString::fromStdString(a7).toInt();
                hpic = a8;
                rooms =  QString::fromStdString(a9).toInt();
                hbuildarea1 = QString::fromStdString(a10).toInt();
                bp = a11;
                rent = QString::fromStdString(a12).toInt();
                rqrent = QString::fromStdString(a13).toInt();
                sell = QString::fromStdString(a14).toInt();
                rqsell = QString::fromStdString(a15).toInt();
                int AREA = hbuildarea1;
                 if(Type=="Apartment"&&rqrent==0&&rqsell==0&&sell==0&&rent==0&&AREA==wholearea&&street==sstreet){
                     QString Show=QString::fromStdString(Type)+"\t\t"+QString::number(mrtgage,'f',0)+"\t\t"+QString::number(rentpay,'f',0)+"\t\t"+QString::number(fprice,'f',3)+
                             "\t"+QString::number(wholearea)+"\t\t"+QString::fromStdString(street);
                     ui->txted->append(Show);
                 }
            }
           wile.close();
           }sile.close();
        }

    }








    else {
        if(ui->housecmb->currentIndex()==0){
                    ui->txted->clear();
        std::ofstream file10("sellfiles.txt",std::ios::app);
        file10.close();
        ui->txted->append("House Type\t\tCondition\t\tPrice\t\tArea\t\tStreet");
        std::string a1,a2,a3,a4,a5,a6,a7;
        std::ifstream dile("sellfiles.txt");
        int j=0;
        while(!dile.eof()){
            dile>>a1>>a2>>a3>>a4>>a5>>a6>>a7;
            j++;
        }
        dile.close();

        std::ifstream file("sellfiles.txt");
       for(int i=0;i<j-1;i++){
        std::string Type,CON;
        double fprice;
        int wholearea;
        std::string street,user,useruser;
        file>>Type>>CON>>fprice>>wholearea>>street>>user>>useruser;

        //north villa fields
        int buildarea,frontyard,backyard,nroom;
        std::string pictur;
        int baseprice;
        std::string address,username2;
        int rent,reqrent,sell,reqsell;
        std::ifstream hile("northvilla.txt");
        int h=0;
        while (!hile.eof()) {
            hile>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
            h++;
        }

        std::ifstream nile("northvilla.txt");
        for(int g=0;g<h-1;g++){
        nile>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
        int AREA = frontyard+backyard+buildarea;
        if(Type=="North"&&reqsell==0&&reqrent==0&&sell==0&&rent==0&&AREA==wholearea&&street==address){
        QString Show=QString::fromStdString(Type)+"\t\t"+QString::fromStdString(CON)+"\t\t"+QString::number(fprice,'f',3)+
                "\t\t"+QString::number(wholearea)+"\t\t"+QString::fromStdString(street);
        ui->txted->append(Show);
    }
        }
            nile.close();
    }
        file.close();

    }
        else if(ui->housecmb->currentIndex()==1){
                    ui->txted->clear();
            std::ofstream file10("sellfiles.txt",std::ios::app);
            file10.close();
            ui->txted->append("House Type\t\tCondition\t\tPrice\t\tArea\t\tStreet");
            std::string a1,a2,a3,a4,a5,a6,a7;
            std::ifstream dile("sellfiles.txt");
            int j=0;
            while(!dile.eof()){
                dile>>a1>>a2>>a3>>a4>>a5>>a6>>a7;
                j++;
            }
            dile.close();

            std::ifstream file("sellfiles.txt");
           for(int i=0;i<j-1;i++){
               std::string Type,CON;
               double fprice;
               int wholearea;
               std::string street,user,useruser;
               file>>Type>>CON>>fprice>>wholearea>>street>>user>>useruser;

               //south villa fields
            int buildarea,frontyard,backyard,nroom;
            std::string pictur;
            int baseprice;
            std::string address,username2;
            int rent,reqrent,sell,reqsell;
            std::ifstream hile("southvilla.txt");
            int h=0;
            while (!hile.eof()) {
                hile>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
                h++;
            }

            std::ifstream nile("southvilla.txt");
            for(int g=0;g<h-1;g++){
            nile>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
            int AREA = frontyard+backyard+buildarea;
            if(Type=="South"&&reqsell==0&&reqrent==0&&sell==0&&rent==0&&AREA==wholearea&&street==address){
            QString Show=QString::fromStdString(Type)+"\t\t"+QString::fromStdString(CON)+"\t\t"+QString::number(fprice,'f',3)+
                    "\t\t"+QString::number(wholearea)+"\t\t"+QString::fromStdString(street);
            ui->txted->append(Show);
        }
            }
                nile.close();
        }
            file.close();

        }

        else {
            ui->txted->clear();
            std::ofstream file10("sellfiles.txt",std::ios::app);
            file10.close();
            ui->txted->append("House Type\t\tCondition\t\tPrice\t\tArea\t\tStreet");
            std::string a1,a2,a3,a4,a5,a6,a7;
            std::ifstream dile("sellfiles.txt");
            int j=0;
            while(!dile.eof()){
                dile>>a1>>a2>>a3>>a4>>a5>>a6>>a7;
                j++;
            }
            dile.close();

            std::ifstream sile("sellfiles.txt");
           for(int i=0;i<j-1;i++){
               std::string Type,CON;
               double fprice;
               int wholearea;
               std::string street,user,useruser;
               sile>>Type>>CON>>fprice>>wholearea>>street>>user>>useruser;


            std::ifstream file("apartment.txt",std::ios::in);

            int buildarea,baseprice1;

            int elevator1;
            int apfloor1;
            std::string appic;
            std::string sstreet;
            int floor;
            std::string hpic;
            int rooms,hbuildarea1;
            std::string bp;
            int rent,rqrent,sell,rqsell;
            std::string usern;
            std::string a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15;
            int j=0;
            while(!file.eof()){
                file>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9>>a10>>a11>>a12>>a13>>a14>>a15>>usern;
                j++;
            }
            file.close();
            std::ifstream wile("apartment.txt",std::ios::in);
            for(int f=0;f<j-1;f++){
                 wile>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9>>a10>>a11>>a12>>a13>>a14>>a15>>usern;

                buildarea = QString::fromStdString(a1).toInt();
                baseprice1 = QString::fromStdString(a2).toInt();
                elevator1 = QString::fromStdString(a3).toInt();
                apfloor1 =  QString::fromStdString(a4).toInt();
                appic = a5;
                sstreet = a6;
                floor =  QString::fromStdString(a7).toInt();
                hpic = a8;
                rooms =  QString::fromStdString(a9).toInt();
                hbuildarea1 = QString::fromStdString(a10).toInt();
                bp = a11;
                rent = QString::fromStdString(a12).toInt();
                rqrent = QString::fromStdString(a13).toInt();
                sell = QString::fromStdString(a14).toInt();
                rqsell = QString::fromStdString(a15).toInt();
                int AREA = hbuildarea1;
                 if(Type=="Apartment"&&rqrent==0&&rqsell==0&&sell==0&&rent==0&&AREA==wholearea&&street==sstreet){
                     QString Show=QString::fromStdString(Type)+"\t\t"+QString::fromStdString(CON)+"\t\t"+QString::number(fprice,'f',3)+
                             "\t"+QString::number(wholearea)+"\t\t"+QString::fromStdString(street);
                     ui->txted->append(Show);
                 }
            }
           wile.close();
           }sile.close();
        }

    }



}

void UserBuildingShow::on_pushButton_clicked()
{
    if(ui->filecmb->currentIndex()==0){
        if(ui->housecmb->currentIndex()==0){
        QVector<rentFile> rf;
        QVector<rentFile> nrf;
        QVector<ad> rf1;
        QVector<ad> nrf1;
        QVector<north_villa> nv;
        std::ifstream file("rentfiles.txt");
        std::string Type;
       double mrtgage,rentpay;
       int month;
        double fprice;
        int wholearea;
        std::string street,user,useruser;
        while(!file.eof()){
            file>>Type>>mrtgage>>rentpay>>month>>fprice>>wholearea>>street>>user>>useruser;
            if(Type=="North"){
            rentFile tmp;
            ad temp;
            tmp.setType(QString::fromStdString(Type));
            tmp.setAllprice(rentpay*100);
            tmp.setMonth(month);
            tmp.setUser(QString::fromStdString(useruser));
            temp.WholeArea = wholearea;
            temp.Street=street;
            temp.User = user;
            temp.FinalPrice = fprice;
            rf.push_back(tmp);
            rf1.push_back(temp);
            }
            else {
                rentFile tmp;
                ad temp;
                tmp.setType(QString::fromStdString(Type));
                tmp.setAllprice(rentpay*100);
                tmp.setMonth(month);
                tmp.setUser(QString::fromStdString(useruser));
                temp.WholeArea = wholearea;
                temp.Street=street;
                temp.User = user;
                temp.FinalPrice = fprice;
                nrf.push_back(tmp);
                nrf1.push_back(temp);
            }
        }
        file.close();
        if(rf.size()<=1){
            nrf.pop_back();
            nrf1.pop_back();
        }
        else if(rf[rf.size()-1].getRent()==rf[rf.size()-2].getRent()&&rf[rf.size()-1].getMotgage()==rf[rf.size()-2].getMotgage()&&rf[rf.size()-1].getUser()==rf[rf.size()-2].getUser()
                &&rf1[rf1.size()-1].FinalPrice==rf1[rf1.size()-2].FinalPrice){
             rf.pop_back();
             rf1.pop_back();
        }
        else {
            nrf.pop_back();
            nrf1.pop_back();
        }




        int num =ui->indexspin->value();
        if(num>rf.size()){
            QMessageBox::warning(this,"Error","Entered Number Is Not Valid");
            ui->indexspin->setValue(1);
        }
        else {
            rf[num-1].setMonth(ui->monthspin->value());
            rf[num-1].setUser(username);
            std::ofstream oile("rentfiles.txt",std::ios::trunc);
            for(int i=0;i<rf.size();i++){
                oile<<rf[i].getType().toStdString()<<'\t'<<rf[i].getMotgage()<<'\t'<<rf[i].getRent()<<'\t'<<rf[i].getMonth()<<'\t'<<rf[i].finalprice()<<
                      '\t'<<rf1[i].WholeArea<<'\t'<<rf1[i].Street<<'\t'<<rf1[i].User<<'\t'<<rf[i].getUser().toStdString()<<'\n';
            }
            for(int i=0;i<nrf.size();i++){
                oile<<nrf[i].getType().toStdString()<<'\t'<<nrf[i].getMotgage()<<'\t'<<nrf[i].getRent()<<'\t'<<nrf[i].getMonth()<<'\t'<<nrf[i].finalprice()<<
                      '\t'<<nrf1[i].WholeArea<<'\t'<<nrf1[i].Street<<'\t'<<nrf1[i].User<<'\t'<<nrf[i].getUser().toStdString()<<'\n';
            }

            oile.close();
            int buildarea,frontyard,backyard,nroom;
            std::string pictur;
            int baseprice;
            std::string address,username2;
            int rent,reqrent,sell,reqsell;
            QVector<QString> ADuser;
            std::ifstream nile("northvilla.txt");
            while(!nile.eof()){
                nile>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
                north_villa tmp;
                QString aduser;
                tmp.setBuildingArea(buildarea);
                tmp.setAreafrontyard(frontyard);
                tmp.setAreabackyard(backyard);
                tmp.setRoom(nroom);
                tmp.setPicture(QString::fromStdString(pictur));
                tmp.setBasePrice(baseprice);
                tmp.setAddress("",QString::fromStdString(address),"","");
                tmp.setRent(rent);
                tmp.setRequestRent(reqrent);
                tmp.setSell(sell);
                tmp.setRequestSell(reqsell);
                aduser = QString::fromStdString(username2);
                nv.push_back(tmp);
                ADuser.push_back(aduser);
            }
            nile.close();
            nv.pop_back();
            ADuser.pop_back();
            QString PIC;
            for(int i=0;i<nv.size();i++){
                int ff=nv[i].getAreabackyard()+nv[i].getAreafrontyard()+nv[i].getBuildingArea();
               if(nv[i].getStreet().toStdString()==rf1[num-1].Street&&ff==rf1[num-1].WholeArea&&ADuser[i].toStdString()==rf1[num-1].User){
                    nv[i].setRequestRent(true);
                    PIC=nv[i].getPicture();
                }
             }
                std::ofstream pile("northvilla.txt",std::ios::trunc);
                for(int d = 0;d<nv.size();d++){
                    pile << nv[d].getBuildingArea()<<'\t'<<nv[d].getAreafrontyard()<<"\t"<< nv[d].getAreabackyard()<<"\t"<<nv[d].getNroom()<<"\t"<<nv[d].getPicture().toStdString()
                       <<"\t"<<nv[d].getBasePrice()<<"\t"<<nv[d].getStreet().toStdString()<<'\t'
                      <<nv[d].getRent()<<'\t'<<nv[d].getRequestRent()<<'\t'<<nv[d].getSell()<<'\t'<<nv[d].getRequestSell()<<'\t'<<ADuser[d].toStdString()<<"\n";
                }
                pile.close();
                QMessageBox::information(this,"","Your Request Accepted");
                QPixmap Pix(PIC);
                ui->picturelbl->setPixmap(Pix.scaled(500,500,Qt::KeepAspectRatio));
                nv.clear();
                rf.clear();
                rf1.clear();
                nrf.clear();
                nrf1.clear();
        }
    }
        else if(ui->housecmb->currentIndex()==1){

            QVector<rentFile> rf;
            QVector<rentFile> nrf;
            QVector<ad> rf1;
            QVector<ad> nrf1;
            QVector<south_villa> nv;
            std::ifstream file("rentfiles.txt");
            std::string Type;
           double mrtgage,rentpay;
           int month;
            double fprice;
            int wholearea;
            std::string street,user,useruser;
            while(!file.eof()){
                file>>Type>>mrtgage>>rentpay>>month>>fprice>>wholearea>>street>>user>>useruser;
                if(Type=="South"){
                rentFile tmp;
                ad temp;
                tmp.setType(QString::fromStdString(Type));
                tmp.setAllprice(rentpay*100);
                tmp.setMonth(month);
                tmp.setUser(QString::fromStdString(useruser));
                temp.WholeArea = wholearea;
                temp.Street=street;
                temp.User = user;
                temp.FinalPrice = fprice;
                rf.push_back(tmp);
                rf1.push_back(temp);
                }
                else {
                    rentFile tmp;
                    ad temp;
                    tmp.setType(QString::fromStdString(Type));
                    tmp.setAllprice(rentpay*100);
                    tmp.setMonth(month);
                    tmp.setUser(QString::fromStdString(useruser));
                    temp.WholeArea = wholearea;
                    temp.Street=street;
                    temp.User = user;
                    temp.FinalPrice = fprice;
                    nrf.push_back(tmp);
                    nrf1.push_back(temp);
                }
            }
            file.close();
            if(rf.size()<=1){
                nrf.pop_back();
                nrf1.pop_back();
            }
            else if(rf[rf.size()-1].getRent()==rf[rf.size()-2].getRent()&&rf[rf.size()-1].getMotgage()==rf[rf.size()-2].getMotgage()&&rf[rf.size()-1].getUser()==rf[rf.size()-2].getUser()
                    &&rf1[rf1.size()-1].FinalPrice==rf1[rf1.size()-2].FinalPrice){
                 rf.pop_back();
                 rf1.pop_back();
            }
            else {
                nrf.pop_back();
                nrf1.pop_back();
            }




            int num =ui->indexspin->value();
            if(num>rf.size()){
                QMessageBox::warning(this,"Error","Entered Number Is Not Valid");
                ui->indexspin->setValue(1);
            }
            else {
                rf[num-1].setMonth(ui->monthspin->value());
                rf[num-1].setUser(username);
                std::ofstream oile("rentfiles.txt",std::ios::trunc);
                for(int i=0;i<rf.size();i++){
                    oile<<rf[i].getType().toStdString()<<'\t'<<rf[i].getMotgage()<<'\t'<<rf[i].getRent()<<'\t'<<rf[i].getMonth()<<'\t'<<rf[i].finalprice()<<
                          '\t'<<rf1[i].WholeArea<<'\t'<<rf1[i].Street<<'\t'<<rf1[i].User<<'\t'<<rf[i].getUser().toStdString()<<'\n';
                }
                for(int i=0;i<nrf.size();i++){
                    oile<<nrf[i].getType().toStdString()<<'\t'<<nrf[i].getMotgage()<<'\t'<<nrf[i].getRent()<<'\t'<<nrf[i].getMonth()<<'\t'<<nrf[i].finalprice()<<
                          '\t'<<nrf1[i].WholeArea<<'\t'<<nrf1[i].Street<<'\t'<<nrf1[i].User<<'\t'<<nrf[i].getUser().toStdString()<<'\n';
                }
                //rf.clear();
                oile.close();
                int buildarea,frontyard,backyard,nroom;
                std::string pictur;
                int baseprice;
                std::string address,username2;
                int rent,reqrent,sell,reqsell;
                QVector<QString> ADuser;
                std::ifstream nile("southvilla.txt");
                while(!nile.eof()){
                    nile>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
                    south_villa tmp;
                    QString aduser;
                    tmp.setBuildingArea(buildarea);
                    tmp.setAreaYard(frontyard);
                    tmp.setAreaParking(backyard);
                    tmp.setRoom(nroom);
                    tmp.setPicture(QString::fromStdString(pictur));
                    tmp.setBasePrice(baseprice);
                    tmp.setAddress("",QString::fromStdString(address),"","");
                    tmp.setRent(rent);
                    tmp.setRequestRent(reqrent);
                    tmp.setSell(sell);
                    tmp.setRequestSell(reqsell);
                    aduser = QString::fromStdString(username2);
                    nv.push_back(tmp);
                    ADuser.push_back(aduser);
                }
                nile.close();
                nv.pop_back();
                ADuser.pop_back();
                QString PIC;
                for(int i=0;i<nv.size();i++){
                    int ff=nv[i].getAreaYard()+nv[i].getAreaParking()+nv[i].getBuildingArea();
                    if(nv[i].getStreet().toStdString()==rf1[num-1].Street&&ff==rf1[num-1].WholeArea&&ADuser[i].toStdString()==rf1[num-1].User){
                        nv[i].setRequestRent(true);
                        PIC=nv[i].getPicture();
                    }
                 }
                    std::ofstream pile("southvilla.txt",std::ios::trunc);
                    for(int d = 0;d<nv.size();d++){
                        pile << nv[d].getBuildingArea()<<'\t'<<nv[d].getAreaYard()<<"\t"<< nv[d].getAreaParking()<<"\t"<<nv[d].getNroom()<<"\t"<<nv[d].getPicture().toStdString()
                           <<"\t"<<nv[d].getBasePrice()<<"\t"<<nv[d].getStreet().toStdString()<<'\t'
                          <<nv[d].getRent()<<'\t'<<nv[d].getRequestRent()<<'\t'<<nv[d].getSell()<<'\t'<<nv[d].getRequestSell()<<'\t'<<ADuser[d].toStdString()<<"\n";
                    }
                    pile.close();
                    QMessageBox::information(this,"","Your Request Accepted");
                    QPixmap Pix(PIC);
                    ui->picturelbl->setPixmap(Pix.scaled(500,500,Qt::KeepAspectRatio));
                    nv.clear();
                    rf.clear();
                    rf1.clear();
                    nrf.clear();
                    nrf1.clear();
            }

        }
        ////////////////
        else {
            QVector<rentFile> rf;
            QVector<rentFile> nrf;
            QVector<ad> rf1;
            QVector<ad> nrf1;
            QVector<apartment> nv;
            std::ifstream file("rentfiles.txt");
            std::string Type;
           double mrtgage,rentpay;
           int month;
            double fprice;
            int wholearea;
            std::string street,user,useruser;
            while(!file.eof()){
                file>>Type>>mrtgage>>rentpay>>month>>fprice>>wholearea>>street>>user>>useruser;
                if(Type=="Apartment"){
                rentFile tmp;
                ad temp;
                tmp.setType(QString::fromStdString(Type));
                tmp.setAllprice(rentpay*100);
                tmp.setMonth(month);
                tmp.setUser(QString::fromStdString(useruser));
                temp.WholeArea = wholearea;
                temp.Street=street;
                temp.User = user;
                temp.FinalPrice = fprice;
                rf.push_back(tmp);
                rf1.push_back(temp);
                }
                else {
                    rentFile tmp;
                    ad temp;
                    tmp.setType(QString::fromStdString(Type));
                    tmp.setAllprice(rentpay*100);
                    tmp.setMonth(month);
                    tmp.setUser(QString::fromStdString(useruser));
                    temp.WholeArea = wholearea;
                    temp.Street=street;
                    temp.User = user;
                    temp.FinalPrice = fprice;
                    nrf.push_back(tmp);
                    nrf1.push_back(temp);
                }
            }
            file.close();
            if(rf.size()<=1){
                nrf.pop_back();
                nrf1.pop_back();
            }
            else if(rf[rf.size()-1].getRent()==rf[rf.size()-2].getRent()&&rf[rf.size()-1].getMotgage()==rf[rf.size()-2].getMotgage()&&rf[rf.size()-1].getUser()==rf[rf.size()-2].getUser()
                    &&rf1[rf1.size()-1].FinalPrice==rf1[rf1.size()-2].FinalPrice){
                 rf.pop_back();
                 rf1.pop_back();
            }
            else {
                nrf.pop_back();
                nrf1.pop_back();
            }


            int num =ui->indexspin->value();
            if(num>rf.size()){
                QMessageBox::warning(this,"Error","Entered Number Is Not Valid");
                ui->indexspin->setValue(1);
            }
            else {
                rf[num-1].setMonth(ui->monthspin->value());
                rf[num-1].setUser(username);
                std::ofstream oile("rentfiles.txt",std::ios::trunc);
                for(int i=0;i<rf.size();i++){
                    oile<<rf[i].getType().toStdString()<<'\t'<<rf[i].getMotgage()<<'\t'<<rf[i].getRent()<<'\t'<<rf[i].getMonth()<<'\t'<<rf[i].finalprice()<<
                          '\t'<<rf1[i].WholeArea<<'\t'<<rf1[i].Street<<'\t'<<rf1[i].User<<'\t'<<rf[i].getUser().toStdString()<<'\n';
                }
                for(int i=0;i<nrf.size();i++){
                    oile<<nrf[i].getType().toStdString()<<'\t'<<nrf[i].getMotgage()<<'\t'<<nrf[i].getRent()<<'\t'<<nrf[i].getMonth()<<'\t'<<nrf[i].finalprice()<<
                          '\t'<<nrf1[i].WholeArea<<'\t'<<nrf1[i].Street<<'\t'<<nrf1[i].User<<'\t'<<nrf[i].getUser().toStdString()<<'\n';
                }
                //rf.clear();
                oile.close();
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
                QString aduser;
                QVector<QString> ADuser;
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
                    nv.push_back(tmp);
                    aduser = QString::fromStdString(user);
                    ADuser.push_back(aduser);
                }
                file.close();
                nv.pop_back();
                ADuser.pop_back();

            QString PIC;
            for(int i=0;i<nv.size();i++){
                int ff=nv[i].h.getAreaBuild();
                if(nv[i].getStreet().toStdString()==rf1[num-1].Street&&ff==rf1[num-1].WholeArea&&ADuser[i].toStdString()==rf1[num-1].User){
                    nv[i].setRequestRent(true);
                    PIC=nv[i].h.getPic();
                }
             }
            std::ofstream pile("apartment.txt",std::ios::trunc);
            for(int k = 0;k<nv.size();k++){
                pile<<nv[k].getBuildingArea()<<'\t'<<nv[k].getBasePrice()<<'\t'<<nv[k].getelevator()<<'\t'<<nv[k].getFloor()<<'\t'<<nv[k].getPicture().toStdString()<<'\t'<<nv[k].getStreet().toStdString()<<'\t'<<
                      nv[k].h.getFloornumber()<<'\t'<<nv[k].h.getPic().toStdString()<<'\t'<<nv[k].h.getRooms()<<'\t'<<nv[k].h.getAreaBuild()<<'\t'<<nv[k].h.getBusinessPlan().toStdString()
                      <<'\t'<<nv[k].getRent()<<'\t'<<nv[k].getRequestRent()<<'\t'<<nv[k].getSell()<<'\t'<<nv[k].getRequestSell()<<'\t'<<ADuser[k].toStdString()<<'\n'; ;
            }
            pile.close();
            QMessageBox::information(this,"","Your Request Accepted");
            QPixmap Pix(PIC);
            ui->picturelbl->setPixmap(Pix.scaled(500,500,Qt::KeepAspectRatio));
            nv.clear();
            rf.clear();
            rf1.clear();
            nrf.clear();
            nrf1.clear();
            }
        }

    }



    /////////////
    else {
        if(ui->housecmb->currentIndex()==0){
        QVector<sellFile> rf;
        QVector<sellFile> nrf;
        QVector<ad> rf1;
        QVector<ad> nrf1;
        QVector<north_villa> nv;
        std::ifstream file("sellfiles.txt");
        std::string Type,CON;
        double fprice;
        int wholearea;
        std::string street,user,useruser;
        while(!file.eof()){
            file>>Type>>CON>>fprice>>wholearea>>street>>user>>useruser;
            if(Type=="North"){
            sellFile tmp;
            ad temp;
            tmp.setType(QString::fromStdString(Type));
            tmp.setAllprice(fprice/1.025);
            tmp.setCo(QString::fromStdString(CON));
            tmp.setUser(QString::fromStdString(useruser));
            temp.WholeArea = wholearea;
            temp.Street=street;
            temp.User = user;
            temp.FinalPrice = fprice;
            rf.push_back(tmp);
            rf1.push_back(temp);
            }
            else {
                sellFile tmp;
                ad temp;
                tmp.setType(QString::fromStdString(Type));
                tmp.setAllprice(fprice/1.025);
                tmp.setCo(QString::fromStdString(CON));
                tmp.setUser(QString::fromStdString(useruser));
                temp.WholeArea = wholearea;
                temp.Street=street;
                temp.User = user;
                temp.FinalPrice = fprice;
                nrf.push_back(tmp);
                nrf1.push_back(temp);
            }
        }
        file.close();
        if(rf.size()<=1){
            nrf.pop_back();
            nrf1.pop_back();
        }
        else if(rf[rf.size()-1].getAllprice()==rf[rf.size()-2].getAllprice()&&rf[rf.size()-1].getCo()==rf[rf.size()-2].getCo()
                &&rf[rf.size()-1].getUser()==rf[rf.size()-2].getUser()){
             rf.pop_back();
             rf1.pop_back();
        }
        else {
            nrf.pop_back();
            nrf1.pop_back();
        }




        int num =ui->indexspin->value();
        if(num>rf.size()){
            QMessageBox::warning(this,"Error","Entered Number Is Not Valid");
            ui->indexspin->setValue(1);
        }
        else {
            rf[num-1].setUser(username);
            std::ofstream oile("sellfiles.txt",std::ios::trunc);
            for(int i=0;i<rf.size();i++){
                oile<<rf[i].getType().toStdString()<<'\t'<<rf[i].getCo().toStdString()<<'\t'<<rf[i].finalprice()<<
                      '\t'<<rf1[i].WholeArea<<'\t'<<rf1[i].Street<<'\t'<<rf1[i].User<<'\t'<<rf[i].getUser().toStdString()<<'\n';
            }
            for(int i=0;i<nrf.size();i++){
                oile<<nrf[i].getType().toStdString()<<'\t'<<nrf[i].getCo().toStdString()<<'\t'<<nrf[i].finalprice()<<
                      '\t'<<nrf1[i].WholeArea<<'\t'<<nrf1[i].Street<<'\t'<<nrf1[i].User<<'\t'<<nrf[i].getUser().toStdString()<<'\n';
            }

            oile.close();
            int buildarea,frontyard,backyard,nroom;
            std::string pictur;
            int baseprice;
            std::string address,username2;
            int rent,reqrent,sell,reqsell;
            QVector<QString> ADuser;
            std::ifstream nile("northvilla.txt");
            while(!nile.eof()){
                nile>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
                north_villa tmp;
                QString aduser;
                tmp.setBuildingArea(buildarea);
                tmp.setAreafrontyard(frontyard);
                tmp.setAreabackyard(backyard);
                tmp.setRoom(nroom);
                tmp.setPicture(QString::fromStdString(pictur));
                tmp.setBasePrice(baseprice);
                tmp.setAddress("",QString::fromStdString(address),"","");
                tmp.setRent(rent);
                tmp.setRequestRent(reqrent);
                tmp.setSell(sell);
                tmp.setRequestSell(reqsell);
                aduser = QString::fromStdString(username2);
                nv.push_back(tmp);
                ADuser.push_back(aduser);
            }
            nile.close();
            nv.pop_back();
            ADuser.pop_back();
            QString PIC;
            for(int i=0;i<nv.size();i++){
                int ff=nv[i].getAreabackyard()+nv[i].getAreafrontyard()+nv[i].getBuildingArea();
               if(nv[i].getStreet().toStdString()==rf1[num-1].Street&&ff==rf1[num-1].WholeArea&&ADuser[i].toStdString()==rf1[num-1].User){
                    nv[i].setRequestSell(true);
                    PIC=nv[i].getPicture();
                }
             }
                std::ofstream pile("northvilla.txt",std::ios::trunc);
                for(int d = 0;d<nv.size();d++){
                    pile << nv[d].getBuildingArea()<<'\t'<<nv[d].getAreafrontyard()<<"\t"<< nv[d].getAreabackyard()<<"\t"<<nv[d].getNroom()<<"\t"<<nv[d].getPicture().toStdString()
                       <<"\t"<<nv[d].getBasePrice()<<"\t"<<nv[d].getStreet().toStdString()<<'\t'
                      <<nv[d].getRent()<<'\t'<<nv[d].getRequestRent()<<'\t'<<nv[d].getSell()<<'\t'<<nv[d].getRequestSell()<<'\t'<<ADuser[d].toStdString()<<"\n";
                }
                pile.close();
                QMessageBox::information(this,"","Your Request Accepted");
                QPixmap Pix(PIC);
                ui->picturelbl->setPixmap(Pix.scaled(500,500,Qt::KeepAspectRatio));
                nv.clear();
                rf.clear();
                rf1.clear();
                nrf.clear();
                nrf1.clear();
        }
    }
        else if(ui->housecmb->currentIndex()==1){

            QVector<sellFile> rf;
            QVector<sellFile> nrf;
            QVector<ad> rf1;
            QVector<ad> nrf1;
            QVector<south_villa> nv;
            std::ifstream file("sellfiles.txt");
            std::string Type,CON;
            double fprice;
            int wholearea;
            std::string street,user,useruser;
            while(!file.eof()){
                file>>Type>>CON>>fprice>>wholearea>>street>>user>>useruser;
                if(Type=="South"){
                sellFile tmp;
                ad temp;
                tmp.setType(QString::fromStdString(Type));
                tmp.setAllprice(fprice/1.025);
                tmp.setCo(QString::fromStdString(CON));
                tmp.setUser(QString::fromStdString(useruser));
                temp.WholeArea = wholearea;
                temp.Street=street;
                temp.User = user;
                temp.FinalPrice = fprice;
                rf.push_back(tmp);
                rf1.push_back(temp);
                }
                else {
                    sellFile tmp;
                    ad temp;
                    tmp.setType(QString::fromStdString(Type));
                    tmp.setAllprice(fprice/1.025);
                    tmp.setCo(QString::fromStdString(CON));
                    tmp.setUser(QString::fromStdString(useruser));
                    temp.WholeArea = wholearea;
                    temp.Street=street;
                    temp.User = user;
                    temp.FinalPrice = fprice;
                    nrf.push_back(tmp);
                    nrf1.push_back(temp);
                }
            }
            file.close();
            if(rf.size()<=1){
                nrf.pop_back();
                nrf1.pop_back();
            }
            else if(rf[rf.size()-1].getAllprice()==rf[rf.size()-2].getAllprice()&&rf[rf.size()-1].getCo()==rf[rf.size()-2].getCo()
                    &&rf[rf.size()-1].getUser()==rf[rf.size()-2].getUser()){
                 rf.pop_back();
                 rf1.pop_back();
            }
            else {
                nrf.pop_back();
                nrf1.pop_back();
            }




            int num =ui->indexspin->value();
            if(num>rf.size()){
                QMessageBox::warning(this,"Error","Entered Number Is Not Valid");
                ui->indexspin->setValue(1);
            }
            else {
                rf[num-1].setUser(username);
                std::ofstream oile("sellfiles.txt",std::ios::trunc);
                for(int i=0;i<rf.size();i++){
                    oile<<rf[i].getType().toStdString()<<'\t'<<rf[i].getCo().toStdString()<<'\t'<<rf[i].finalprice()<<
                          '\t'<<rf1[i].WholeArea<<'\t'<<rf1[i].Street<<'\t'<<rf1[i].User<<'\t'<<rf[i].getUser().toStdString()<<'\n';
                }
                for(int i=0;i<nrf.size();i++){
                    oile<<nrf[i].getType().toStdString()<<'\t'<<nrf[i].getCo().toStdString()<<'\t'<<nrf[i].finalprice()<<
                          '\t'<<nrf1[i].WholeArea<<'\t'<<nrf1[i].Street<<'\t'<<nrf1[i].User<<'\t'<<nrf[i].getUser().toStdString()<<'\n';
                }
                //rf.clear();
                oile.close();
                int buildarea,frontyard,backyard,nroom;
                std::string pictur;
                int baseprice;
                std::string address,username2;
                int rent,reqrent,sell,reqsell;
                QVector<QString> ADuser;
                std::ifstream nile("southvilla.txt");
                while(!nile.eof()){
                    nile>>buildarea>>frontyard>>backyard>>nroom>>pictur>>baseprice>>address>>rent>>reqrent>>sell>>reqsell>>username2;
                    south_villa tmp;
                    QString aduser;
                    tmp.setBuildingArea(buildarea);
                    tmp.setAreaYard(frontyard);
                    tmp.setAreaParking(backyard);
                    tmp.setRoom(nroom);
                    tmp.setPicture(QString::fromStdString(pictur));
                    tmp.setBasePrice(baseprice);
                    tmp.setAddress("",QString::fromStdString(address),"","");
                    tmp.setRent(rent);
                    tmp.setRequestRent(reqrent);
                    tmp.setSell(sell);
                    tmp.setRequestSell(reqsell);
                    aduser = QString::fromStdString(username2);
                    nv.push_back(tmp);
                    ADuser.push_back(aduser);
                }
                nile.close();
                nv.pop_back();
                ADuser.pop_back();
                QString PIC;
                for(int i=0;i<nv.size();i++){
                    int ff=nv[i].getAreaYard()+nv[i].getAreaParking()+nv[i].getBuildingArea();
                    if(nv[i].getStreet().toStdString()==rf1[num-1].Street&&ff==rf1[num-1].WholeArea&&ADuser[i].toStdString()==rf1[num-1].User){
                        nv[i].setRequestSell(true);
                        PIC=nv[i].getPicture();
                    }
                 }
                    std::ofstream pile("southvilla.txt",std::ios::trunc);
                    for(int d = 0;d<nv.size();d++){
                        pile << nv[d].getBuildingArea()<<'\t'<<nv[d].getAreaYard()<<"\t"<< nv[d].getAreaParking()<<"\t"<<nv[d].getNroom()<<"\t"<<nv[d].getPicture().toStdString()
                           <<"\t"<<nv[d].getBasePrice()<<"\t"<<nv[d].getStreet().toStdString()<<'\t'
                          <<nv[d].getRent()<<'\t'<<nv[d].getRequestRent()<<'\t'<<nv[d].getSell()<<'\t'<<nv[d].getRequestSell()<<'\t'<<ADuser[d].toStdString()<<"\n";
                    }
                    pile.close();
                    QMessageBox::information(this,"","Your Request Accepted");
                    QPixmap Pix(PIC);
                    ui->picturelbl->setPixmap(Pix.scaled(500,500,Qt::KeepAspectRatio));
                    nv.clear();
                    rf.clear();
                    rf1.clear();
                    nrf.clear();
                    nrf1.clear();
            }

        }
        ////////////////
        else {
            QVector<sellFile> rf;
            QVector<sellFile> nrf;
            QVector<ad> rf1;
            QVector<ad> nrf1;
            QVector<apartment> nv;
            std::ifstream file("sellfiles.txt");
            std::string Type,CON;
            double fprice;
            int wholearea;
            std::string street,user,useruser;
            while(!file.eof()){
                file>>Type>>CON>>fprice>>wholearea>>street>>user>>useruser;
                if(Type=="Apartment"){
                sellFile tmp;
                ad temp;
                tmp.setType(QString::fromStdString(Type));
                tmp.setAllprice(fprice/1.025);
                tmp.setCo(QString::fromStdString(CON));
                tmp.setUser(QString::fromStdString(useruser));
                temp.WholeArea = wholearea;
                temp.Street=street;
                temp.User = user;
                temp.FinalPrice = fprice;
                rf.push_back(tmp);
                rf1.push_back(temp);
                }
                else {
                    sellFile tmp;
                    ad temp;
                    tmp.setType(QString::fromStdString(Type));
                    tmp.setAllprice(fprice/1.025);
                    tmp.setCo(QString::fromStdString(CON));
                    tmp.setUser(QString::fromStdString(useruser));
                    temp.WholeArea = wholearea;
                    temp.Street=street;
                    temp.User = user;
                    temp.FinalPrice = fprice;
                    nrf.push_back(tmp);
                    nrf1.push_back(temp);
                }
            }
            file.close();
            if(rf.size()<=1){
                nrf.pop_back();
                nrf1.pop_back();
            }
            else if(rf[rf.size()-1].getAllprice()==rf[rf.size()-2].getAllprice()&&rf[rf.size()-1].getCo()==rf[rf.size()-2].getCo()
                    &&rf[rf.size()-1].getUser()==rf[rf.size()-2].getUser()){
                 rf.pop_back();
                 rf1.pop_back();
            }
            else {
                nrf.pop_back();
                nrf1.pop_back();
            }


            int num =ui->indexspin->value();
            if(num>rf.size()){
                QMessageBox::warning(this,"Error","Entered Number Is Not Valid");
                ui->indexspin->setValue(1);
            }
            else {
                rf[num-1].setUser(username);
                std::ofstream oile("sellfiles.txt",std::ios::trunc);
                for(int i=0;i<rf.size();i++){
                    oile<<rf[i].getType().toStdString()<<'\t'<<rf[i].getCo().toStdString()<<'\t'<<rf[i].finalprice()<<
                          '\t'<<rf1[i].WholeArea<<'\t'<<rf1[i].Street<<'\t'<<rf1[i].User<<'\t'<<rf[i].getUser().toStdString()<<'\n';
                }
                for(int i=0;i<nrf.size();i++){
                    oile<<nrf[i].getType().toStdString()<<'\t'<<nrf[i].getCo().toStdString()<<'\t'<<nrf[i].finalprice()<<
                          '\t'<<nrf1[i].WholeArea<<'\t'<<nrf1[i].Street<<'\t'<<nrf1[i].User<<'\t'<<nrf[i].getUser().toStdString()<<'\n';
                }
                //rf.clear();
                oile.close();
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
                QString aduser;
                QVector<QString> ADuser;
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
                    nv.push_back(tmp);
                    aduser = QString::fromStdString(user);
                    ADuser.push_back(aduser);
                }
                file.close();
                nv.pop_back();
                ADuser.pop_back();

            QString PIC;
            for(int i=0;i<nv.size();i++){
                int ff=nv[i].h.getAreaBuild();
                if(nv[i].getStreet().toStdString()==rf1[num-1].Street&&ff==rf1[num-1].WholeArea&&ADuser[i].toStdString()==rf1[num-1].User){
                    nv[i].setRequestSell(true);
                    PIC=nv[i].h.getPic();
                }
             }
            std::ofstream pile("apartment.txt",std::ios::trunc);
            for(int k = 0;k<nv.size();k++){
                pile<<nv[k].getBuildingArea()<<'\t'<<nv[k].getBasePrice()<<'\t'<<nv[k].getelevator()<<'\t'<<nv[k].getFloor()<<'\t'<<nv[k].getPicture().toStdString()<<'\t'<<nv[k].getStreet().toStdString()<<'\t'<<
                      nv[k].h.getFloornumber()<<'\t'<<nv[k].h.getPic().toStdString()<<'\t'<<nv[k].h.getRooms()<<'\t'<<nv[k].h.getAreaBuild()<<'\t'<<nv[k].h.getBusinessPlan().toStdString()
                      <<'\t'<<nv[k].getRent()<<'\t'<<nv[k].getRequestRent()<<'\t'<<nv[k].getSell()<<'\t'<<nv[k].getRequestSell()<<'\t'<<ADuser[k].toStdString()<<'\n'; ;
            }
            pile.close();
            QMessageBox::information(this,"","Your Request Accepted");
            QPixmap Pix(PIC);
            ui->picturelbl->setPixmap(Pix.scaled(500,500,Qt::KeepAspectRatio));
            nv.clear();
            rf.clear();
            rf1.clear();
            nrf.clear();
            nrf1.clear();
            }
        }
}
}
