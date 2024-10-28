#ifndef MEMORY_H
#define MEMORY_H

#include <bits/stdc++.h>
using namespace std;

class Memory {
private:
    std::array<string , 256> memory;

public:
    Memory();
    string getMemory(int address);
    void setMemory(int address, string value);
    void printMemory();                
};

#endif  
