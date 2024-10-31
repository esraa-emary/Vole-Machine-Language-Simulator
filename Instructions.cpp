#include "Instructions.h"
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

void Instructions::exclusiveOr(int R, int S, int T) {
    int result = getRegister(S) ^ getRegister(T);
    setRegister(R, result);

    cout << "Performed XOR between registers " << S << " and " << T << ". Result stored in register " << R << ": " << result << endl;
}

void Instructions::rotateRight(int R, int X) {
    int value = getRegister(R);
    int rotatedValue = (value >> X) | (value << (32 - X));
    setRegister(R, rotatedValue);

    cout << "Rotated register " << R << " to the right by " << X << " bits. New value: " << rotatedValue << endl;
}

void Instructions::conditionalJump(int R, int XY) {
    if (getRegister(R) == getRegister(0)) {
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

void Instructions::conditionalJumpGreater(int R, int XY) {
    int regRValue = getRegister(R);
    int reg0Value = getRegister(0);
    
    if (regRValue > reg0Value) {
        setProgramCounter(XY);
        cout << "Jumping to address " << XY << " because register " << R << " (" << regRValue << ") is greater than register 0 (" << reg0Value << ")" << endl;
    } else {
        cout << "No jump. Register " << R << " (" << regRValue << ") is not greater than register 0 (" << reg0Value << ")" << endl;
    }
}
