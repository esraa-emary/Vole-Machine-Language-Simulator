#include "Instructions.h"
#include "Register.h"
#include <bits/stdc++.h>

using namespace std;

vector<string> Instructions::Get_Instructions() {
    vector<string> content = instruct;
    return content;
}

void Instructions::Read_From_File() {
    string fileName, fileContent, pos = "";
    stringstream content;
    vector<string> instructions;
    cout << "Please enter file name:";
    getline(cin, fileName);                               // get file name and check the validity of format.
    while (fileName.size() < 5 || fileName.substr(fileName.size() - 4, 4) != ".txt") {
        cout << "\nThe file name should be like this ----> (file name).txt\n";
        cout << "Please enter a valid file name :";
        getline(cin, fileName);
    }
    ifstream file(fileName);
    while (fileName.size() < 5 || fileName.substr(fileName.size() - 4, 4) != ".txt" || !file.good()) {
        cout << "\nThe file name should be like this ----> (file name).txt\n";
        cout << "Please enter a valid file name :";
        getline(cin, fileName);
    }
    content << file.rdbuf();
    fileContent = content.str();
    for (int i = 0; i < fileContent.size(); ++i) {
        fileContent.erase(remove(fileContent.begin(), fileContent.end(), '\n'), fileContent.end());
        fileContent.erase(remove(fileContent.begin(), fileContent.end(), ' '), fileContent.end());
    }
    for (int i = 0; i < fileContent.size(); i += 4) {
        instructions.push_back(fileContent.substr(i, 4));
    }
    for (int i = 0; i < instructions.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            if (instructions[i][j] < 48 || (instructions[i][j] > 57 && instructions[i][j] < 65) ||
                (instructions[i][j] > 70 && instructions[i][j] < 97) || instructions[i][j] > 102) {
                instructions.erase(instructions.begin() + i);
                i --;
                break;
            }
        }
    }
    instruct = instructions;
}

void Instructions::Load_From_Memory_To_Register(string address4, string address1, Register &reg, Memory &mem) {
    int index = Hexa_To_Decimal(address4);
    string content = mem.getMemory(index);
    reg.setRegister(address1,content);
}

void Instructions::Load_To_Register(string address1, string value, Register &reg) {
    reg.setRegister(address1, value);
}

void Instructions::Store(string address1, string address4, Register &reg, Memory &mem) {
    string content = reg.getRegister(address1);
    int address = Hexa_To_Decimal(address4);
    mem.setMemory(address, content);
}

void Instructions::Move(string address2, string address3, Register &reg) {
    string content = reg.getRegister(address2);
    reg.setRegister(address3, content);
}

int Instructions::Hexa_To_Decimal(string Hex_Number) {
    // Convert the hexadecimal number to decimal.
    int decimalValue = stoi(Hex_Number, nullptr, 16);
    return decimalValue;
}

string Instructions::Decimal_To_Hexa (int Dec_Number) {
    stringstream hexadecimal;
    // Convert the decimal number to hexadecimal.
    hexadecimal << hex << (static_cast<uint16_t>(Dec_Number) & 0xFF);
    return hexadecimal.str();
}

string Instructions::OneComplement(string binary) {
    while (binary.size() < 16) {binary = '0' + binary;}

    // For ones complement flip every bit in the binary number.
    for (int i = 0; i < binary.size(); ++i) {
        binary[i] = (binary[i] == '0') ? '1' : '0';
    }
    return binary;
}

string Instructions::TwoComplement(string& binary) {
    string onesComplement = OneComplement(binary);

    // For twos complement add 1 to the ones complement.
    int carry = 1;
    for (int i = binary.size() - 1; i >= 0; --i) {
        if (onesComplement[i] == '1' && carry == 1) onesComplement[i] = '0';
        else if (onesComplement[i] == '0' && carry == 1) {
            onesComplement[i] = '1';
            carry = 0;
        }
    }
    return onesComplement;
}

string Instructions::decimalToBinary(int num) {
    string bin = "";
    bool isNegative = false;

    // If the number is zero, return 0.
    if (num == 0) {return "0";}
        // If the number is negative, convert it to positive and set the isNegative flag to true.
    else if (num < 0) {
        isNegative = true, num *= -1;
    }

    // Convert the decimal number to binary.
    while (num > 0) {
        bin = char('0' + num % 2) + bin;
        num /= 2;
    }

    // Make the binary number have 16 bits.
    while (bin.size() < 16) {bin = '0' + bin;}
    return isNegative ? TwoComplement(bin) : bin;
}

int Instructions::binaryToDecimal(string binNumber) {
    int dec = 0;
    deque<char>bit;
    for (int i = 0; i < int(binNumber.size()); i++){
        bit.push_front(binNumber[i]);                          // Put every index in an array but reversed.
    }
    for (int i = 0; i < int(bit.size()); i++){
        dec += static_cast<int>(bit[i]-'0') * pow(2,i);  // Evaluate the value of every index.
    }
    return dec;
}

string Instructions::AddingBinaryNumbers(string binary1, string binary2) {
    string result;
    int carry = 0;
    binary1 = '0' + binary1, binary2 = '0' + binary2;

    // Make the two binary numbers have the same size.
    while (binary1.size() > binary2.size()) {binary2 = '0' + binary2;}
    while (binary2.size() > binary1.size()) {binary1 = '0' + binary1;}

    // Adding the two binary numbers.
    for (int i = binary1.size() - 1; i >= 0; --i) {
        int sum = (binary1[i] - '0') + (binary2[i] - '0') + carry;
        if (sum == 0) {
            result.push_back('0');
            carry = 0;
        }
        else if (sum == 1) {
            result.push_back('1');
            carry = 0;
        }
        else if (sum == 2) {
            result.push_back('0');
            carry = 1;
        }
        else if (sum == 3) {
            result.push_back('1');
            carry = 1;
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

void Instructions::AddingTwoComplement(string& address1, string& address2, string& address3, Register& reg) {
    int valReg1 = Hexa_To_Decimal(reg.getRegister(address2));
    int valReg2 = Hexa_To_Decimal(reg.getRegister(address3));

    if (valReg1 > 127) {valReg1 -= 256;}
    if (valReg2 > 127) {valReg2 -= 256;}

    string binary1 = decimalToBinary(valReg1);
    string binary2 = decimalToBinary(valReg2);
    string result = AddingBinaryNumbers(binary1, binary2);
    reg.setRegister(address1, Decimal_To_Hexa(binaryToDecimal(result)));
}

void Instructions::OrBitwiseOperation(string& address1, string& address2, string& address3, Register& reg) {
    int valReg1 = Hexa_To_Decimal(reg.getRegister(address2));
    int valReg2 = Hexa_To_Decimal(reg.getRegister(address3));
    int result = valReg1 | valReg2;
    reg.setRegister(address1, Decimal_To_Hexa(result));
}

void Instructions::AndBitwiseOperation(string& address1, string& address2, string& address3, Register& reg) {
    int valReg1 = Hexa_To_Decimal(reg.getRegister(address2));
    int valReg2 = Hexa_To_Decimal(reg.getRegister(address3));
    int result = valReg1 & valReg2;
    reg.setRegister(address1, Decimal_To_Hexa(result));
}

//void Instructions::exclusiveOr(int R, int S, int T) {
//    int result = reg.getRegister(to_string(S)) ^ reg.getRegister(to_string(T));
//    reg.setRegister(to_string(R), to_string(result));
//
//    cout << "Performed XOR between registers " << S << " and " << T << ". Result stored in register " << R << ": " << result << endl;
//}

void Instructions::rotateRight(const string& R, int X) {
    int value = stoi(reg.getRegister(R), nullptr, 16);
    int rotatedValue = (value >> X) | (value << (32 - X));
    stringstream stream;
    stream << std::hex << rotatedValue;
    string rotatedHex = stream.str();

    reg.setRegister(R, rotatedHex);

    cout << "Rotated register " << R << " to the right by " << X << " bits. New value: " << rotatedHex << endl;
}

void Instructions::conditionalJump(const string& R, int XY) {
    if (reg.getRegister(R) == reg.getRegister("0")) {
        setProgramCounter(XY);
        cout << "Jumping to address " << XY << " because register " << R << " equals register 0" << endl;
    } else {
        cout << "No jump. Register " << R << " does not equal register 0." << endl;
    }
}

void Instructions::halt() {
    halted = true;
    cout << "Execution halted." << endl;
}

void Instructions::conditionalJumpGreater(const string& R, int XY) {
    int regRValue = stoi(reg.getRegister(R), nullptr, 16);
    int reg0Value = stoi(reg.getRegister("0"), nullptr, 16);

    if (regRValue > reg0Value) {
        setProgramCounter(XY);
        cout << "Jumping to address " << XY << " because register " << R << " (" << regRValue << ") is greater than register 0 (" << reg0Value << ")" << endl;
    } else {
        cout << "No jump. Register " << R << " (" << regRValue << ") is not greater than register 0 (" << reg0Value << ")" << endl;
    }
}
