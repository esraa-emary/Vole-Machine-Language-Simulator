#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <bits/stdc++.h>
#include "Register.h"
#include "Memory.h"
using namespace std;

class Instructions {
private:
    vector<string> instruct;
    bool halted = false;
    int programCounter = 0;
public:
    void Read_From_File();
    vector<string> Get_Instructions();
    Instructions(){}

    string OneComplement(string binary);
    string twoComplement(string binary);
    string decimalToBinary(int Dec_Number);
    int Hexa_To_Decimal(string Hex_Number);
    string Decimal_To_Hexa (int Dec_Number);
    int binaryToDecimal(string binNumber);
    double binaryToDecimalFraction(const string& binaryFraction);
    string fractionDecimalToBinary(double decimalFraction, int precision);

    void Move(string address1, string address2, Register &reg);
    void Load_To_Register(string address1, string value, Register &reg);
    void Load_From_Memory_To_Register(string address4, string address1, Register &reg, Memory &mem);
    void Store(string address1, string address2, Register & reg, Memory & mem);

    string AddingBinaryNumbers(string binary1, string binary2);
    void AddingTwoComplement(string& address1, string& address2, string& address3, Register& reg);
    string ImplicitNormalization(double Dec_Number);
    double encodeImplicitNormalization(string hexNumber);
    void AddingFloatingNumber(string& address1, string& address2, string& address3, Register& reg);
    void OrBitwiseOperation(string& address1, string& address2, string& address3, Register& reg);
    void AndBitwiseOperation(string& address1, string& address2, string& address3, Register& reg);

    void halt();
    bool getHalted(){return halted;}
    void rotateRight(const string& address1, int X, Register& reg);
    void conditionalJump(const string& address1, int XY, Register& reg,Memory& mem, vector<string>& instructions, int currentI);
    void exclusiveOr(const string& address1, const string& address2, const string& address3, Register& reg);
    void conditionalJumpGreater(const string& address1, int XY, Register& reg,Memory& mem, vector<string>& instructions, int currentI);
    void setProgramCounter(int address) {programCounter = address;}
};

#endif //INSTRUCTIONS_H
