#include <bits/stdc++.h>
#include <bitset>
#include "Machine.h"
#include "Memory.h"
#include "Register.h"
#include "Instructions.h"

using namespace std;

void Machine::showScreenOutput() {
    string hex = machineMemory.getMemory(0);
    cout << "\nWhat shows on screen in Hexa: " << hex << endl;
    std::string ascii;

    // Check if the hex string length is even
    if (hex.length() % 2 != 0) {
        throw std::invalid_argument("Hex string length must be even.");
    }

    for (size_t i = 0; i < hex.length(); i += 2) {
        // Convert each two-character hex pair to a byte (8 bits)
        std::string byteString = hex.substr(i, 2);
        char byte = static_cast<char>(std::stoi(byteString, nullptr, 16));
        ascii += byte;
    }

    // Print the converted ASCII string
    cout << "What shows on screen in Ascii: " << ascii << endl << endl;
}

void Machine::loadNewProgram(Memory& newMem, Register& newReg) {
    runInstruction(newMem,newReg);
    getRegister();
    getMemory();
}

void Machine::runAll(Memory& mem, Register& reg) {
    runInstruction(mem, reg);
    cout << "\nFinal Register :\n";
    getRegister();
    cout << "Final Memory :\n";
    getMemory();
}

void Machine::runStepByStep(Memory& mem, Register& reg) {
    int i = 0;
    Instructions inst;
    inst.readFromFile();
    vector<string> instructions = inst.getInstructions();
    mem.programCounterIncrement(instructions);
    int programCounter = mem.getProgramCounter();
    int nextCounter = programCounter;
    bool flag = inst.getHalted();

    machineMemory = mem;
    machineRegister = reg;
    cout << "\nInitial Register :\n";
    getRegister();
    cout << "Initial Memory :\n";
    getMemory();

    while (programCounter <= 255 && !flag) {
        string instruction = mem.getInstruction();
        string num = instruction.substr(0, 1);
        string address1 = instruction.substr(1, 1);
        string address2 = instruction.substr(2, 1);
        string address3 = instruction.substr(3, 1);
        string address4 = instruction.substr(2, 2);
        bool ff = false;
        int X, XY;

        if (instruction.substr(0, 2) != "00") {
            i++;
            if (i > 1) {
                cout << "\nStep " << i - 1 << " completed. \nCurrent Register State:\n";
                getRegister();
                cout << "Current Memory State:\n";
                getMemory();
            }
        }

        if (num == "1") {
            inst.loadFromMemoryToRegister(address4, address1, reg, mem);
        } else if (num == "2") {
            inst.loadToRegister(address1, address4, reg);
        } else if (num == "3") {
            inst.store(address1, address4, reg, mem);
            machineMemory = mem;
            machineRegister = reg;
            if (address4 == "00") showScreenOutput(); // Display what shows on screen
        } else if (num == "4") {
            inst.move(address2, address3, reg);
        } else if (num == "5") {
            inst.addingTwoComplement(address1, address2, address3, reg);
        } else if (num == "6") {
            inst.addingFloatingNumber(address1, address2, address3, reg);
        } else if (num == "7") {
            inst.orBitwiseOperation(address1, address2, address3, reg);
        } else if (num == "8") {
            inst.andBitwiseOperation(address1, address2, address3, reg);
        } else if (num == "9") {
            inst.exclusiveOr(address1, address2, address3, reg);
        } else if (num == "A" || num == "a") {
            X = stoi(address4, nullptr, 16);
            inst.rotateRight(address1, X, reg);
        } else if (num == "B" || num == "b") {
            XY = stoi(address4, nullptr, 16);
            programCounter = inst.conditionalJump(address1, XY, reg, mem, programCounter, ff);
            if (ff) programCounter -= 2;
        } else if (num == "C" || num == "c") {
            inst.halt();
        } else if (num == "D" || num == "d") {
            XY = stoi(address4, nullptr, 16);
            programCounter = inst.conditionalJumpGreater(address1, XY, reg, mem, programCounter, ff);
            if (ff) programCounter -= 2;
        }

        // Display register and memory state after each instruction
        machineMemory = mem;
        machineRegister = reg;
        mem.setProgramCounter(programCounter + 2);
        programCounter = mem.getProgramCounter();
        flag = inst.getHalted();
    }
    cout << "\nFinal Register :\n";
    getRegister();
    cout << "Final Memory :\n";
    getMemory();
    mem.setProgramCounter(nextCounter + (i * 2));
}

void Machine::runInstruction(Memory& mem, Register& reg) {
    int i = 0;
    Instructions inst;
    inst.readFromFile();
    vector<string> instructions = inst.getInstructions();
    mem.programCounterIncrement(instructions);
    int programCounter = mem.getProgramCounter();
    int nextCounter = programCounter;
    bool flag = inst.getHalted();

    machineMemory = mem;
    machineRegister = reg;
    cout << "\nInitial Register :\n";
    getRegister();
    cout << "Initial Memory :\n";
    getMemory();

    while (programCounter < 253 && !flag) {
        string instruction = mem.getInstruction();
        string num = instruction.substr(0, 1);
        string address1 = instruction.substr(1, 1);
        string address2 = instruction.substr(2, 1);
        string address3 = instruction.substr(3, 1);
        string address4 = instruction.substr(2, 2);
        bool ff = false;
        int X, XY;

        if (num == "1") {
            inst.loadFromMemoryToRegister(address4, address1, reg, mem);
        } else if (num == "2") {
            inst.loadToRegister(address1, address4, reg);
        } else if (num == "3") {
            inst.store(address1, address4, reg, mem);
            machineMemory = mem;
            machineRegister = reg;
            if (address4 == "00") showScreenOutput(); // Display what shows on screen
        } else if (num == "4") {
            inst.move(address2, address3, reg);
        } else if (num == "5") {
            inst.addingTwoComplement(address1, address2, address3, reg);
        } else if (num == "6") {
            inst.addingFloatingNumber(address1, address2, address3, reg);
        } else if (num == "7") {
            inst.orBitwiseOperation(address1, address2, address3, reg);
        } else if (num == "8") {
            inst.andBitwiseOperation(address1, address2, address3, reg);
        } else if (num == "9") {
            inst.exclusiveOr(address1, address2, address3, reg);
        } else if (num == "A" || num == "a") {
            X = stoi(address4, nullptr, 16);
            inst.rotateRight(address1, X, reg);
        } else if (num == "B" || num == "b") {
            XY = stoi(address4, nullptr, 16);
            programCounter = inst.conditionalJump(address1, XY, reg, mem, programCounter, ff);
            if (ff) programCounter -= 2;
        } else if (num == "C" || num == "c") {
            inst.halt();
        } else if (num == "D" || num == "d") {
            XY = stoi(address4, nullptr, 16);
            programCounter = inst.conditionalJumpGreater(address1, XY, reg, mem, programCounter, ff);
            if (ff) programCounter -= 2;
        }

        // Display register and memory state after each instruction
        machineMemory = mem;
        machineRegister = reg;
        mem.setProgramCounter(programCounter + 2);
        programCounter = mem.getProgramCounter();
        flag = inst.getHalted();
    }
    mem.setProgramCounter(nextCounter + (i * 2));
}

void Machine::getMemory() {
    machineMemory.printMemory();
}

void Machine::getRegister() {
    machineRegister.displayRegister();
}
