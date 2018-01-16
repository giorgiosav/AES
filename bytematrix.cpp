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
    string output;

    for(int col = 0; col < 4; col++) {
        for(int row = 0; row < 4; row++) {
            output.push_back(this->at(row, col).getChar());
        }
    }

    return output;
}

vector<bool> ByteMatrix::getBitStream() {
    vector<bool> output;

    for(int col = 0; col < 4; col++) {
        for(int row = 0; row < 4; row++) {
            for(int bit = 7; bit >= 0; bit--) {
                output.push_back(this->at(row, col).getByte()[bit]);
            }
        }
    }
    return output;

}

vector<Byte> ByteMatrix::getMatrix() {
    return _matrix;
}

void ByteMatrix::print() {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) {
            std::cout << this->at(i, j).getByte().to_ulong() << " ";
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
    return _matrix[col * 4 + row];
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
        _matrix[col * 4 + row] = word[row];
    }
}

void ByteMatrix::rotRowLeft(int rowNum, int n) {
    vector<Byte> matrix = _matrix;
    for(int col = 0; col < 4; col++) {
        _matrix[col * 4 + rowNum] = matrix[((col + n)%4)*4 + rowNum];
    }
}

void ByteMatrix::shiftRows() {
    this->rotRowLeft(1, 1);
    this->rotRowLeft(2, 2);
    this->rotRowLeft(3, 3);
}

void ByteMatrix::mixCols() {
    Byte three = *(new Byte(3));
    Byte two = *(new Byte(2));

    for(int col = 0; col < 4; col++) {
        for(int row = 0; row < 4; row++) {
            _matrix[col * 4 + row] = _matrix[col * 4 + row].multiply(two).XOR(
                                     _matrix[col * 4 + (row + 1)%4].multiply(three)).XOR(
                                     _matrix[col * 4 + (row + 2)%4]).XOR(
                                     _matrix[col * 4 + (row + 3)%4]);
        }
    }
}

void ByteMatrix::setAt(int row, int col, Byte byte) {
    _matrix[col * 4 + row] = byte;
}

ByteMatrix ByteMatrix::XOR(ByteMatrix matrix) {
    ByteMatrix result;

    for(int row = 0; row < 4; row++) {
        for(int col = 0; col < 4; col++) {
            result.setAt(row, col, this->at(row, col).XOR(matrix.at(row, col)));
        }
    }
    return result;
}

void ByteMatrix::subBytes() {
    for(int row = 0; row < 4; row++) {
        for(int col = 0; col < 4; col++) {
            this->setAt(row, col, this->at(row, col).substitute());
        }
    }
}
