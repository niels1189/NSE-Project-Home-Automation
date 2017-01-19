#include "dialog.h"
#include <QApplication>
#include "temperatuur.h"


int main(int argc, char *argv[])
{
    Ingesteldetemperatuur =25;
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}
