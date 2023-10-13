#ifndef HOUSE_H
#define HOUSE_H
#include<QString>
#include<QFileDialog>

struct address{
    QString city,street,alley,plaque;
};

class house
{   protected:
    long int building_area;
    int base_price;

    address Ad;
    QString picture;
    QString AdminUsername;
    bool requestRent;
    bool requestSell;
    bool rent;
    bool sell;
public:
    house();
    void setBuildingArea(long int a){building_area = a;}
    void setBasePrice(int a){base_price=a;}
    void setAddress(QString _c,QString _s,QString _a,QString _p ){ Ad.city=_c;Ad.alley=_a;Ad.plaque=_p;Ad.street=_s;}
    void setPicture(QString pic){picture=pic;}
    void setRequestRent(bool bo){requestRent=bo;}
    void setRequestSell(bool bo){requestSell=bo;}
    void setRent(bool bo){rent = bo;}
    void setSell(bool bo){sell = bo;}

    long int getBuildingArea(){return building_area;}
    int getBasePrice(){return base_price;}
    QString getStreet(){return Ad.street;}
    QString getPicture(){return  picture;}
    int getRequestRent(){return  requestRent;}
    int getRequestSell(){return requestSell;}
    int getRent(){return rent;}
    int getSell(){return sell;}


    virtual double calArea()=0;
    virtual double calPrice()=0;

};

#endif // HOUSE_H
