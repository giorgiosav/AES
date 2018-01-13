#include <QCoreApplication>
#include <iostream>
#include "byte.h"
#include "bytematrix.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ByteMatrix *m = new ByteMatrix("1234567890123456");

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout << m->at(i,j).getChar() << endl;

        }
    }


    delete m;
    //return a.exec();
    return 0;
}
