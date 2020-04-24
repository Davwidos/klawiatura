#include "klawiatura.h"
#include<QBrush>
#include<QMediaPlayer>
#include<QDebug>
#include<QUrl>
#include<QFileDialog>
#include<QStandardPaths>
#include<QFile>
#include<QTextStream>

Klawiatura::Klawiatura(QWidget *parent) :QGraphicsView(parent)
{
    QRect rec=QApplication::desktop()->screenGeometry();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,rec.width(),rec.height());
    QImage image(":/images/keyboard.jpg");
    image=image.scaled(rec.width(),rec.height());
    setBackgroundBrush(QBrush(image));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(rec.width(),rec.height());
    setScene(scene);
    muzyka = new QMediaPlayer();
    muzyka->setMedia(QUrl("qrc:/sounds/wiedmin.mp3"));

    QString path=*QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).begin();
    if(!QDir(path+"/Klawiatura").exists()) QDir(path).mkdir("Klawiatura");

}

Klawiatura::~Klawiatura()
{
    delete scene;
    delete muzyka;
}
void Klawiatura::displayMenu()
{
    clear();
    Przycisk *przycisk=dodajprzycisk("Rozpoznanie",0);
    connect(przycisk,SIGNAL(clicked()),this,SLOT(rozpoznanie()));
    przycisk=dodajprzycisk("Dodaj",1);
    connect(przycisk,SIGNAL(clicked()),this,SLOT(dodawanie()));
    przycisk=dodajprzycisk("Dodaj z pliku",2);
    connect(przycisk,SIGNAL(clicked()),this,SLOT(zpliku()));
    przycisk=dodajprzycisk("Wyjscie",3);
    connect(przycisk,SIGNAL(clicked()),this,SLOT(wyjscie()));


    //muzyka->play();*
}

void Klawiatura::clear()
{
    dane.clear();
    for(QGraphicsItem *n:items())
        if(n->parentItem()==0)
        {
            scene->removeItem(n);
            delete n;
        }
}

Przycisk* Klawiatura::dodajprzycisk(QString nazwa, int ktory)
{
    Przycisk *przycisk=new Przycisk(nazwa);
    przycisk->setX(this->width()/2-przycisk->boundingRect().width()/2);
    scene->addItem(przycisk);
    przycisk->setY(ktory*przycisk->boundingRect().height());
    return przycisk;
}

void Klawiatura::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape) displayMenu();
    for(Dane *d:dane) d->keyPressEvent(event);
}

void Klawiatura::keyReleaseEvent(QKeyEvent *event)
{
    for(Dane *d:dane) d->keyReleaseEvent(event);
}


void Klawiatura::dodawanie()
{
    clear();
    Dodaj *d=new Dodaj;
    dane.insert(dane.end(),d);
    scene->addItem(d);
}

void Klawiatura::rozpoznanie()
{
    clear();
    Rozpoznaj *d=new Rozpoznaj;
    dane.insert(dane.end(),d);
    scene->addItem(d);
}
void Klawiatura::wyjscie()
{
    QApplication::quit();
}

void Klawiatura::zpliku()
{
    QString p=*QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).begin();
    QString file=QFileDialog::getOpenFileName(this,"Otworz plik",p,"Text files(*.txt)");
    QFileInfo fileInfo(file);
    QFile a(file);
    QFile b(p+"/Klawiatura/"+fileInfo.fileName());
    if(a.open(QIODevice::ReadOnly | QIODevice::Text) && b.open(QIODevice::WriteOnly |QIODevice::Append))
        {
            QTextStream as(&a);
            QTextStream bs(&b);
            while (!as.atEnd()) bs<<as.readLine()<<"\n";
            a.close();
            b.close();
        }


}

