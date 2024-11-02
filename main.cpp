#include <bits/stdc++.h>
#include "Machine.h"

using namespace std;

int main() {
    cout << "Welcome to Our Vole Machine Simulator Program!\n";
    Machine m;
    int choice;
    bool running = true;

    while (running) {
        cout << "\nMenu:\n";
        cout << "1) Load new program\n";
        cout << "2) Run program as a whole\n";
        cout << "3) Run step by step\n";
        cout << "4) Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nLoading a new program...\n";
                m.LoadNewProgram();
                break;
            case 2:
                cout << "\nRunning program as a whole...\n";
                m.RunAll();
                break;
            case 3:
                cout << "\nRunning program step by step...\n";
                m.RunStepByStep();
                break;
            case 4:
                cout << "\nExiting the program. Thank you for using our simulator!\n";
                running = false;
                break;
            default:
                cout << "\nInvalid choice. Please select a valid option.\n";
                break;
        }
    }
    return 0;
}
