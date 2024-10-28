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
        if (instructions[0] == "1") {

        } else if (instructions[0] == "2") {

        } else if (instructions[0] == "3") {

        } else if (instructions[0] == "4") {

        } else if (instructions[0] == "5") {

        } else if (instructions[0] == "6") {

        } else if (instructions[0] == "7") {

        } else if (instructions[0] == "8") {

        } else if (instructions[0] == "9") {

        } else if (instructions[0] == "A") {

        } else if (instructions[0] == "B") {

        } else if (instructions[0] == "C") {

        }
    }
    reg.displayRegister();
}



