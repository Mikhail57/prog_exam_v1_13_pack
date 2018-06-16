//
// Created by mikhail-mustakimov on 16.06.18.
//

#ifndef V1_13_PACK_ALGO_H
#define V1_13_PACK_ALGO_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "structs.h"

unordered_message readMessage(const char *filename);

std::string getStringMessage(unordered_message msg);

#endif //V1_13_PACK_ALGO_H
