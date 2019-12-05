//
// Created by Michael Neuhold on 28.11.19.
//

#include "./main.h"
#include "./engine.h"

engine::engine(const int engine_number,const string fuel_type, int power, double n_consumption,const date_t production_date) {
    this -> engine_number = engine_number;
    this -> fuel_type = fuel_type;
    this -> power = power;
    this -> n_consumption = n_consumption;
    this -> production_date = production_date;
}

std::ostream &operator<<(std::ostream &os,const engine &car_engine) {
    return os << "engine: { \n"
                 "\tengine_number: " << car_engine.engine_number <<
                 "\n\tfuel_type: " << car_engine.fuel_type <<
                 "\n\tpower: " << car_engine.power <<
                 "\n\tn_consuption: " << car_engine.n_consumption <<
                 "\n\tproduction_date: "<< car_engine.production_date.day <<
                 "." << car_engine.production_date.month <<
                 "." << car_engine.production_date.year <<
                 "\n\t}" << std::endl;
}