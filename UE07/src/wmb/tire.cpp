//
// Created by Michael Neuhold on 28.11.19.
//

#include "tire.h"

tire::tire(double rim_diameter, int production_year, speed_index_t speed_index, string manufacturer) {
    this -> rim_diameter = rim_diameter;
    this -> procduction_year = production_year;
    this -> speed_index = speed_index;
    this -> manufacturer = manufacturer;
}

std::ostream &operator<<(std::ostream &os,const tire &car_tire) {
    return os << "tire: {"
                 "rim diameter: " << car_tire.rim_diameter <<
              ", production year: " << car_tire.procduction_year <<
              ", speed index: " << car_tire.speed_index <<
              ", manufacturer: " << car_tire.manufacturer <<
              " }" << std::endl;
}
