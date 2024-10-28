#ifndef MACHINE_H
#define MACHINE_H

#include <bits/stdc++.h>
#include "Instructions.h"
using namespace std;

class Machine {
private:
    Instructions input;
    int program_count;
public:
    Machine();
    string Get_Next_Instruction();
    void Run_Instruction();
};

#endif // MACHINE_H
