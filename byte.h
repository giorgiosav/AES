#ifndef BYTE_H
#define BYTE_H
#include <bitset>
#include <vector>

/*
 *
 * */

using namespace std;

class Byte
{
public:
    Byte();
    Byte(char c);
    Byte(int n);
    Byte(bitset<8> b);
    Byte(string s);
    ~Byte();

    //Setters, getters
    bitset<8> getByte();
    char getChar();
    void setByte(bitset<8> byte);
    void setByte(int n);

    // Operations
    Byte inverse();
    Byte multiply(Byte byte);
    Byte leftRot(unsigned int n);
    Byte rightRot(unsigned int n);
    Byte leftShift(int n);
    Byte rightShift(int n);
    Byte wordLeftRot(bool carry);
    Byte wordRightRot(bool carry);
    Byte XOR(Byte byte);
    Byte substitute();


private:
    bitset<8> _byte;

    //Helpers
    int msbPos(bitset<8> byte);
    Byte timesTwo();
    vector<Byte> divide(Byte byte, bool carry);



};

#endif // BYTE_H
