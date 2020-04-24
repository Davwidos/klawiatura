#include "dane.h"
#include"klawiatura.h"
#include<QTime>
#include<QTextCursor>
#include<QDir>
#include<QStandardPaths>
extern Klawiatura *w;

extern Klawiatura *w;
Dane::Dane(QGraphicsItem *parent):QObject(), QGraphicsItemGroup(parent)
{    
    przywitanie=new QGraphicsTextItem(this);
    przywitanie->setDefaultTextColor(Qt::green);
    przywitanie->setFont(QFont("comic sans",20));
    przywitanie->setTextWidth(w->width());

    doprzepisania=new QGraphicsTextItem(this);
    doprzepisania->setDefaultTextColor(Qt::blue);
    doprzepisania->setFont(QFont("comic sans",20));
    doprzepisania->setTextWidth(w->width());

    przepisane=new QGraphicsTextItem(this);
    przepisane->setDefaultTextColor(Qt::red);
    przepisane->setFont(QFont("comic sans",20));
    przepisane->setTextWidth(w->width());

    time=new QTime(QTime::currentTime());
    QFile prze(":/text/do_przepisania.txt");
    prze.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream przepisz(&prze);
    d=przepisz.readAll();
    doprzepisania->setY(przywitanie->y()+przywitanie->boundingRect().height()+5);
    doprzepisania->setPlainText(d);
    przepisane->setY(doprzepisania->y()+doprzepisania->boundingRect().height()+5);
    QString path=*QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).begin();
    dane=new QFile(path+"/Klawiatura/dane.txt");
    u=new QFile(path+"/Klawiatura/uzytkownicy.txt");
    if(u->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(u);
        while(!stream.atEnd())
        {
            Uzytkownik *uzytkownik=new Uzytkownik(stream.readLine());
            uzytkownicy.insert(uzytkownicy.end(),uzytkownik);
        }
        u->close();
    }
}

Dane::~Dane()
{
    delete time;
    delete przywitanie;
    delete doprzepisania;
    delete przepisane;
    delete dane;
    delete u;

}

void Dane::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Backspace)
    {
        t=t.remove(t.size()-1,1);
        przepisane->setPlainText(t);
        return;
    }
    if(!event->text().isEmpty())
    {
        QString sek[]={poprzedni_klawisz,event->text()};
        poprzedni_klawisz=event->text();
        Klawisz *klawisz=new Klawisz(user,sek,poprzedni,QTime::currentTime().msecsTo(*time),dane);
        klawisz->aP(QTime::currentTime().msecsTo(*time));
        if(poprzedni) k.insert(k.end(),klawisz);
        poprzedni=QTime::currentTime().msecsTo(*time);
        t+=event->text();
        przepisane->setPlainText(t);
    }

}

void Dane::quit()
{
    w->displayMenu();
}




