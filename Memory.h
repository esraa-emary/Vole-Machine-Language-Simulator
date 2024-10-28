#ifndef MEMORY_H
#define MEMORY_H

#include <bits/stdc++.h>
using namespace std;

class Memory {
private:
    std::array<int, 256> memory;

public:
    Memory();                           

    int getMemory(int address);         
    void setMemory(int address, int value); 
    void printMemory();                
};

#endif  
