#ifndef DANE_H
#define DANE_H
#include<QKeyEvent>
#include<QGraphicsItem>
#include<QTimer>
#include<QTime>

struct Klawisz
{
    char t;
    int v;
    int x;
};
class Dane: public QGraphicsTextItem
{
    Q_OBJECT
public:
    Dane(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void porownanie();
private:
    QTime *time;
    QList<Klawisz*> k;
    QList<Klawisz*> wyjscie;
    QList<Klawisz*> doPorownania;
    QString t;
    int poprzedni=0;
};

#endif // DANE_H
