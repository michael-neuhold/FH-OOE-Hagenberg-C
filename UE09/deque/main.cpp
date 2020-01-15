#include <iostream>
#include <vector>
#include "deque.h"

void separator() {
    std::cout << "===========================================" << std::endl;
}


int main() {


    /* ================== ================== ================== ================== ================== */

    // standard CONSTRUCTOR

    swo::deque<int> q1;
    q1.push_back(2);
    q1.push_back(22);
    q1.push_back(222);
    for(int i = 0; i < 3; i++ ) {
        std::cout << "value[" << i << "] = " << q1.m_data[i] << std::endl;
    }

    separator();

    /* ================== ================== ================== ================== ================== */

    // COUNT, VALUE CONSTRUCTOR

    swo::deque<int> q2(10, 20);
    for(int i = 0; i < 10; i++ ) {
        std::cout << "value[" << i << "] = " << q2.m_data[i] << std::endl;
    }
    std::cout << "current front: " << q2.m_front << std::endl;
    std::cout << "current back: " << q2.m_back << std::endl;

    separator();

    /* ================== ================== ================== ================== ================== */

    // COUNT CONSTRUCTOR

    swo::deque<int> q3(10);
    q3.push_back(1);
    q3.push_back(11);
    q3.push_back(111);
    for(int i = 0; i < 3; i++ ) {
        std::cout << "value[" << i << "] = " << q3.m_data[i] << std::endl;
    }
    std::cout << "current front: " << q3.m_front << std::endl;
    std::cout << "current back: " << q3.m_back << std::endl;

    separator();

    /* ================== ================== ================== ================== ================== */

    // COPY CONSTRUCTOR

    swo::deque<int> q4(q1);
    for(int i = 0; i < 3; i++ ) {
        std::cout << "value[" << i << "] = " << q4.m_data[i] << std::endl;
    }

    separator();

    /* ================== ================== ================== ================== ================== */

    // MOVE CONSTRUCTOR

    separator();

    /* ================== ================== ================== ================== ================== */

    // INITLIST CONSTRUCTOR

    swo::deque<int> q6 = { 1 , 2 , 3 , 4 , 5 , 6 };
    for(int i = 0; i <= q6.m_back; i++ ) {
        std::cout << "value[" << i << "] = " << q6.m_data[i] << std::endl;
    }

    separator();

    /* ================== ================== ================== ================== ================== */

    // TEST push front combined with push back

    swo::deque<int> q7;
    q7.push_front(3);
    q7.push_front(33);
    q7.push_front(333);
    q7.push_back(4);
    q7.push_back(44);
    q7.push_back(444);
    q7.push_back(444);
    q7.push_back(444);
    q7.push_back(444);
    q7.push_back(444);
    q7.push_back(444);
    q7.push_back(444);
    q7.push_back(444);

    for(int i = 0; i < 10; i++ ) {
        std::cout << "value[" << i << "] = " << q7.m_data[i] << std::endl;
    }
    std::cout << "current front: " << q7.m_front << std::endl;
    std::cout << "current back: " << q7.m_back << std::endl;

    separator();

    /* ================== ================== ================== ================== ================== */


    swo::deque<int>::iterator begin = q7.begin();
    swo::deque<int>::iterator end = q7.end();
    /*std::cout << *begin << std::endl;
    begin++;
    if(begin == q6.end()) {
        std::cout << *begin << std::endl;
    }*/

   // begin += 2;
    std::cout << *begin << std::endl;

    //end -= 2;
    std::cout << *end << std::endl;


    // print deque
    std::cout << "deque: {";
    for(swo::deque<int>::iterator p = q7.begin();p != q7.end();p++) {
        std::cout << (p == q7.begin() ? "":",") << *p;
    }
    std::cout << "}" << std::endl;


    std::cout << "deque: {";
    for(swo::deque<int>::iterator p = q7.end();p != q7.begin();p--) {
        std::cout << (p == q7.end() ? "":",") << *p;
    }
    std::cout << "}" << std::endl;

    separator();

    /* ================== ================== ================== ================== ================== */






}