//
// Created by mikhail-mustakimov on 16.06.18.
//

#include "algo.h"

using namespace std;

unordered_message readMessage(const char *filename) {
    ifstream in(filename);
    unordered_message msg = unordered_message();
    string buf;
    states state = PACKAGE_NUM;
    size_t pos = 0;
    package tmpPkg;
    int tmpNum = 0;
    while (!in.eof()) {
        char ch = static_cast<char>(in.get());
        pos++;

        if (ch == ',') {
            if (state != PACKAGE_CONTENT) {
                cerr << "Illegal state! Unexpected comma at " << pos << "!" << endl;
                return unordered_message();
            }
            state = PACKAGE_NUM;
            tmpPkg.message = buf;
            msg.packages.push_back(tmpPkg);
            tmpPkg.message = "";
            tmpPkg.num = -1;
            buf = "";
            tmpNum = 0;
            continue;
        } else if (ch == '.') {
            if (state == PACKAGE_NUM) {
                if (tmpNum == 0)
                    state = MESSAGE_SIZE;
                else
                    state = PACKAGE_CONTENT;
                tmpPkg.num = tmpNum;
            } else {
                if (state == MESSAGE_SIZE) {
                    state = PACKAGE_CONTENT;
                    msg.size = tmpNum;
                } else {
                    // TODO: error
                }
            }
            continue;
        }
        switch (state) {
            case PACKAGE_NUM:
            case MESSAGE_SIZE:
                if (ch < '0' || ch > '9') {
                    cerr << "Wrong input. Symbol '" << ch << "' is not a number" << endl;
                    return unordered_message();
                }
                tmpNum *= 10;
                tmpNum += (ch - '0');
                break;
            case PACKAGE_CONTENT:
                buf += ch;
                break;
        }
    }
    tmpPkg.message = buf.substr(0, buf.size() - 1);
    msg.packages.push_back(tmpPkg);
    return msg;
}

struct {
    bool operator()(package a, package b) const
    {
        return a.num < b.num;
    }
} pkgCmp;

string getStringMessage(unordered_message msg) {
    sort(msg.packages.begin(), msg.packages.end(), pkgCmp);
    string res;
    for (auto pkg : msg.packages) {
        res += pkg.message;
    }
    return res;
}