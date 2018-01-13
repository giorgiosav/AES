#ifndef TEXTORGANIZER_H
#define TEXTORGANIZER_H

#include <vector>
#include "bytematrix.h"

using namespace std;

class TextOrganizer
{
public:
    TextOrganizer();
    TextOrganizer(string text);
    ~TextOrganizer();

    string getText();
    vector<ByteMatrix> getSequence();


private:
    string _plainText;
    vector<ByteMatrix> _stateSequence;
    void padText();
    void createSequence();
};

#endif // TEXTORGANIZER_H
