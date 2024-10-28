#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <bits/stdc++.h>
using namespace std;

class Instructions {
private:
    vector<string> instruct;
public:
    vector<string> Read_From_File();
    void Decode();
};

#endif //INSTRUCTIONS_H
