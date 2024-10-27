#include <bits/stdc++.h>
#include <bitset>
#include "Machine.h"
#include <fstream>

using namespace std;

vector<string> Instructions::Read_From_File() {
    string fileName, fileContent, pos = "";
    bool found = false;
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
    for (int i = 0; i < fileContent.size(); ++i) {
        if (fileContent[i + 1] == 'x') {
            pos += fileContent[i + 2];
            i += 2;
        } else {
            pos += fileContent[i];
            instructions.push_back(pos);
            pos = "";
        }
    }
    return instructions;
}



