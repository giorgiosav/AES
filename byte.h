#ifndef BYTE_H
#define BYTE_H
#include <bitset>
#include <vector>


using namespace std;

class Byte
{
public:
    Byte();
    Byte(char c);
    Byte(int n);
    Byte(bitset<8> b);
    Byte(string s);

    bitset<8> getByte();
    void setByte(bitset<8> byte);

    Byte inverse();
    Byte multiply(Byte byte);

private:
    bitset<8> _byte;
    int msbPos(bitset<8> byte);
    Byte timesTwo();
    Byte XOR(Byte byte);
    vector<Byte> divide(Byte byte, bool carry);



};

#endif // BYTE_H
