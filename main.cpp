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

    ByteMatrix *m = new ByteMatrix("01234567890123456");

    m->print();
    m->mixCols();
    m->print();
    delete m;
    //return a.exec();
    return 0;
}
