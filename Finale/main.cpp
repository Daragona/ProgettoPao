#include "view.h"
#include "controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    view w;
    Model m;
    Controller c;

    w.show();
    c.setModel(&m);
    c.setView(&w);
    w.setController(&c);

    return a.exec();
}
