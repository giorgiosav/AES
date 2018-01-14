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


private:
    string _key;
    vector<Byte> _rCon;
    vector<ByteMatrix> _keyschedule;
    static vector<Byte> wordLeftRot(vector<Byte> &word);
    static vector<Byte> genRoundConstant();

    static vector<Byte> gFunc(vector<Byte> &word, int round, Byte rCon);
    static vector<Byte> wordXOR(vector<Byte> word1, vector<Byte> word2);

    void createSchedule();




};

#endif // KEYEXPANSION_H
