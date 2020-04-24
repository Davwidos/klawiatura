#ifndef PRZECHOWYWANIE_H
#define PRZECHOWYWANIE_H
#include<QString>
#include<QTextStream>
#include<QFile>

class Klawisz
{
public:
    Klawisz(QString,QString[],int=0,int=0,QFile*file=0);
    ~Klawisz();
    double odleglosc(Klawisz*);
    void zapisywanie();
    void aP(int);
    void aCW(int);
    QString klawisz();
    QString uzytkownik();
    bool taSamaSekwencja(Klawisz *kl);

private:
    QString user;
    QString sekwencja[2];
    int pomiedzy;
    int czas_wcisniecia;
    QFile *dowolne;
};
#endif // PRZECHOWYWANIE_H
