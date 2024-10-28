#ifndef MACHINE_H
#define MACHINE_H

#include <bits/stdc++.h>

using namespace std;

// =========================== Memory ===========================

class Memory {
private:
    std::array<int, 256> memory;
public:
    Memory();
    int getMemory(int address);
    void setMemory(int address, int value);
    void printMemory();
    void Display_Memory();
};

// =========================== Register ===========================

class Register {
private:
    vector<string> registers = vector<string>(16);
public:
    Register();
    void setRegister(const string &Address, const string &Value);
    string getRegister(const string &location);
    void displayRegister();
    void clearRegister();
};

// =========================== Instructions ===========================

class Instructions {
private:
    vector<string> instruct;
public:
    vector<string> Read_From_File();
    void Decode();
};

// =========================== Machine ===========================

class Machine {
private:
    Register processor;
    Memory storage;
    Instructions input;
    int program_count;
public:
    Machine();
    string Get_Next_Instruction();
    void Run_Instruction();
};

#endif // MACHINE_H
