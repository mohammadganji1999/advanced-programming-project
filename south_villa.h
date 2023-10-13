#ifndef SOUTH_VILLA_H
#define SOUTH_VILLA_H
#include<house.h>

class south_villa:public house
{
    long int areaYard;
    long int areaParking;
    int Nroom;
public:
    south_villa();
    void setAreaYard(long int a){areaYard=a;}
    void setAreaParking(long int a){areaParking=a;}
    void setRoom(int c){Nroom=c;}

    long int getAreaYard(){return areaYard;}
    long int getAreaParking(){return areaYard;}
    int getNroom(){return Nroom;}

    double calArea(){
        double wholearea=areaYard+areaParking+building_area;
        return wholearea;

    }
    double calPrice(){
        double wholeprice=building_area*base_price+areaYard*base_price*0.3+base_price*areaParking*0.15;
        return  wholeprice;

    }


};

#endif // SOUTH_VILLA_H
