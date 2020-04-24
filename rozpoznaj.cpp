#include "rozpoznaj.h"
#include<QDebug>
#include<algorithm>
#include<QMessageBox>

Klawisz *por;
bool porownaj(Klawisz *i,Klawisz *j){return i->odleglosc(por)<j->odleglosc(por);}
bool porownaju(Uzytkownik *i,Uzytkownik*j){return i->ileKlawiszy()<j->ileKlawiszy();}
Rozpoznaj::Rozpoznaj(QGraphicsItem *parent): Dane(parent)
{
    QString d="Witaj rozpoznam cie jesli przepiszesz ponizszy tekst";
    przywitanie->setPlainText(d);
    if(dane->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(dane);
        while(!stream.atEnd())
        {
            QString nazwa=stream.readLine();
            QString sek[2];
            sek[0]=stream.readLine();
            sek[1]=stream.readLine();
            int pomiedzy=stream.readLine().toInt();
            int czas_wcisniecia=stream.readLine().toInt();
            Klawisz *klawisz=new Klawisz(nazwa,sek,pomiedzy,czas_wcisniecia);
            zpliku.insert(zpliku.end(),klawisz);
        }
    }
}

Rozpoznaj::~Rozpoznaj()
{

}

void Rozpoznaj::keyReleaseEvent(QKeyEvent *event)
{
    for(Klawisz *kl:k)
        if(kl->klawisz()==event->text())
        {
            kl->aCW(QTime::currentTime().msecsTo(*time));
            przepisane.insert(przepisane.end(),kl);
            k.removeOne(kl);
        }
    if(t==d) rozpoznanie();
}

void Rozpoznaj::rozpoznanie()
{
    const int k=3;

    for(Klawisz *kl:przepisane)
    {

        por=kl;
        std::sort(zpliku.begin(),zpliku.end(),porownaj);
        int i=0;
        for(Klawisz *d:zpliku)
        {

            if(kl->taSamaSekwencja(d))
            {
                for(Uzytkownik *u:uzytkownicy)
                    if(d->uzytkownik()==u->nazwa())
                    {
                        u->kp();
                        break;
                    }
            }
            if(++i>3) break;
        }
    }

    Uzytkownik *u=*std::max_element(uzytkownicy.begin(),uzytkownicy.end(),porownaju);
    //Uzytkownik *a=*u;
    QMessageBox msgBox;
    msgBox.setText("Użytkownik rozpoznazny jako: "+u->nazwa());
    msgBox.exec();
    quit();
quit();
}

