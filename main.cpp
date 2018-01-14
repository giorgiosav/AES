#include <QCoreApplication>
#include <iostream>
#include "byte.h"
#include "bytematrix.h"
#include "textorganizer.h"
#include "keyexpansion.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    KeyExpansion *m = new KeyExpansion("1234567890123456");

    for(int i = 0; i < 11; i++) {
        m->getSchedule()[i].print();
    }

    delete m;
    //return a.exec();
    return 0;
}
