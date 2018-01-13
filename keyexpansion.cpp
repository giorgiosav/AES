#include "keyexpansion.h"

KeyExpansion::KeyExpansion() {
    _key = "0000000000000000";
    _keyschedule = vector<ByteMatrix>(44);
}

KeyExpansion::KeyExpansion(string key) {
    _key = key;
    _keyschedule = vector<ByteMatrix>(44);
}

KeyExpansion::~KeyExpansion() {}


//Setters, getters

vector<ByteMatrix> KeyExpansion::getSchedule() {
    return _keyschedule;
}


vector<Byte> KeyExpansion::genRoundConstant() {
    vector<Byte> rCon (44);
    const Byte multConst = *(new Byte(2));

    rCon[0].setByte(1);
    for(int i = 1; i < rCon.size(); i++) {
        rCon[i] = rCon[i-1].multiply(multConst);
    }

    return rCon;
}


