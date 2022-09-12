#include "HFAST.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HFAST w;
    w.show();

    return a.exec();
}
