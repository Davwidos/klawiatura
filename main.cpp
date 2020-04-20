#include "klawiatura.h"

#include <QApplication>

Klawiatura *w;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w=new Klawiatura;
    w->showFullScreen();
    w->displayMenu();
    return a.exec();
}
