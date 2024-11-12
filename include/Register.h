#ifndef ASSIGNMENT_1_TASK_4_REGISTER_H
#define ASSIGNMENT_1_TASK_4_REGISTER_H

#include <bits/stdc++.h>
using namespace std;

class Register {
private:
    vector<string> registers = vector<string>(16);

public:
    Register();
    void setRegister(const string& Address, const string& Value);
    string getRegister(const string& location);
    void displayRegister();
};

#endif //ASSIGNMENT_1_TASK_4_REGISTER_H
