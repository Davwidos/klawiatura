#ifndef PRZYCISK_H
#define PRZYCISK_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include<QPixmap>
class Przycisk:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Przycisk(QString nazwa,QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem *text;
    int rozmiar=150;
};
#endif // PRZYCISK_H
