#include "encryption.h"
#include "assert.h"

Encryption::Encryption(string text, string key){
    assert(key.length() == 16);
    _textOrganizer = *(new TextOrganizer(text));
    _keyExpansion = *(new KeyExpansion(key));
}

Encryption::~Encryption() {}

vector<ByteMatrix> Encryption::encrypt() {
    vector<ByteMatrix> stateSequence = _textOrganizer.getSequence();
    vector<ByteMatrix> keySchedule = _keyExpansion.getSchedule();


    for(int block = 0; block < stateSequence.size(); block++) {
        for(int round = 0; round < 10; round++) {
            stateSequence[block] = keySchedule[round].XOR(stateSequence[block]);
            stateSequence[block].subBytes();
            stateSequence[block].shiftRows();
            if(round != 9) stateSequence[block].mixCols();
            stateSequence[block] = stateSequence[block].XOR(keySchedule[round + 1]);
        }
    }
    return stateSequence;
}

string Encryption::generateCipherText() {
    vector<ByteMatrix> output = this->encrypt();
    string cipherText;

    for(int i = 0; i < output.size(); i++) {
        cipherText.append(output[i].getText());
    }
    return cipherText;
}
