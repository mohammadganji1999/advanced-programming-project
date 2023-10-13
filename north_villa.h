#ifndef NORTH_VILLA_H
#define NORTH_VILLA_H
#include"house.h"

class north_villa:public house
{
    long int areabackyard;
    long int areafrontyard;
    int Nroom;
public:
    north_villa();

    void setAreabackyard(long int a){areabackyard=a;}
    void setAreafrontyard(long int b){areafrontyard=b;}
    void setRoom(int c){Nroom=c;}

    long int getAreabackyard(){return areabackyard;}
    long int getAreafrontyard(){return areafrontyard;}
    int getNroom(){return Nroom;}
    double calArea(){
        double wholearea=building_area+areabackyard+areafrontyard;
        return wholearea;
    }
    double calPrice(){
        double whole = base_price*building_area+base_price*areafrontyard*0.3+base_price*areabackyard*0.15;

        return whole;
    }


};
#endif // NORTH_VILLA_H
