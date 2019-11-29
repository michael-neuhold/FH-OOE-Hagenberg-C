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
    tire(double rim_diameter, int production_year, speed_index_t speed_index, string manufacturer);
    ~tire() = default;
private:
    //Felgendurchmesser
    //Produktionsjahr
    //Geschwindigkeitsindex
    //Hersteller
    double rim_diameter;
    int procduction_year;
    speed_index_t speed_index;
    string manufacturer;
};


#endif //ADT_TIRE_H
