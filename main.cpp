#include <QCoreApplication>
#include <bitset>
#include <iostream>
#include "operations.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char c1 = 64;
    char c2 = 4;
    char res = Operations::modMultiply(c1, c2);

    cout << Operations::charToBitset(res) << endl;

    //return a.exec();
    return 0;
}
