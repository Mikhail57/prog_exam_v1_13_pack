//
// Created by mikhail-mustakimov on 16.06.18.
//

#ifndef V1_13_PACK_STRUCTS_H
#define V1_13_PACK_STRUCTS_H

#include <string>
#include <vector>


struct package {
    int num = 0;
    std::string message;
};

enum states {
    PACKAGE_NUM,
    PACKAGE_CONTENT,
    MESSAGE_SIZE
};

struct unordered_message {
    int size = 0;
    std::vector<package> packages;
};

#endif //V1_13_PACK_STRUCTS_H
