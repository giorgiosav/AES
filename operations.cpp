#include "operations.h"
#include <assert.h>
#include <cmath>



Operations::Operations() {}

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

//char Operations::oneHotMultiply(char multiplicand, char multiplier) {
//    {
//        int count = 0;

//        for(int i = 0; i < 8; i++) {
//            if(Operations::bitAt(multiplier, i)) {
//                count++;
//            }
//        }
//        assert(count == 1);
//    }

//    if(multiplier == 1) {
//        return multiplicand;
//    } else {

//    }
//}
