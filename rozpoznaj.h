#ifndef ROZPOZNAJ_H
#define ROZPOZNAJ_H
#include"dane.h"

class Rozpoznaj: public Dane
{
    Q_OBJECT
public:
    Rozpoznaj(QGraphicsItem *parent=0);
    ~Rozpoznaj();
    void keyReleaseEvent(QKeyEvent *event);
    void rozpoznanie();
    bool operator() (Klawisz *i,Klawisz *j);
private:
    QList<Klawisz*> przepisane;
    QList<Klawisz*> zpliku;
};

#endif // ROZPOZNAJ_H
