//
// Created by Michael Neuhold on 29.11.19.
//

#ifndef ADT_VERTEX_T_H
#define ADT_VERTEX_T_H

#include <iostream>

class vertex_t {
public:
    vertex_t();
    vertex_t(std::string payload);
    std::string get_payload();

private:
    std::string payload;

};


#endif //ADT_VERTEX_T_H
