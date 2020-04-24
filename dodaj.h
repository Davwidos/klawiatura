#ifndef DODAJ_H
#define DODAJ_H
#include"dane.h"

class Dodaj:public Dane
{
    Q_OBJECT
public:
    Dodaj(QGraphicsItem *parent=0);
    ~Dodaj();
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // DODAJ_H
