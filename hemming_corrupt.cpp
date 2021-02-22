//
// Created by calebcintary on 2/22/21.
//

#include "hemming.h"

using namespace std;

string *corrupt(string *fname) {
    ifstream fis;
    fis.open(*fname);
    if (fis.is_open()) {
        auto str = new string;
        fis >> *str;
        if (str->length() % 12 != 0) {
            throw runtime_error("Corrupted input file");
        }
        int i = 0;
        while (i < str->length()) {
            bool docorrupt = false;
            srand(time(0));

            int i1 = 1 + (rand() % 4);
            if (i1 == 1) {
                docorrupt = true;
            }
            if (docorrupt) {
                int place = rand() % 12;
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