//
// Created by Michael Neuhold on 28.11.19.
//

#include <iostream>
#include "car.h"
#include "./main.h"
#include "./tire.h"

using namespace std;

car::car(string type, color_t color, int serial_number,
        date_t production_date, string production_place,
        string gearbox, string type_of_drive, int top_speed,
        int weight, const tire &car_tire, const engine &car_engine) : car_tire(car_tire), car_engine(car_engine) {
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
    return os << "car: {"
                 "type: " << finished_car.type <<
                 ", color: " << finished_car.color <<
                 ", serial number: " << finished_car.serial_number <<
                 ", production_date: " << finished_car.production_date.day <<
                 "." << finished_car.production_date.month <<
                 "." << finished_car.production_date.year <<
                 ", production_place: " << finished_car.production_place <<
                 ", gearbox: " << finished_car.gearbox <<
                 ", type_of_drive: " << finished_car.type_of_drive <<
                 ", top_speed: " << finished_car.top_speed <<
                 ", weight: " << finished_car.weight <<
                 ", car_tire: " << finished_car.car_tire <<
                 ", car_engine: " << finished_car.car_engine <<
                 " }" << std::endl;
}