//
// Created by calebcintary on 2/22/21.
//

#ifndef UNIVERSAL_EX2_HEMMING_H
#define UNIVERSAL_EX2_HEMMING_H

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

std::string * encode(const std::string &arg2);

std::string * corrupt(std::string *fname);

std::string * repair(const std::string &fname);

std::string * decode(const std::string &fname);

#endif //UNIVERSAL_EX2_HEMMING_H
