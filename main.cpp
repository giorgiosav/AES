#include <QCoreApplication>
#include <iostream>
#include "operations.h"
#include "byte.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Byte *byte = new Byte::Byte("00101101");
    Byte *byte2 = new Byte::Byte(string("00000010"));
    Byte divisor = *byte2;
    Byte dividend = *byte;
    Byte inv = dividend.inverse();

    //vector<Byte> div = dividend.divide(divisor, true);

   cout << inv.getByte() << endl << dividend.multiply(inv).getByte() << endl;

    //return a.exec();
    return 0;
}
