//
// Created by calebcintary on 2/22/21.
//

#include "hemming.h"

using namespace std;

string* toHemming(char a);

string *encode(const string &arg2) {
    ifstream fis;
    fis.open(arg2);

    auto* array = new string;
    if (fis.is_open()) {
        int i = 0;
        while(!fis.eof()) {
            char a;
            fis >> a;
            if (!fis.eof()) {
                array->append(*toHemming(a));
            }

        }
        fis.close();
        return array;
    } else {
        throw runtime_error("File not found");
    }
}

string* toHemming(char a) {
    string array;

    int maxPow = floor(log2(a));
    //FIRST ZEROS
    int i = 0;
    for (; i < 7 - maxPow; ++i) {
        array += "0";
    }

    char subA = a;
    while (subA > 0) {
        unsigned int powered = pow(2, maxPow);
        if (subA >= powered) {
            subA -= powered;
            array += "1";
        } else {
            array += "0";
        }
        --maxPow;
    }
    for (i = array.length(); i < 8; ++i)
        array += "0";

    unsigned int arrayHemming[12];
    i = 0;
    auto pArray1 = array.begin();
    unsigned int powered = 1;
    for(; i < 12; ++i) {
        arrayHemming[i] = 0;
        if (i != powered - 1) {
            char digit = *(pArray1++);
            if (digit == '1') {
                arrayHemming[i] = 1;
            }

        } else {
            powered *= 2;
        }
    }


    powered = 1;
    i = 0;
    for(; i < 12; ++i) {
        if (i == (powered - 1)) {
            unsigned int* pArray = arrayHemming + i;
            unsigned int* pEnder = pArray + powered;
            while (pArray < arrayHemming + 12) {
                arrayHemming[i] ^= *pArray;
                ++pArray;

                if (pArray == pEnder) {
                    pEnder += 2 * powered;
                    pArray += powered;
                }
            }

            powered *= 2;
        }
    }

    string stringArrayHemming;
    i = 0;
    for (; i < 12; ++i) {
        if (arrayHemming[i] == 1) {
            stringArrayHemming += "1";
        } else {
            stringArrayHemming += "0";
        }
    }
    auto* pstring = new string(stringArrayHemming);
    return pstring;

}

