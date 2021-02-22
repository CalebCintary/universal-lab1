#include <iostream>
#include <string>
#include "hemming.h"

using namespace std;



int main(int argc, char* argv[]) {
    if (argc == 3) {
        string arg1 (argv[1]);
        string arg2 (argv[2]);

        if (arg1 == "--encode") {
            auto array = encode(arg2);
            cout << *array;
            delete array;
        }

        if (arg1 == "--corrupt") {
            auto str = corrupt(&arg2);
            cout << *str;
            delete str;
        }

        if (arg1 == "--repair") {
            auto str = repair(arg2);
            cout << *str;
            delete str;
        }

        if (arg1 == "--decode") {
            auto str = decode(arg2);
            cout << *str;
            delete str;
        }
    }

    if (argc == 5) {
        string arg1 (argv[1]);
        string arg2 (argv[2]);
        string arg3 (argv[3]);
        string arg4 (argv[4]);


        if ((arg1 == "--encode") && (arg3 == "-f")) {
            ofstream fos;
            fos.open(arg4);
            if (fos.is_open()) {
                auto str = encode(arg2);
                fos << *str;
                delete str;
                fos.close();
            } else {
                throw runtime_error("Failed to open output file");
            }
        }

        if ((arg1 == "--corrupt") && (arg3 == "-f")) {
            ofstream fos;
            fos.open(arg4);
            if (fos.is_open()) {
                auto str = corrupt(&arg2);
                fos << *str;
                delete str;
                fos.close();
            } else {
                throw runtime_error("Failed to open output file");
            }

        }

        if ((arg1 == "--repair") && (arg3 == "-f")) {
            ofstream fos;
            fos.open(arg4);
            if (fos.is_open()) {
                auto str = repair(arg2);
                fos << *str;
                delete str;
                fos.close();
            } else {
                throw runtime_error("Failed to open output file");
            }
        }

        if ((arg1 == "--decode") && (arg3 == "-f")) {
            ofstream fos;
            fos.open(arg4);
            if (fos.is_open()) {
                auto str = decode(arg2);
                fos << *str;
                delete str;
                fos.close();
            } else {
                throw runtime_error("Failed to open output file");
            }
        }
    }


    return 0;
}


