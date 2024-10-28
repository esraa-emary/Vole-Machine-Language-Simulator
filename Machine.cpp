#include <bits/stdc++.h>
#include <bitset>
#include "Machine.h"
#include "Memory.h"
#include "Register.h"
#include "Instructions.h"
#include <fstream>

using namespace std;

void Machine::Run_Instruction() {
    Register reg;
    Instructions inst;
    inst.Read_From_File();
    vector<string> instructions = inst.Get_Instructions();
    for (int i = 0; i < instructions.size(); ++i) {
        string address1 = to_string(instructions[i][1]);
        string address2 = to_string(instructions[i][2]);
        string address3 = to_string(instructions[i][3]);
        if (instructions[0] == "1") {

        } 
        else if (instructions[0] == "2") {

        } 
        else if (instructions[0] == "3") {

        } 
        else if (instructions[0] == "4") {

        } 
        else if (instructions[0] == "5") {

        } 
        else if (instructions[0] == "6") {

        } 
        else if (instructions[0] == "7") {
            int valReg1 = stoi(reg.getRegister(address2));
            int valReg2 = stoi(reg.getRegister(address3));
            int result = valReg1 | valReg2;
            reg.setRegister(address1, to_string(result));
        } 
        else if (instructions[0] == "8") {
            int valReg1 = stoi(reg.getRegister(address2));
            int valReg2 = stoi(reg.getRegister(address3));
            int result = valReg1 & valReg2;
            reg.setRegister(address1, to_string(result));
        } 
        else if (instructions[0] == "9") {

        } 
        else if (instructions[0] == "A") {

        } 
        else if (instructions[0] == "B") {

        } 
        else if (instructions[0] == "C") {

        }
    }
    reg.displayRegister();
}



