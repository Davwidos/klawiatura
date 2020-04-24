#include "klawiatura.h"

#include <QApplication>

Klawiatura *w;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(res);
    w=new Klawiatura;
    w->showFullScreen();
    w->displayMenu();
    return a.exec();
}
