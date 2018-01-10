#include <QCoreApplication>
#include <bitset>
#include <iostream>
#include "operations.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    bitset<8> q1 = Operations::charToBitset('a');
//    bitset<8> q3 = Operations::rightRot(q1, -2);
//    char c1 = 'a';
//    char c3 = Operations::rightRot(c1, -2);

//    cout << q1 << endl;
//    cout << q3 << endl;

//    cout << Operations::charToBitset(c1) << endl;
//    cout << Operations::charToBitset(c3) << endl;

    char c1 = 121;
    for(int i = 0; i < 8; i++) {
        cout << Operations::bitAt(c1, i) << endl;
    }
    cout << Operations::charToBitset(c1) << endl;

    //return a.exec();
    return 0;
}
