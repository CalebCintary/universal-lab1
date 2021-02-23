cmake_minimum_required(VERSION 3.17)
project(universal_lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(app main.cpp hemming.h hemming_encode.cpp hemming_corrupt.cpp hemming_repair.cpp hemming_decode.cpp)
