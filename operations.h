#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <bitset>

using namespace std;

class Operations
{
public:
    Operations();

    static bitset<8> charToBitset(char c);
    static bitset<8> leftRot(bitset<8> byte, unsigned int n);
    static bitset<8> rightRot(bitset<8> byte, unsigned int n);

    static char leftRot(char byte, unsigned int n);
    static char rightRot(char byte, unsigned int n);

    static char modMultiply(char multiplicand, char multiplier);
    static char modInvert(char byte);

    static bitset<8> longDivision(bitset<8> dividend, bitset<8> divisor);

private:
    static const char multConst;
    static bool bitAt(char byte, int pos); // Helper functions
    static char timesTwo(char multiplicand);


};

#endif // OPERATIONS_H
