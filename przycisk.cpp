#include "przycisk.h"
#include<QGraphicsTextItem>
#include<QBrush>

//tworzenie nowego przycisku
Przycisk::Przycisk(QString nazwa,QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/button.png").scaled(rozmiar,rozmiar));
    text=new QGraphicsTextItem(nazwa,this);
    int xPos = boundingRect().width()/2-text->boundingRect().width()/2;
    int yPos = boundingRect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
    setAcceptHoverEvents(true);
}

//co się dzieje po kliknięciu dowolnym przyciskiem myszy w obiekt
void Przycisk::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

//co się dzieje po najechaniu kursora myszy na obiekt
void Przycisk::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setPixmap(QPixmap(":/images/button1.png").scaled(rozmiar,rozmiar));
}

//co się dzieje po wyjściu kursora myszy poza obiekt
void Przycisk::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setPixmap(QPixmap(":/images/button.png").scaled(rozmiar,rozmiar));
}
