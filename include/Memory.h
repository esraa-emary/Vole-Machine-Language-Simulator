#ifndef MEMORY_H
#define MEMORY_H

#include <bits/stdc++.h>
using namespace std;

class Memory {
private:
    std::array<string , 256> memory;
    int programCounter = 10;
public:
    Memory();
    string getMemory(int address);
    void setMemory(int address, string value);
    void printMemory();
    void programCounterIncrement (vector<string>& instructions);
    bool checkDecimal(const string& str);
    bool checkProgramCounter(int programCounter, vector<string>& instructions);
    void setProgramCounter(int address);
    int getProgramCounter ();
    string getInstruction ();
};

#endif  
