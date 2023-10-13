#ifndef USERINFO_H
#define USERINFO_H
#include<QString>
#include<QTime>



class userinfo
{    protected:
    QString name;
    QString lastname;
    QString birthday;
    bool active;
    QString username;
    QString password;
    long int currency;
    QTime enter;
    QTime exit;

public:
    userinfo();
    void setname(QString a){name=a;}
    void setlastname(QString a){lastname=a;}
    void setbirth(QString a){birthday = a;}
    void setuser(QString a){username=a;}
    void setpass(QString a){password=a;}
    void setentertime(QTime a){enter=a;}
    void setexittime(QTime a){exit=a;}
    void setcurrency(long int a){currency=a; }

    QString getname(){return name;}
    QString getlastname(){return lastname;}
    QString getbirth(){return birthday;}
    QString getuser(){return username;}
    QString getpass(){return password;}
    QTime getentertime(){return enter;}
    QTime getexittime(){return exit;}
    long int getcurrency(){return currency;}


    void activechange(){active=false;}

};

#endif // USERINFO_H
