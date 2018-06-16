#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "structs.h"
#include "algo.h"

using namespace std;


int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Wrong number of parameters!" << endl;
        cerr << "You should run with 1 command line option - filename" << endl;
        return -1;
    }
    unordered_message msg = readMessage(argv[1]);

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