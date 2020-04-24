#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H
#include<QString>

class Uzytkownik
{
public:
    Uzytkownik(QString);
    QString nazwa();
    int ileKlawiszy();
    void kp();
private:
    QString n;
    int k=0;
};

#endif // UZYTKOWNIK_H
