#ifndef GRA_H
#define GRA_H

#include <QWidget>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QApplication>
#include<QDesktopWidget>
#include<QList>
#include<QKeyEvent>
#include"przycisk.h"
#include"dane.h"

class Klawiatura : public QGraphicsView
{
    Q_OBJECT

public:
    Klawiatura(QWidget *parent=0);
    void displayMenu();
    void clear();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
public slots:
    void start();
    void wyjscie();
private:
    QGraphicsScene *scene;
    QList<Dane*> dane;
};
#endif // GRA_H
