#include "../include/Memory.h"
#include <bits/stdc++.h>
using namespace std;

// Constructor to initialize the array with 0 in all cells
Memory::Memory() {
    for (int i = 0; i < 256; i++) {
        memory[i] = "00";
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

bool Memory::checkDecimal(const string &str) {
    for (char i: str) {
        // Check if the character is a valid decimal number.
        if (!isdigit(i)) return false;
    }
    return true;
}

bool Memory::checkProgramCounter(int programCounter, vector<string> &instructions) {
    return programCounter + (instructions.size() * 2) < 256;          // Check if the program fits in the memory.
}

void Memory::programCounterIncrement(vector<string> &instructions) {
    int numberOfAttempts = 3;
    int proCou;
    while (true) {
        string address;

        if (numberOfAttempts > 0) {
            cout << "\nTake care, the Number of attempts = " << numberOfAttempts << endl;
            cout << "Enter Program Counter :";
            getline(cin, address);
        }

            // If the user exceeds the number of attempts, set the program counter to 10.
        else if (numberOfAttempts == 0) {
            cout << "\nYou have exceeded the number of attempts.\n";
            cout << "So, The Default Program Counter = 10.\n";
            address = "10";
        }

        if (checkDecimal(address)) {
            proCou = stoi(address);        // Convert the decimal address to decimal.

            // Check if the address is in the range of the memory.
            if (checkProgramCounter(proCou, instructions) && proCou % 2 == 0 && proCou > 0) {
                programCounter = proCou;
                // Load the program into the memory.
                for (int i = 0; i < instructions.size(); ++i) {
                    memory[proCou] = instructions[i].substr(0, 2);
                    ++proCou;
                    memory[proCou] = instructions[i].substr(2);
                    ++proCou;
                }
                break;
            }

                // If the address is not in the range of the memory, ask the user to enter a valid address.
            else {
                cout << "\nThe address is out of range. Please enter a valid address.\n";
                --numberOfAttempts;
            }
        }

            // If the address is not a decimal number, ask the user to enter a valid address.
        else {
            cout << "\nThe address is out of range. Please enter a valid address.\n";
            --numberOfAttempts;
        }
    }
}

void Memory::setProgramCounter(int address) {
    programCounter = address;
}

int Memory::getProgramCounter() {
    return programCounter;
}

string Memory::getInstruction() {
    return memory[programCounter] + memory[programCounter + 1];
}
