#ifndef DANE_H
#define DANE_H
#include<QKeyEvent>
#include<QGraphicsItem>
#include<QTimer>
#include<QTime>
#include<QString>
#include"klawisz.h"
#include<QTextStream>
#include"uzytkownik.h"

class Dane: public QObject,public QGraphicsItemGroup
{
    Q_OBJECT
public:
    Dane(QGraphicsItem *parent=0);
    ~Dane();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event)=0;
    void quit();
protected:
    QGraphicsTextItem *przywitanie;
    QGraphicsTextItem *doprzepisania;
    QGraphicsTextItem *przepisane;
    QTime *time;
    QList<Klawisz*> k;
    QList<Uzytkownik*> uzytkownicy;
    QString t;
    QString d;
    int poprzedni=0;
    QString poprzedni_klawisz=0;
    QString user;
    QFile *dane;
    QFile *u;
};

#endif // DANE_H
