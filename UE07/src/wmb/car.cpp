//
// Created by Michael Neuhold on 28.11.19.
//

#include <iostream>
#include "car.h"
#include "./main.h"
#include "./tire.h"

using namespace std;

car::car(const string type, string color,const int serial_number,
        const date_t production_date,const string production_place,
        const string gearbox,const string type_of_drive, int top_speed,
        int weight, tire &car_tire, engine &car_engine) : car_tire(car_tire), car_engine(car_engine) {
    this -> type = type;
    this -> color = color;
    this -> serial_number = serial_number;
    this -> production_date = production_date;
    this -> production_place = production_place;
    this -> gearbox = gearbox;
    this -> type_of_drive = type_of_drive;
    this -> top_speed = top_speed;
    this -> weight = weight;
    this -> car_tire = car_tire;
    this -> car_engine = car_engine;
}

std::ostream &operator<<(std::ostream &os,const car &finished_car) {
    return os << "car: {\n"
                 "\ttype: " << finished_car.type <<
                 "\n\tcolor: " << finished_car.color <<
                 "\n\tserial number: " << finished_car.serial_number <<
                 "\n\tproduction_date: " << finished_car.production_date.day <<
                 "." << finished_car.production_date.month <<
                 "." << finished_car.production_date.year <<
                 "\n\tproduction_place: " << finished_car.production_place <<
                 "\n\tgearbox: " << finished_car.gearbox <<
                 "\n\ttype_of_drive: " << finished_car.type_of_drive <<
                 "\n\ttop_speed: " << finished_car.top_speed <<
                 "\n\tweight: " << finished_car.weight <<
                 "\n\t" << finished_car.car_tire <<
                 "\t" << finished_car.car_engine <<
                 " }" << std::endl;
}
