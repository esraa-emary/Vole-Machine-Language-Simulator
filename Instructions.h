#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <bits/stdc++.h>
using namespace std;

class Instructions {
private:
    vector<string> instruct;
public:
    void Read_From_File();
    vector<string> Get_Instructions();
    void halt();
    void conditionalJumpEqual(int R, int XY);
    void rotateRight(int R, int X);
    void exclusiveOr(int R, int S, int T);
    void conditionalJumpGreater(int R, int XY);
};

#endif //INSTRUCTIONS_H
