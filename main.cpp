#include <QCoreApplication>
#include <iostream>
#include "byte.h"
#include "bytematrix.h"
#include "textorganizer.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TextOrganizer *m = new TextOrganizer("Some random text written here");
    int len = m->getSequence().size();

    for(int i = 0; i < len; i++) {
        m->getSequence()[i].print();
    }


    delete m;
    //return a.exec();
    return 0;
}
