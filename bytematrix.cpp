#include "bytematrix.h"
#include<iostream>

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

void ByteMatrix::print() {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) {
            std::cout << this->at(j,i).getByte().to_ulong() << " ";
        }
            std::cout << std::endl;
    }
    std::cout << '\n';
}


void ByteMatrix::createMatrix() { //index order: col * 4 + row
    for(int i = 0; i < 16; i++) {
        _matrix[i] = *(new Byte(_plainText[i]));
    }
}

Byte ByteMatrix::at(int row, int col) {
    return _matrix[row * 4 + col];
}

vector<Byte> ByteMatrix::getWord(int col) {
    vector<Byte> vec (4);
    for(int row = 0; row < 4; row++) {
        vec[row] = this->at(row, col);
    }

    return vec;
}

void ByteMatrix::setWord(vector<Byte> word, int col) {
    for(int row = 0; row < 4; row++) {
        _matrix[row * 4 + col] = word[row];
    }
}
