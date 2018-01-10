#include "operations.h"
#include <assert.h>
#include <cmath>



Operations::Operations() {}

const char Operations::multConst = 27;

bitset<8> Operations::charToBitset(char c) {
    return static_cast<bitset<8>> (c);
}


bitset<8> Operations::leftRot(bitset<8> byte, unsigned int n) {
    n = n % 8;
    return (byte << n) | (byte >> (-n & 7));
}

bitset<8> Operations::rightRot(bitset<8> byte, unsigned int n) {
    n = 8 - n;
    return Operations::leftRot(byte, n);
}

char Operations::leftRot(char byte, unsigned int n) {
    n = n % 8;
    return (byte << n) | (byte >> (-n & 7));
}

char Operations::rightRot(char byte, unsigned int n) {
    n = 8 - n;
    return Operations::leftRot(byte, n);
}

bool Operations::bitAt(char byte, int pos) {
    assert (pos >= 0 && pos <= 7);

    char mask = pow(2, pos);

    return byte & mask;
}

char Operations::timesTwo(char multiplicand) {

    if(Operations::bitAt(multiplicand, 7)) {
        return (multiplicand << 1) ^ multConst;
    } else {
        return (multiplicand << 1);
    }
}



char Operations::modMultiply(char multiplicand, char multiplier) {
    char res = 0;

    if(Operations::bitAt(multiplier, 0)) {
        res = multiplicand;
    }

    for(int i = 1; i < 8; i++) {
        if(Operations::bitAt(multiplier,i)) {
            char partRes = multiplicand;
            for(int j = 0; j < i; j++) {
                partRes = Operations::timesTwo(partRes);
            }
            res ^= partRes;
        }
    }
    return res;
}

bitset<8> Operations::longDivision(bitset<8> dividend, bitset<8> divisor) {

}


char Operations::modInvert(char byte) {

}
