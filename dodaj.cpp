#include "dodaj.h"
#include<QInputDialog>
#include"klawiatura.h"
#include<QMessageBox>
extern Klawiatura *w;
Dodaj::Dodaj(QGraphicsItem *parent): Dane(parent)
{
    QInputDialog a;
    user = a.getText(w,tr("Wprowadzanie nazwy"),tr("Podaj nazwe uzytkownika"));
    bool test=false;
    for(Uzytkownik *u:uzytkownicy) if(u->nazwa()==user) test=true;
    QString d;
    if(test) d="Witaj ponownie "+user+" przepisz ten przepisz ponizszy tekst abym mogl cie lepiej rozpoznawac";
    else
    {
        d="Witaj "+user+" przepisz poniższy tekst abym mogl cie rozpoznac:";
        if(u->open(QIODevice::WriteOnly | QIODevice::Append))
        {
            QTextStream stream(u);
            stream<<user<<"\n";
            u->close();
        }
    }
    przywitanie->setPlainText(d);
}

Dodaj::~Dodaj()
{

}
void Dodaj::keyReleaseEvent(QKeyEvent *event)
{
    for(Klawisz *kl:k)
        if(kl->klawisz()==event->text())
        {
            kl->aCW(QTime::currentTime().msecsTo(*time));
            kl->zapisywanie();
            k.removeOne(kl);
        }
    if(t==d)
    {
        QMessageBox msgBox;
        msgBox.setText("Użytkownik dodany.");
        msgBox.exec();
        quit();
    }
}
