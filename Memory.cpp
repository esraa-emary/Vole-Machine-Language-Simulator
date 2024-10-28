#include "Memory.h"
#include <bits/stdc++.h>
using namespace std;
// Constructor to initialize the array with 0 in all cells
Memory::Memory() {
    for (int i = 0; i < 256; i++) {
        memory[i] = 0;
    }
}

// Getter to read from memory
int Memory::getMemory(int address) {
    if (address < 0 || address >= 256) {
        throw out_of_range("Memory read error: Address out of range");
    }
    return memory[address];
}

// Setter to write in the memory
void Memory::setMemory(int address, string value) {
    if (address < 0 || address >= 256) {
        throw out_of_range("Memory write error: Address out of range");
    }
    memory[address] = value;
}

// Display memory contents
void Memory::printMemory() {
    for (int i = 0; i < 256; ++i) {
        cout << "Memory[" << i << "] = " << memory[i] << "\n";
    }
}
