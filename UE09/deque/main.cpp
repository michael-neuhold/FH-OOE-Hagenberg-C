#include <iostream>
#include <vector>
#include "deque.h"

void separator() {
    std::cout << "===========================================" << std::endl;
}


int main() {

    /* ================== ================== ================== ================== ================== */

    /* ================== ================== ================== ================== ================== */

    // standard CONSTRUCTOR

    swo::deque<int> q1; //{ 1 , 2 , 3 };
    swo::deque<int> q1{ 8 , 7 , 6 , 5 , 4 , 3 , 2 };

    //q1.push_back(20);
    print_queue(std::cout,q1);
    //print_queue(std::cout,q2);

    separator();

}