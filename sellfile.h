#ifndef SELLFILE_H
#define SELLFILE_H
#include "file.h"
#include "QString"

class sellFile:public file
{
   QString condition;
public:
    sellFile();
    void setCo(QString a){condition=a;}

    QString getCo(){return condition;}

    double finalprice(){return allprice*(1+comission);}
};

#endif // SELLFILE_H
