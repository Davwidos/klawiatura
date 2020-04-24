#include "klawisz.h"
#include <cmath>

Klawisz::Klawisz(QString a,QString b[], int c, int t,QFile* file)
{
    user = a;
    sekwencja[0] = b[0];
    sekwencja[1] = b[1];
    pomiedzy = c;
    czas_wcisniecia = t;
    dowolne = file;
}

Klawisz::~Klawisz()
{
}

double Klawisz::odleglosc(Klawisz *a)
{
    int x = a->pomiedzy-pomiedzy;
    int y = a->czas_wcisniecia-czas_wcisniecia;
    return sqrt(x*x+y*y);
}

void Klawisz::zapisywanie()
{
    if(dowolne->open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream stream(dowolne);
        stream<<user<<"\n";
        stream<<sekwencja[0]<<"\n"<<sekwencja[1]<<"\n";
        stream<<pomiedzy<<"\n";
        stream<<czas_wcisniecia<<"\n";
        dowolne->close();
    }
}

void Klawisz::aP(int a)
{
    pomiedzy-=a;
}

void Klawisz::aCW(int a)
{
    czas_wcisniecia-=a;
}

QString Klawisz::klawisz()
{
    return sekwencja[1];
}

QString Klawisz::uzytkownik()
{
    return user;
}

bool Klawisz::taSamaSekwencja(Klawisz *kl)
{
    if(kl->sekwencja[0]==sekwencja[0] && kl->sekwencja[1]==sekwencja[1]) return true;
    return false;
}
