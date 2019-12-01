//
// Created by Michael Neuhold on 28.11.19.
//

#ifndef ADT_CAR_H
#define ADT_CAR_H

#include <iostream>
#include "./main.h"
#include "./tire.h"
#include "./engine.h"

using namespace std;

class car {
    friend std::ostream &operator<<(std::ostream &os,const car &finished_car);
public:
    car(const string type, string color,const int serial_number,const date_t production_date,const string production_place,const string gearbox,const string type_of_drive,int top_speed, int weight, tire &, engine &);
    ~car() = default;
private:
    string type;
    string color;
    int serial_number;
    date_t production_date;
    string production_place;
    string gearbox;
    string type_of_drive;
    int top_speed;
    int weight;
    tire car_tire;
    engine car_engine;
};

#endif //ADT_CAR_H
