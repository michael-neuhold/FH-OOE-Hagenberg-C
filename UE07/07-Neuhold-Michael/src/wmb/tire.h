//
// Created by Michael Neuhold on 28.11.19.
//

#ifndef ADT_TIRE_H
#define ADT_TIRE_H

#include <iostream>
#include "main.h"

using namespace std;

class tire {
    friend std::ostream &operator<<(std::ostream &os,const tire &car_tire);
public:
    tire(const double rim_diameter,const int production_year,const string speed_index,const string manufacturer);
    ~tire() = default;
private:
    double rim_diameter;
    int procduction_year;
    string speed_index;
    string manufacturer;
};

#endif //ADT_TIRE_H
