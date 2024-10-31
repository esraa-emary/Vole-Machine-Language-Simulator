#include <bits/stdc++.h>
#include "Machine.h"

using namespace std;

int main() {
    cout << "Welcome To Our Vole Machine Simulator Program!\n";
    Machine m;
    m.Run_Instruction();
    m.getRegister();
    m.getMemory();
    return 0;
}
