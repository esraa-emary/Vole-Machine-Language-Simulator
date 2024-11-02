#include "Register.h"
#include <bits/stdc++.h>
using namespace std;

Register::Register() {
    for(string& Value: registers) {
        Value = "00";
    }
}

void Register::setRegister(const string& address, const string& value) {
    int index = stoi(address,nullptr,16);
    if (index >= registers.size()) cout << "The Register location is not found..\n";
    else registers[index] = value;
}

string Register::getRegister(const string& address) {
    int index = stoi(address, nullptr,16);
    if (index < registers.size()) return registers[index];
    else return "Is not found..\n";
}

void Register::displayRegister() {
    cout << "The Registers: \n";
    for (int i = 0; i < registers.size(); ++i) {
        if (i > 9) cout << " - R" << static_cast<char>(65+i-10)<< ": " << registers[i] << endl;
        else cout << " - R" << i << ": " << registers[i] << endl;
    }
    cout << endl;
}
