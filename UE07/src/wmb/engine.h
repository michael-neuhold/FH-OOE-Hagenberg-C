//
// Created by Michael Neuhold on 28.11.19.
//

#ifndef ADT_ENGINE_H
#define ADT_ENGINE_H

#include <iostream>
#include "./main.h"

class engine {
    friend std::ostream &operator<<(std::ostream &,const engine &);
public:
    engine(const int engine_number,const string fuel_type, int power, double n_consumption,const date_t production_date);
    ~engine() = default;
private:
    // Motornummer
    // Treibstoffart
    // Leistung
    // Normverbrauch
    // Produktionsdatum
    int engine_number;
    int power;
    double n_consumption;
    string fuel_type;
    date_t production_date;
};



#endif //ADT_ENGINE_H
