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
    car(string type, color_t color, int serial_number, date_t production_date, string production_place, string gearbox, string type_of_drive, int top_speed, int weight, const tire &, const engine &);
    ~car() = default;
private:
    // Typ
    // Farbe
    // Seriennummer
    // Produktionsdatum
    // Produktionsort
    // Getriebeart
    // Antriebsart
    // Höchstgeschwindigkeit
    // Gewicht
    string type;
    color_t color;
    int serial_number;
    date_t production_date;
    string production_place;
    string gearbox;
    string type_of_drive;
    int top_speed;
    int weight;
    // tire
    tire car_tire;
    // engine
    engine car_engine;
};


#endif //ADT_CAR_H
