#ifndef RENTFILE_H
#define RENTFILE_H
#include "file.h"

class rentFile:public file
{
protected:

    int month;

public:
    rentFile();

    void setMonth(int a){month=a;}

    double getMotgage(){return allprice*0.05;}
    double getRent(){return allprice*0.01;}
    int getMonth(){return month;}

    double finalprice(){return  getRent()*month+getMotgage()*(1+comission);}
};

#endif // RENTFILE_H
