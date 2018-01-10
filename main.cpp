#include <QCoreApplication>
#include <iostream>
#include "operations.h"
#include "byte.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Byte *byte = new Byte::Byte(string("11001011"));
    Byte *byte2 = new Byte::Byte(string("00110110"));
    Byte divisor = *byte2;
    Byte dividend = *byte;

   cout << "ex" << endl;

    //return a.exec();
    return 0;
}
