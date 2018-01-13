#include "bytematrix.h"

//Constructors, destructor
ByteMatrix::ByteMatrix() {
    _plainText = "0000000000000000";
    _matrix = vector<Byte>(16);
    this->createMatrix();
}

ByteMatrix::ByteMatrix(string text) {
    _plainText = text;
    _matrix = vector<Byte>(16);
    this->createMatrix();
}

ByteMatrix::~ByteMatrix() {}


//Setters, getters
void ByteMatrix::setText(string text) {
    _plainText = text;
}

string ByteMatrix::getText() {
    return _plainText;
}

vector<Byte> ByteMatrix::getMatrix() {
    return _matrix;
}


void ByteMatrix::createMatrix() { //index order: col * 4 + row
    for(int i = 0; i < 16; i++) {
        _matrix[i] = *(new Byte(_plainText[i]));
    }
}

Byte ByteMatrix::at(int row, int col) {
    return _matrix[row * 4 + col];
}
