#include <QCoreApplication>
#include <iostream>
#include "operations.h"
#include "byte.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Byte *byte = new Byte::Byte(string("00011011"));
    Byte *byte2 = new Byte::Byte(string("00000010"));
    Byte divisor = *byte2;
    Byte dividend = *byte;
    Byte inv = divisor.inverse();
    //vector<Byte> div = dividend.divide(divisor, true);
    dividend.rightRot(8);

   cout << dividend.getByte() << endl;

    //return a.exec();
    return 0;
}
