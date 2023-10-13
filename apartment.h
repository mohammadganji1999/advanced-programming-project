#ifndef APARTMENT_H
#define APARTMENT_H
#include"house.h"
#include"QString"
#include"QFileDialog"
#include<QVector>

class home{

    int floor;
    QString pic;
    int rooms;
    int areabuild;
    QString businessplan;

public:
void setFloornumber(int f){floor=f;}
void setRooms(int r){rooms=r;}
void setAreaBuild(int ab){areabuild=ab;}
void setBusinessPlan(QString bp){businessplan=bp;}
void setPic(QString p){pic = p;}

int getFloornumber(){return floor;}
int getRooms(){return rooms;}
int getAreaBuild(){return areabuild;}
QString getBusinessPlan(){return businessplan;}
QString getPic(){return pic;}

};

class apartment:public house
{
    bool elevator;
    int floor;
public:
    apartment();
    void setFloor(int f){floor=f;}
    void setelevator(bool e){elevator=e;}


    int getelevator(){return elevator;}
    int getFloor(){return floor;}

    home h;

    double calArea(){
        double wholearea=floor*building_area;
        return wholearea;
    }
    double calPrice(){

        double wholeprice = calArea()*base_price*0.8;
        return wholeprice;
    }
    double CALPrice(){
        double home=base_price*h.getAreaBuild();
        home+=home*h.getFloornumber()*0.05+home*h.getRooms()*0.08;
        if(h.getBusinessPlan()=="Business"){
            home+=home*0.5;
        }
        else if(h.getBusinessPlan()=="Official"){
            home+=home*0.3;
        }

        if(elevator){
            home+=home*0.02;
        }
        return home;
    }
};

#endif // APARTMENT_H
