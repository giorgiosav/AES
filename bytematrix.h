#ifndef MATRIXGENERATOR_H
#define MATRIXGENERATOR_H

#include <string>
#include <vector>
#include "byte.h"

using namespace std;

class ByteMatrix
{
public:
    ByteMatrix();
    ByteMatrix(string text);
    ~ByteMatrix();

    void setText(string text);
    string getText();
    vector<Byte> getMatrix();

    Byte at(int row, int col);
    vector<Byte> getWord(int col);
    void setWord(vector<Byte> word, int col);

    void print();
    void shiftRows();
    void mixCols();


private:
    string _plainText; //128-bit input
    vector<Byte> _matrix;
    void rotRowLeft(int rowNum, int n);
    void createMatrix();
};

#endif // MATRIXGENERATOR_H
