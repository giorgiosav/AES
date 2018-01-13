#include "textorganizer.h"

//Constructors, destructor
TextOrganizer::TextOrganizer(){
    _plainText = "0000000000000000";
    this->padText();
    this->createSequence();
}

TextOrganizer::TextOrganizer(string text){
    _plainText = text;
    this->padText();
    this->createSequence();
}

TextOrganizer::~TextOrganizer() {}

//Setters, getters

string TextOrganizer::getText() {
    return _plainText;
}

vector<ByteMatrix> TextOrganizer::getSequence() {
    return _stateSequence;
}


void TextOrganizer::padText() {
    int len = _plainText.length();
    len = len % 16;
    if(len < 16 && len != 0) {
        char pad = 16 - len; //PKCS7 padding

        for(int i = 0; i < 16 - len; i++) {
            _plainText.push_back(pad);
        }

    }
}

void TextOrganizer::createSequence() {
    int len = _plainText.length()/16;
    _stateSequence = vector<ByteMatrix>(len);

    for(int i = 0; i < len; i++) {
        string inputString = _plainText.substr(16 * i, 16);
        _stateSequence[i] = *(new ByteMatrix(inputString));
    }
}
