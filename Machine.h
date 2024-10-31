#ifndef MACHINE_H
#define MACHINE_H

#include <bits/stdc++.h>
#include "Register.h"
#include "Memory.h"

using namespace std;

class Machine {
private:
    Memory machineMemory;
    Register machineRegister;
public:
    void getMemory();
    void getRegister();
    void Run_Instruction();
};

#endif // MACHINE_H
