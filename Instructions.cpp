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
    ifstream file(fileName);                                   // get file name and check the validity of format.
    while (fileName.size() < 5 || fileName.substr(fileName.size() - 4, 4) != ".txt" || !file.good()) {
        cout << "\nThe file name should be like this ----> (file name).txt\n";
        cout << "Please enter a valid file name :";
        getline(cin, fileName);
    }
    content << file.rdbuf();
    fileContent = content.str();
    for (int i = 0; i < fileContent.size(); ++i) {                  // remove spaces and end lines from the file.
        fileContent.erase(remove(fileContent.begin(), fileContent.end(), '\n'), fileContent.end());
        fileContent.erase(remove(fileContent.begin(), fileContent.end(), ' '), fileContent.end());
    }
    for (int i = 0; i < fileContent.size(); i += 4) {               // put every 4 characters in an index in the vector.
        instructions.push_back(fileContent.substr(i, 4));
    }
    for (int i = 0; i < instructions.size(); ++i) {
        for (int j = 0; j < 4; ++j) {                               // check the validity of each char in each index.
            if (instructions[i][j] < 48 || (instructions[i][j] > 57 && instructions[i][j] < 65) ||
                (instructions[i][j] > 70 && instructions[i][j] < 97) || instructions[i][j] > 102) {
                instructions.erase(instructions.begin() + i);
                i--;
                break;
            }
        }
    }
    instruct = instructions;
}

string Instructions::OneComplement(string binary) {
    while (binary.size() < 8) { binary = '0' + binary; }

    // For ones complement flip every bit in the binary number.
    for (int i = 0; i < binary.size(); ++i) {
        binary[i] = (binary[i] == '0') ? '1' : '0';
    }
    return binary;
}

string Instructions::twoComplement(string binary) {
    string onesComplement = OneComplement(binary);

    // For twos complement add 1 to the ones complement.
    int carry = 1;
    for (int i = binary.size() - 1; i >= 0; --i) {
        if (onesComplement[i] == '1' && carry == 1) {
            onesComplement[i] = '0';
        } else if (onesComplement[i] == '0' && carry == 1) {
            onesComplement[i] = '1';
            carry = 0;
        }
    }
    return onesComplement;
}

string Instructions::decimalToBinary(int Dec_Number) {
    string bin;
    bool isNegative = false;

    // If the number is zero, return 0.
    if (Dec_Number == 0) { return "0"; }
        // If the number is negative, convert it to positive and set the isNegative flag to true.
    else if (Dec_Number < 0) {
        isNegative = true, Dec_Number *= -1;
    }

    // Convert the decimal number to binary.
    while (Dec_Number > 0) {
        bin = char('0' + Dec_Number % 2) + bin;
        Dec_Number /= 2;
    }

    // Make the binary number have 8 bits.
    while (bin.size() < 8) { bin = '0' + bin; }
    // Return the binary number.
    // If the number was negative, return the two's complement of the binary number.
    return isNegative ? twoComplement(bin) : bin;
}

int Instructions::binaryToDecimal(string binNumber) {
    int dec = 0;
    deque<char> bit;
    for (int i = 0; i < int(binNumber.size()); i++) {
        bit.push_front(binNumber[i]);               // Put every index in an array but reversed.
    }
    for (int i = 0; i < int(bit.size()); i++) {
        dec += static_cast<int>(bit[i] - '0') * pow(2, i);  // Evaluate the value of every index.
    }
    return dec;
}

double Instructions::binaryToDecimalFraction(const string &binaryFraction) {
    // Get the fractional and integer parts of the binary number.
    string fractionalPart = binaryFraction.substr(binaryFraction.find('.') + 1);
    string integerPart = binaryFraction.substr(0, binaryFraction.find('.'));
    // Calculate the decimal value of the fractional part.
    double decimalValue = 0.0;
    for (int i = 0; i < fractionalPart.size(); i++) {
        if (fractionalPart[i] == '1') {
            decimalValue += pow(2, -(i + 1));
        }
    }
    // Return the sum of the integer and fractional parts.
    return binaryToDecimal(integerPart) + decimalValue;
}

string Instructions::fractionDecimalToBinary(double decimalFraction, int precision = 10) {
    string binary = "0.";
    // Get the integer part of the decimal number and subtract it from the decimal number.
    int integerPart = int(decimalFraction);
    decimalFraction -= integerPart;
    // If the decimal number is an integer, return the binary of the integer part.
    if (decimalFraction == 0) return decimalToBinary(integerPart);
    // If the decimal number is negative, make it positive.
    decimalFraction < 0 ? decimalFraction *= -1 : decimalFraction;
    // Calculate the binary of the fractional part.
    while (decimalFraction > 0 && precision > 0) {
        decimalFraction *= 2;
        int bit = static_cast<int>(decimalFraction);
        binary += to_string(bit);
        decimalFraction -= bit;
        precision--;
    }
    binary.erase(binary.begin());
    return decimalToBinary(integerPart) + binary;
}

int Instructions::Hexa_To_Decimal(string Hex_Number) {
    int decimalValue = stoi(Hex_Number, nullptr, 16);
    return decimalValue;
}

string Instructions::Decimal_To_Hexa(int Dec_Number) {
    stringstream hexadecimal;
    hexadecimal << hex << uppercase << setw(2) << setfill('0') << (static_cast<uint16_t>(Dec_Number) & 0xFF);
    return hexadecimal.str();
}

//#####################################################################################################################

void Instructions::Load_From_Memory_To_Register(string address4, string address1, Register &reg, Memory &mem) {
    int index = Hexa_To_Decimal(address4);
    string content = mem.getMemory(index);
    reg.setRegister(address1, content);
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

//#####################################################################################################################

string Instructions::AddingBinaryNumbers(string binary1, string binary2) {
    string result;
    int carry = 0;
    binary1 = '0' + binary1, binary2 = '0' + binary2;

    // Make the two binary numbers have the same size.
    while (binary1.size() > binary2.size()) { binary2 = '0' + binary2; }
    while (binary2.size() > binary1.size()) { binary1 = '0' + binary1; }

    // Adding the two binary numbers.
    for (int i = binary1.size() - 1; i >= 0; --i) {
        int sum = (binary1[i] - '0') + (binary2[i] - '0') + carry;
        if (sum == 0) {
            result.push_back('0');
            carry = 0;
        } else if (sum == 1) {
            result.push_back('1');
            carry = 0;
        } else if (sum == 2) {
            result.push_back('0');
            carry = 1;
        } else if (sum == 3) {
            result.push_back('1');
            carry = 1;
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

void Instructions::AddingTwoComplement(string &address1, string &address2, string &address3, Register &reg) {
    int valReg1 = Hexa_To_Decimal(reg.getRegister(address2));
    int valReg2 = Hexa_To_Decimal(reg.getRegister(address3));

    if (valReg1 > 127) { valReg1 -= 256; }
    if (valReg2 > 127) { valReg2 -= 256; }

    string binary1 = decimalToBinary(valReg1);
    string binary2 = decimalToBinary(valReg2);
    string result = AddingBinaryNumbers(binary1, binary2);
    reg.setRegister(address1, Decimal_To_Hexa(binaryToDecimal(result)));
}

string Instructions::ImplicitNormalization(double Dec_Number) {
    // Check if the number is negative. If it is negative, make it positive and set the flag to true.
    bool isNegative = false;
    if (Dec_Number < 0) {
        isNegative = true;
        Dec_Number *= -1;
    }
    // Convert the number to binary and get the index of the first one bit.
    string binary = fractionDecimalToBinary(Dec_Number);
    int floatingIndex = 8, firstOneBitIndex = 0;
    for (int i = 0; i < binary.size(); ++i) {
        if (binary[i] == '1') {
            firstOneBitIndex = i;
            break;
        }
    }
    // Calculate the exponent.
    int exponent = Dec_Number >= 1 ? floatingIndex - firstOneBitIndex - 1 : (firstOneBitIndex - 1) * -1;
    // Calculate and Normalize the mantissa.
    double tempBinary = stod(fractionDecimalToBinary(Dec_Number));
    tempBinary *= pow(10, -exponent);
    // Construct the final result.
    string result;
    isNegative ? result.push_back('1') : result.push_back('0');
    result += decimalToBinary(exponent + 4).substr(5, 4);
    result += to_string(tempBinary).substr(2, 4);
    return result;
}

double Instructions::encodeImplicitNormalization(string hexNumber) {
    string binary = decimalToBinary(Hexa_To_Decimal(hexNumber));
    // Calculate the exponent and the mantissa.
    int exponent = binaryToDecimal(binary.substr(1, 3));
    int power = exponent - 4;
    double mantissaPart = stod("1." + binary.substr(4, 4));
    double result = mantissaPart * pow(10, power);
    // If it is negative, make it negative. Else, make it positive.
    // Return the result.
    return binary[0] == '1' ? -binaryToDecimalFraction(to_string(result)) : binaryToDecimalFraction(to_string(result));
}

void Instructions::AddingFloatingNumber(string &address1, string &address2, string &address3, Register &reg) {
    double valReg1 = encodeImplicitNormalization(reg.getRegister(address2));
    double valReg2 = encodeImplicitNormalization(reg.getRegister(address3));
    // Calculate the sum of the two floating numbers.
    double temp = valReg1 + valReg2;
    // Normalize the result.
    int tempResult = binaryToDecimal(ImplicitNormalization(temp));
    reg.setRegister(address1, Decimal_To_Hexa(tempResult));
}

void Instructions::OrBitwiseOperation(string &address1, string &address2, string &address3, Register &reg) {
    int valReg1 = Hexa_To_Decimal(reg.getRegister(address2));
    int valReg2 = Hexa_To_Decimal(reg.getRegister(address3));
    int result = valReg1 | valReg2;
    reg.setRegister(address1, Decimal_To_Hexa(result));
}

void Instructions::AndBitwiseOperation(string &address1, string &address2, string &address3, Register &reg) {
    int valReg1 = Hexa_To_Decimal(reg.getRegister(address2));
    int valReg2 = Hexa_To_Decimal(reg.getRegister(address3));
    int result = valReg1 & valReg2;
    reg.setRegister(address1, Decimal_To_Hexa(result));
}

//#####################################################################################################################

void Instructions::exclusiveOr(const string &address1, const string &address2, const string &address3, Register &reg) {
    string value2 = reg.getRegister(address2);
    string value3 = reg.getRegister(address3);
    // Assuming valueR and valueS are in hexadecimal format
    int num2 = stoi(value2, nullptr, 16);
    int num3 = stoi(value3, nullptr, 16);
    // Perform XOR operation
    int result = num2 ^ num3;
    // Store the result in register T
    reg.setRegister(address1, Decimal_To_Hexa(result));
}

void Instructions::rotateRight(const string &address1, int X, Register &reg) {
    // Retrieve the hexadecimal value from the register
    string value1 = reg.getRegister(address1);
    // Convert the hexadecimal value to decimal
    int num1 = stoi(value1, nullptr, 16);

    // Create a 16-bit bitset from the decimal value
    bitset<16> bits(num1);

    // Convert the bitset to a binary string representation
    string binaryString = bits.to_string();

    // Ensure X is a valid rotation amount
    X = X % 16; // Only need to rotate within the range of 0-15

    // Perform the right rotation
    if (X > 0) {
        // Right rotate the binary string
        string rotatedString = binaryString.substr(binaryString.size() - X) +
                               binaryString.substr(0, binaryString.size() - X);
        binaryString = rotatedString; // Update the binary string
    }

    // Convert the rotated binary string back to decimal
    int res = binaryToDecimal(binaryString);

    // Convert decimal to hexadecimal
    string resultAfter = Decimal_To_Hexa(res);

    // Store back the result in the same register
    reg.setRegister(address1, resultAfter);
}

void Instructions::conditionalJump(const string &R, int XY, Register &reg, int &currentInstructionIndex) {
    int value = stoi(reg.getRegister(R), nullptr, 16);
    if (value == 0) {
        currentInstructionIndex = XY - 1;  // Jump to instruction XY
    }
}

void Instructions::halt() {
    halted = true;  // Signal to halt execution in the Machine class
}

void Instructions::conditionalJumpGreater(const string &R, int XY, Register &reg, int &currentInstructionIndex) {
    int value = stoi(reg.getRegister(R), nullptr, 16);
    if (value > 0) {
        currentInstructionIndex = XY - 1;  // Jump to instruction XY
    }
}
