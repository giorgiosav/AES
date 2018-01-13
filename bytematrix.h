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

    void print();

private:
    string _plainText; //128-bit input
    vector<Byte> _matrix;

    void createMatrix();
};

#endif // MATRIXGENERATOR_H
