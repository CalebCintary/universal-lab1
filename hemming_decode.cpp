//
// Created by calebcintary on 2/23/21.
//

#include "hemming.h"

std::string * decode(const std::string &fname) {
    std::ifstream fis;
    fis.open(fname);
    fis.unsetf(std::ios_base::skipws);
    if (!fis.is_open()) {
        throw std::runtime_error("Failed to open file");
    }

    std::string str;
    fis >> str;

    int i = 0;
    std::string str_temp;
    auto result = new std::string;
    while (i < str.length()) {
        std::string slice = str.substr(i, 12);
        int powered = 1;
        for (int j = 0; j < 12; ++j) {
            if (j != (powered - 1)) {
                str_temp += slice[j];
            } else {
                powered *= 2;
            }
        }
        i += 12;
    }

    i = 0;
    while (i < str_temp.length()) {
        std::string slice = str_temp.substr(i, 8);
        std::reverse(slice.begin(), slice.end());
        char result_char = 0;
        for (int j = 0; j < 8; ++j) {
            if (slice[j] == '1') {
                result_char += (char) pow(2, j);
            }
        }
        *result += result_char;

        i += 8;
    }

    return result;
}

