<<<<<<< HEAD
#include "dane.h"
#include"klawiatura.h"
#include<QTime>
#include<QTextCursor>
#include<ctime>
#include<QFile>
#include<QTextStream>


extern Klawiatura *w;
Dane::Dane(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    time=new QTime(QTime::currentTime());
    setDefaultTextColor(Qt::green);
    setFont(QFont("comic sans",20));
    setTextWidth(w->width());
    QFile data;
    data.setFileName(":/text/do_przepisania.txt");
    data.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream f(&data);
    t="Przepisz podany tekst:\n";
    t+=f.readAll();
    t+="\nPrzepisany tekst:\n";
    f.seek(0);
    setPlainText(t);


}

void Dane::keyPressEvent(QKeyEvent *event)
{
    Klawisz *klawisz=new Klawisz;
    klawisz->t=event->key();
    klawisz->x=poprzedni-QTime::currentTime().msecsTo(*time);
    poprzedni=QTime::currentTime().msecsTo(*time);
    klawisz->v=QTime::currentTime().msecsTo(*time);
    if(event->key()==Qt::Key_Backspace)
    {
        t=t.remove(t.size()-1,1);
        setPlainText(t);
    }
    else k.insert(k.end(),klawisz);
}

void Dane::keyReleaseEvent(QKeyEvent *event)
{
    for(Klawisz *kl:k)
        if(kl->t==event->key())
        {
            kl->v-=QTime::currentTime().msecsTo(*time);
            t+=kl->t;
            t+=" "+QString::number(kl->v)+" "+QString::number(kl->x)+" ";
            setPlainText(t);
            wyjscie.insert(wyjscie.end(),kl);
            k.removeOne(kl);

        }
}
=======
#include "dane.h"
#include"klawiatura.h"
#include<QTime>
#include<QTextCursor>
#include<ctime>
//Siema 

extern Klawiatura *w;
Dane::Dane(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    time=new QTime(QTime::currentTime());
    setDefaultTextColor(Qt::green);
    setFont(QFont("comic sans",20));
    setTextWidth(w->width());

}

void Dane::keyPressEvent(QKeyEvent *event)
{
    Klawisz *klawisz=new Klawisz;
    klawisz->t=event->key();
    klawisz->x=poprzedni-QTime::currentTime().msecsTo(*time);
    poprzedni=QTime::currentTime().msecsTo(*time);
    klawisz->v=QTime::currentTime().msecsTo(*time);
    if(event->key()==Qt::Key_Backspace)
    {
        t=t.remove(t.size()-1,1);
        setPlainText(t);
    }
    else k.insert(k.end(),klawisz);
}

void Dane::keyReleaseEvent(QKeyEvent *event)
{
    for(Klawisz *kl:k)
        if(kl->t==event->key())
        {
            kl->v-=QTime::currentTime().msecsTo(*time);
            t+=kl->t;
            t+=" "+QString::number(kl->v)+" "+QString::number(kl->x)+" ";
            setPlainText(t);
            wyjscie.insert(wyjscie.end(),kl);
            k.removeOne(kl);

        }
}
>>>>>>> 7f06b341c3ecad938f0624a64641f2abdf3149f0
