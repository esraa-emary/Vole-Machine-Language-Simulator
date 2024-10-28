#include <bits/stdc++.h>
#include <bitset>
#include "Machine.h"
#include "Memory.h"
#include "Register.h"
#include "Instructions.h"
#include <fstream>

using namespace std;

void Machine::Load_From_Memory_To_Register(string address4, string address1, Register &reg, Memory &mem) {
    int index = stoi(address4);
    int content = mem.getMemory(index);
    reg.setRegister(address1,to_string(content));
}

void Machine::Load_To_Register(string address1, string value, Register &reg) {
    reg.setRegister(address1, value);
}

void Machine::Store(string address1, string address4, Register &reg, Memory &mem) {
    string content = reg.getRegister(address1);
    int address = stoi(address4), value = stoi(content);
    mem.setMemory(address, value);
}

void Machine::Move(string address2, string address3, Register &reg) {
    string content = reg.getRegister(address2);
    reg.setRegister(address3, content);
}

void Machine::OrBitwiseOperation(string& address1, string& address2, string& address3, Register& reg) {
    int valReg1 = stoi(reg.getRegister(address2));
    int valReg2 = stoi(reg.getRegister(address3));
    int result = valReg1 | valReg2;
    reg.setRegister(address1, to_string(result));
}

void Machine::AndBitwiseOperation(string& address1, string& address2, string& address3, Register& reg) {
    int valReg1 = stoi(reg.getRegister(address2));
    int valReg2 = stoi(reg.getRegister(address3));
    int result = valReg1 & valReg2;
    reg.setRegister(address1, to_string(result));
}

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
            Load_From_Memory_To_Register(address4, address1,reg,mem);
        } else if (instructions[i][0] == '2') {
            string value = instructions[i].substr(2, 2);
            Load_To_Register(address1, value, reg);
        } else if (instructions[i][0] == '3') {
            Store(address1, address4,reg,mem);
        } else if (instructions[i][0] == '4') {
            Move(address2, address3, reg);
        } else if (instructions[i][0] == '5') {

        } else if (instructions[i][0] == '6') {

        } else if (instructions[i][0] == '7') {
            OrBitwiseOperation(address1, address2, address3, reg);
        } else if (instructions[i][0] == '8') {
            AndBitwiseOperation(address1, address2, address3, reg);
        } else if (instructions[i][0] == '9') {

        } else if (instructions[i][0] == 'A') {

        } else if (instructions[i][0] == 'B') {

        } else if (instructions[i][0] == 'C') {

        }
    }
    reg.displayRegister();
    mem.printMemory();
}
