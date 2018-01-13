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

    KeyExpansion *m = new KeyExpansion();
    Byte *b = new Byte(162);
    vector<Byte> vec = {*b,*b,*b,*b};
    m->wordRotLeft(vec);

    delete m;
    delete b;
    //return a.exec();
    return 0;
}
