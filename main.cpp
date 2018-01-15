#include <QCoreApplication>
#include <iostream>
#include "byte.h"
#include "bytematrix.h"
#include "textorganizer.h"
#include "keyexpansion.h"
#include "encryption.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Encryption *m = new Encryption("Here is my text to encrypt", "NiceLongKeysFor1");

    cout << m->generateCipherText() << endl;

    delete m;
    //return a.exec();
    return 0;
}
