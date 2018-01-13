#ifndef KEYEXPANSION_H
#define KEYEXPANSION_H

#include <string>
#include "bytematrix.h"

using namespace std;

class KeyExpansion
{
public:
    KeyExpansion();
    KeyExpansion(string key);
    ~KeyExpansion();

    vector<ByteMatrix> getSchedule();
    void createSchedule();


private:
    string _key;
    vector<ByteMatrix> _keyschedule;
    vector<Byte> genRoundConstant();

    vector<Byte> wordRotLeft(vector<Byte> &word);
    vector<Byte> gFunc(vector<Byte> &word);

};

#endif // KEYEXPANSION_H
