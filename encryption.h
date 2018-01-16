#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>
#include "textorganizer.h"
#include "keyexpansion.h"

using namespace std;

class Encryption
{
public:
    Encryption(string text, string key);
    ~Encryption();
    string generateCipherText();
    vector<bool> generateCipherBitStream();

private:
    TextOrganizer _textOrganizer;
    KeyExpansion _keyExpansion;
    vector<ByteMatrix> encrypt();

};

#endif // ENCRYPTION_H
