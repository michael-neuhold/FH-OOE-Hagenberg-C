//
// Created by Michael Neuhold on 28.11.19.
//

#include "tire.h"

tire::tire(const double rim_diameter,const int production_year,const string speed_index,const string manufacturer) {
    this -> rim_diameter = rim_diameter;
    this -> procduction_year = production_year;
    this -> speed_index = speed_index;
    this -> manufacturer = manufacturer;
}

std::ostream &operator<<(std::ostream &os,const tire &car_tire) {
    return os << "tire: {\n"
                 "\trim diameter: " << car_tire.rim_diameter <<
              "\n\tproduction year: " << car_tire.procduction_year <<
              "\n\tspeed index: " << car_tire.speed_index <<
              "\n\tmanufacturer: " << car_tire.manufacturer <<
              "\n\t}" << std::endl;
}

