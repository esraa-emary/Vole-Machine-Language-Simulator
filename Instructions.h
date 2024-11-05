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
public:
    void readFromFile();
    vector<string> getInstructions();
    Instructions(){}

    string oneComplement(string binary);
    string twoComplement(string binary);
    string decimalToBinary(int Dec_Number);
    int hexaToDecimal(string Hex_Number);
    string decimalToHexa (int Dec_Number);
    int binaryToDecimal(string binNumber);
    double binaryToDecimalFraction(const string& binaryFraction);
    string fractionDecimalToBinary(double decimalFraction, int precision);

    void move(string address1, string address2, Register &reg);
    void loadToRegister(string address1, string value, Register &reg);
    void loadFromMemoryToRegister(string address4, string address1, Register &reg, Memory &mem);
    void store(string address1, string address2, Register & reg, Memory & mem);

    string addingBinaryNumbers(string binary1, string binary2);
    void addingTwoComplement(string& address1, string& address2, string& address3, Register& reg);
    string implicitNormalization(double Dec_Number);
    double encodeImplicitNormalization(string hexNumber);
    void addingFloatingNumber(string& address1, string& address2, string& address3, Register& reg);
    void orBitwiseOperation(string& address1, string& address2, string& address3, Register& reg);
    void andBitwiseOperation(string& address1, string& address2, string& address3, Register& reg);

    void halt();
    bool getHalted(){return halted;}
    void rotateRight(const string& address1, int X, Register& reg);
    int conditionalJump(const string& address1, int XY, Register& reg,Memory& mem, int& currentProgramCounter,bool& ff);
    void exclusiveOr(const string& address1, const string& address2, const string& address3, Register& reg);
    int conditionalJumpGreater(const string& address1, int XY, Register& reg,Memory& mem, int& currentProgramCounter,bool& ff);
    bool compareTwosComplement(const std::string &bin1, const std::string &bin2);
};

#endif //INSTRUCTIONS_H
