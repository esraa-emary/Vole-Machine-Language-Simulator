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
    for (int i = 0; i < instructions.size(); ++i) {
        string address1 = string(1, instructions[i][1]);
        string address2 = string(1, instructions[i][2]);
        string address3 = string(1, instructions[i][3]);
        string address4 = instructions[i].substr(2, 2);
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

        } else if (instructions[i][0] == '7') {
            inst.OrBitwiseOperation(address1, address2, address3, reg);
        } else if (instructions[i][0] == '8') {
            inst.AndBitwiseOperation(address1, address2, address3, reg);
        } else if (instructions[i][0] == '9') {

        } else if (instructions[i][0] == 'A') {

        } else if (instructions[i][0] == 'B') {

        } else if (instructions[i][0] == 'C') {

        }else if (instructions[i][0] == 'D') {

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
