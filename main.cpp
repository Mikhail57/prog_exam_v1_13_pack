#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "structs.h"
#include "algo.h"

using namespace std;


int main() {
    const char *filename = "/home/mikhail-mustakimov/prog_exam/v1_13_pack/input/input.txt";
    unordered_message msg = readMessage(filename);

    cout << "Original (unordered) message packages: " << endl;
    for (auto pkg : msg.packages) {
        cout << "Package(num=" << pkg.num << ", content=" << pkg.message << ")" << endl;
    }
    cout << "-------------------" << endl;


    cout << "-------------------" << endl;
    cout << "Decoded message: '" << getStringMessage(msg) << "'" << endl;
    cout << "-------------------" << endl;

    return 0;
}