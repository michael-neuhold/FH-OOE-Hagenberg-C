//
// Created by Michael Neuhold on 06.12.19.
//

#include <iostream>
#include "io.h"

void separator() {
    std::cout << "\n------------------------------------------------------------------\n";
}

void print_header(std::string msg) {
    separator();
    std::cout << msg << std::endl;
    separator();
}