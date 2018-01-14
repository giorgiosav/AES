#include "keyexpansion.h"

KeyExpansion::KeyExpansion() {
    _key = "0000000000000000";
    _keyschedule = vector<ByteMatrix>(11);
    _rCon = KeyExpansion::genRoundConstant();
    this->createSchedule();
}

KeyExpansion::KeyExpansion(string key) {
    _key = key;
    _keyschedule = vector<ByteMatrix>(11);
    _rCon = KeyExpansion::genRoundConstant();
    this->createSchedule();
}

KeyExpansion::~KeyExpansion() {}


//Setters, getters

vector<ByteMatrix> KeyExpansion::getSchedule() {
    return _keyschedule;
}


vector<Byte> KeyExpansion::genRoundConstant() {
    vector<Byte> rCon (10);
    const Byte multConst = *(new Byte(2));

    rCon[0].setByte(1);
    for(int i = 1; i < rCon.size(); i++) {
        rCon[i] = rCon[i-1].multiply(multConst);
    }

    return rCon;
}

vector<Byte> KeyExpansion::wordLeftRot(vector<Byte> &word) {
    bool msb [4];
    for(int i = 0; i < 4; i++) {
        msb[i] = word[i].getByte()[7];
    }

    for(int i = 0; i < 4; i++) {
        int j = (i + 3) % 4;
        word[i] = word[i].wordLeftRot(msb[j]);
    }

    return word;
}

vector<Byte> KeyExpansion::gFunc(vector<Byte> &word, int round, Byte rCon) {

    word = KeyExpansion::wordLeftRot(word);
    for(int i = 0; i < 4; i++) {
        word[i] = word[i].substitute();
    }

    word[3] = word[3].XOR(rCon);

    return word;
}

vector<Byte> KeyExpansion::wordXOR(vector<Byte> word1, vector<Byte> word2) {
    vector<Byte> result (4);
    for(int i = 0; i < 4; i++) {
        result[i] = word1[i].XOR(word2[i]);
    }
    return result;
}

void KeyExpansion::createSchedule() {
    _keyschedule[0] = *(new ByteMatrix(_key));

    for(int round = 1; round < 11; round++) {
        ByteMatrix roundMatrix;

        for(int pos = 0; pos < 4; pos++) {
            vector<Byte> word1 = _keyschedule[round - 1].getWord(pos);
            vector<Byte> word2 = _keyschedule[round - 1].getWord((pos + 3) % 4);
            vector<Byte> resWord (4);

            if(pos == 0) {
                word2 = KeyExpansion::gFunc(word2, round, _rCon[round]);
            }

            resWord = KeyExpansion::wordXOR(word1, word2);
            roundMatrix.setWord(resWord, pos);
        }
        _keyschedule[round] = roundMatrix;
    }
}


