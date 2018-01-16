#include <QCoreApplication>
#include <iostream>
#include "encryption.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Encryption *m = new Encryption("Here is my text to encrypt", "AnotherNiceKey12");
    cout << m->generateCipherText() << endl;

    vector<bool> vec = m->generateCipherBitStream();

    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if(i%8 == 7) cout << " ";
    }
    cout << endl;

    char c = ',';

    cout << int (c) << endl;

    delete m;
    //return a.exec();
    return 0;
}
