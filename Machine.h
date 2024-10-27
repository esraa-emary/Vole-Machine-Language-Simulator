#ifndef MACHINE_H
#define MACHINE_H

#include <bits/stdc++.h>
using namespace std;

// =========================== Memory ===========================



// =========================== Register ===========================



// =========================== Instructions ===========================

class Instructions{
private:
    vector<string>instruct;
public:
    void Read_From_File();
    void Decode();
};

// =========================== Machine ===========================

class Machine{
private:
    Register processor;
    Memory storage;
    Instructions input;
    int program_count;
public:
    Machine();
    string Get_Next_Instruction();
    void Run_pInstruction();
    void Display_Memory();
    void Disply_Register();
};

#endif // CPU_H