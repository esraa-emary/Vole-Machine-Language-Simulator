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
    void runInstruction(Memory& mem, Register& reg);
    void showScreenOutput();
    void loadNewProgram(Memory& newMem, Register& newReg);
    void runAll(Memory& mem, Register& reg);
    void runStepByStep(Memory& mem, Register& reg);
};

#endif // MACHINE_H
