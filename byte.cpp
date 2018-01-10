#include "byte.h"
#include "assert.h"

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

//Byte Byte::inverse() {

//    bool edgeCase0 = _byte.to_ulong() == 0;
//    bool edgeCase1 = _byte.to_ulong() == 1;
//    Byte num = *this;

//    if(edgeCase0 || edgeCase1) {
//        return num;
//    }

//    Byte *mod = new Byte(string("00011011"));

//    vector<Byte> quotRem = mod->divide(num, true);

//    while(mod->getByte().to_ulong()) {
//        Byte quot = quotRem[0];
//        Byte rem = quotRem[1];
//        Byte temp = num;
//        num = mod;
//        mod = temp ^ mod; //incomplete

//    }
//    return *this;
//}


