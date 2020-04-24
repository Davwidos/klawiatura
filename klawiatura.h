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
#include"dodaj.h"
#include"rozpoznaj.h"
#include<QMediaPlayer>
class Klawiatura : public QGraphicsView
{
    Q_OBJECT

public:
    Klawiatura(QWidget *parent=0);
    ~Klawiatura();
    void clear();
    Przycisk* dodajprzycisk(QString nazwa,int ktory);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
public slots:
    void displayMenu();
    void dodawanie();
    void rozpoznanie();
    void wyjscie();
    void zpliku();
private:
    QGraphicsScene *scene;
    QList<Dane*> dane;
    QMediaPlayer *muzyka;
};
#endif // GRA_H
