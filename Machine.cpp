#include <bits/stdc++.h>
#include <bitset>
#include "Machine.h"
#include "Memory.h"
#include "Register.h"
#include "Instructions.h"
using namespace std;


void Machine::Run_Instruction() {
    Memory mem;
    Register reg;
    Instructions inst;
    inst.Read_From_File();
    vector<string> instructions = inst.Get_Instructions();
    bool haltFlag = false;
    for (int i = 0; i < instructions.size() && !haltFlag; ++i) {
        string instruction = instructions[i];
        string address1 = string(1, instructions[i][1]);
        string address2 = string(1, instructions[i][2]);
        string address3 = string(1, instructions[i][3]);
        string address4 = instructions[i].substr(2, 2);
        string R = string(1, instructions[i][1]);
        string S = string(1, instructions[i][2]);
        string T = string(1, instructions[i][3]);
        int X,XY;
        if (instructions[i][0] == '1') {
            inst.Load_From_Memory_To_Register(address4, address1,reg,mem);
        } else if (instructions[i][0] == '2') {
            string value = instructions[i].substr(2, 2);
            inst.Load_To_Register(address1, value, reg);
        } else if (instructions[i][0] == '3') {
            inst.Store(address1, address4,reg,mem);
        } else if (instructions[i][0] == '4') {
            inst.Move(address2, address3, reg);
        } else if (instructions[i][0] == '5') {
            inst.AddingTwoComplement(address1, address2, address3, reg);
        } else if (instructions[i][0] == '6') {
            inst.AddingFloatingNumber(address1, address2, address3, reg);
        } else if (instructions[i][0] == '7') {
            inst.OrBitwiseOperation(address1, address2, address3, reg);
        } else if (instructions[i][0] == '8') {
            inst.AndBitwiseOperation(address1, address2, address3, reg);
        }else if (instructions[i][0] == '9') {
            inst.exclusiveOr(address1, address2, address3, reg);
        }else if (instructions[i][0] == 'A') {
            X = stoi(instruction.substr(1, 2), nullptr, 16);
            inst.rotateRight(address1, X, reg);
        } else if (instructions[i][0] == 'B') {
            XY = stoi(instruction.substr(1, 2), nullptr, 16);
            inst.conditionalJump(address1, XY, reg, i);
            continue; // Skip increment to jump directly
        } else if (instructions[i][0] == 'C') {
            inst.halt(haltFlag);
        } else if (instructions[i][0] == 'D') {
            XY = stoi(instruction.substr(1, 2), nullptr, 16);
            inst.conditionalJumpGreater(address1, XY, reg, i);
            continue; // Skip increment to jump directly
        }
        machineMemory = mem;
        machineRegister = reg;
    }
}

void Machine::getMemory() {
    machineMemory.printMemory();
}

void Machine::getRegister() {
    machineRegister.displayRegister();
}
