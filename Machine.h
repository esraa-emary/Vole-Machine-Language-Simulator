#ifndef MACHINE_H
#define MACHINE_H

#include <bits/stdc++.h>
#include "Instructions.h"
#include "Register.h"
#include "Memory.h"

using namespace std;

class Machine {
public:
    void Run_Instruction();
    void Move(string address1, string address2, Register &reg);
    void Load_To_Register(string address1, string value, Register &reg);
    void Load_From_Memory_To_Register(string address4, string address1, Register &reg, Memory &mem);
    void Store(string address1, string address2, Register & reg, Memory & mem);
    int Hexa_To_Decimal(string Hex_Number);
    void OrBitwiseOperation(string& address1, string& address2, string& address3, Register& reg);
    void AndBitwiseOperation(string& address1, string& address2, string& address3, Register& reg);
};

#endif // MACHINE_H
