//
// Created by calebcintary on 2/22/21.
//

#include "hemming.h"

std::string * repair(const std::string &fname) {
    std::ifstream fis;
    fis.open(fname);
    if (!fis.is_open()) {
        throw std::runtime_error ("Failed to open input file");
    }

    std::string str;

    fis >> str;

    if (str.length() % 12 != 0) {
        throw std::runtime_error ("Corrupted file");
    }

    int i = 0;
    auto str_temp = new std::string;
    while (i != str.length()) {
        std::string slice = str.substr(i, 12);
        std::string hem;
        for (int powered = 1; powered <= 8; powered *= 2) {
            int result = 0;
            auto pArray = slice.begin() + powered - 1;
            while (pArray < slice.end()) {
                auto pEnder = pArray + powered;
                for(; pArray < pEnder; ++pArray) {
                    if (pArray >= slice.end() ) {
                        break;
                    }
                    int digit = 0;
                    if (*pArray == '1') {
                        digit = 1;
                    }
                    result ^= digit;
                }
                pArray += powered;
            }
            hem += std::to_string(result);
        }
        if (hem != "0000") {
            int error_place = -1;
            for (int j = 0; j < 4; ++j) {
                if (hem[j] == '1') {
                    error_place += (int)pow(2, j);
                }
            }
            if (slice[error_place] == '1') {
                slice[error_place] = '0';
            } else {
                slice[error_place] = '1';
            }
        }
        *str_temp += slice;

        i += 12;
    }


    return str_temp;
}

