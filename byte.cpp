#include "byte.h"
#include "assert.h"

// Constructors
Byte::Byte() {
    _byte = 0;
}

Byte::Byte(char c) {
    _byte = static_cast<bitset<8>> (c);
}

Byte::Byte(bitset<8> b) {
    _byte  = b;
}

Byte::Byte(string s) {
    _byte = bitset<8>(string(s));
}

Byte::Byte(int n) {
    _byte = bitset<8>(n);
}

// Setters, getters

bitset<8> Byte::getByte() {
    return _byte;
}

void Byte::setByte(bitset<8> byte) {
    _byte = byte;
}

int Byte::msbPos(bitset<8> byte) {
    if(byte.any()) {
        int i = 7;
        while(!byte.test(i)) {
            i--;
        }
        return i;
    } else {
        return -1;
    }
}

//Mathematical operations


Byte Byte::timesTwo() {
    bitset<8> newByte;
    Byte *retByte;
    const bitset<8> multConst = bitset<8>(string("00011011"));

    if(_byte[7]) {
        newByte = (_byte << 1) ^ multConst;
    } else {
        newByte = (_byte << 1);
    }

    retByte = new Byte(newByte);

    return *retByte;
}

Byte Byte::multiply(Byte multiplier) {
    Byte *res = new Byte(0);
    bitset<8> multByte = multiplier.getByte();

    if(multByte[0]) {
        res->setByte(_byte);
    }

    for(int i = 1; i < 8; i++) {
        if(multByte[i]) {
            Byte *partRes = new Byte(_byte);

            for(int j = 0; j < i; j++) {
                *partRes = partRes->timesTwo();
            }
            res->setByte(res->getByte() ^ partRes->getByte());
            delete partRes;
        }
    }
    return *res;
}

vector<Byte> Byte::divide(Byte byte, bool carry) {
    bitset<8> divisor = byte.getByte();
    bitset<8> dividend = _byte;
    int msbDividend;

    if(carry) {
        msbDividend = msbPos(dividend); //MSB positions
    } else {
        msbDividend = 8;
    }
    int msbDivisor = msbPos(divisor);

    bitset<8> quot = 0;

    while(msbDivisor <= msbDividend) {
        int diff = msbDividend - msbDivisor;
        quot.set(diff);
        dividend ^= (divisor << diff);
        msbDividend = msbPos(dividend);
    }

    vector<Byte> results(2);
    results[0] = *(new Byte(quot));
    results[1] = *(new Byte(dividend));

    return results;
}

Byte Byte::XOR(Byte byte) {
    Byte *result = new Byte(_byte ^ byte.getByte());

    return *result;
}



Byte Byte::inverse() {

    bool edgeCase0 = _byte.to_ulong() == 0;
    bool edgeCase1 = _byte.to_ulong() == 1;
    Byte num = *this;

    Byte *x, *yOld = new Byte(0);
    Byte *y, *xOld = new Byte(1);

    if(edgeCase0 || edgeCase1) {
        return num;
    }

    Byte *mod = new Byte(string("00011011"));

    vector<Byte> quotRem = mod->divide(num, true);

    while(mod->getByte().to_ulong()) {
        Byte quot = quotRem[0];
        Byte rem = quotRem[1];
        Byte temp = num;
        num = *mod;
        mod->setByte(temp.getByte() ^ mod->getByte()); // mod = mod - num

        temp = *x;
        *x = xOld->XOR(quot.multiply(*x));
        *xOld = temp;

        temp = *y;
        *y = yOld->XOR(quot.multiply(*y));
        *yOld = temp;

        quotRem = mod->divide(num, false);

    }
    delete mod;
    delete x, y, yOld;
    return *xOld;

}


