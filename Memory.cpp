#include "Memory.h"

#include <bits/stdc++.h>
using namespace std;
// Constructor to initialize the array with 0 in all cells
Memory::Memory() {
    for (int i = 0; i < 256; i++) {
        memory[i] = "0";
    }
}

// Getter to read from memory
string Memory::getMemory(int address) {
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
    // Print column headers
    cout << "   ";
    for (int i = 0; i < 16; ++i) {
        cout << hex << i << "  ";  // Print in hexadecimal format
    }
    cout << endl;

    // Print each row
    for (int row = 0; row < 16; ++row) {
        cout << hex << row << " ";  // Print row header in hexadecimal format
        for (int col = 0; col < 16; ++col) {
            int address = row * 16 + col;  // Calculate memory address
            cout << memory[address] << " "; // Print memory content
        }
        cout << endl; // Move to the next line after each row
    }
}
