//
// Created by calebcintary on 2/22/21.
//

#include "hemming.h"

#include <chrono>
#include <random>

using namespace std;

string *corrupt(string *fname) {
    ifstream fis;
    fis.open(*fname);
    fis.unsetf(ios_base::skipws);
    if (fis.is_open()) {
        auto str = new string;
        fis >> *str;
        if (str->length() % 12 != 0) {
            throw runtime_error("Corrupted input file");
        }
        int i = 0;
        while (i < str->length()) {
            bool docorrupt = false;
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::default_random_engine generator(seed);
            std::uniform_int_distribution<int> docorrupt_chance(1, 4);
            std::uniform_int_distribution<int> placechance(0, 11);

            int i1 = docorrupt_chance(generator);
            if (i1 == 1) {
                docorrupt = true;
            }
            if (docorrupt) {
                int place = placechance(generator);
                if ((*(str))[i + place] == '1') {
                    (*(str))[i + place] = '0';
                } else {
                    (*(str))[i + place] = '1';
                }
            }

            i += 12;
        }
        return str;

    } else {
        throw runtime_error("Failed to open input file");
    }

}