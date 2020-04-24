#include "uzytkownik.h"



Uzytkownik::Uzytkownik(QString m)
{
    n=m;
}

QString Uzytkownik::nazwa()
{
    return n;
}

int Uzytkownik::ileKlawiszy()
{
    return k;
}

void Uzytkownik::kp()
{
    k++;
}
