#ifndef FILE_H
#define FILE_H
#include "QString"

class file
{
protected:
    QString Type;
    int id;
    double comission;
    double allprice;
    QString user20;

public:
    file();

    void setType(QString a){Type=a;}
    void setUser(QString a){user20=a;}
    void setId(int a){id=a;}
    void setAllprice(double a){allprice=a;}

    QString getType(){return Type;}
    QString getUser(){return user20;}
    int getId(){return id;}
    double getComission(){return comission;}
    double getAllprice(){return allprice; }


    virtual  double finalprice()=0;
};

#endif // FILE_H
