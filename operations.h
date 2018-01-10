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

    static bool bitAt(char byte, int pos);
    static char oneHotMultiply(char multiplicand, char multiplier);
};

#endif // OPERATIONS_H
