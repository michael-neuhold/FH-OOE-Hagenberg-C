#include <iostream>
#include "deque.h"

int main() {
    std::cout << "Double ended queu" << std::endl;

    // init queu

    swo::deque<int> q1;
    swo::deque<int> q2(20);
    swo::deque<int> g3{1,2,3};

    swo::deque<int> g4{g3};
    swo::deque<int> g5(std::move(g3));

    g3 = {1,2,3,4,5,6};

}