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
};

#endif //INSTRUCTIONS_H
