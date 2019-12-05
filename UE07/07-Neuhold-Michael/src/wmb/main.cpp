#include <iostream>
#include "./main.h"
#include "./tire.h"
#include "./engine.h"
#include "./car.h"

using namespace std;

void Separator() {
    for(int i = 0; i < 50; i++ ) {
        cout << "-";
    }
    cout << endl;
}
void Header(const string &header_text) {
    Separator();
    cout << header_text << endl;
    Separator();
}

int main() {

    Header("tires:");

    /*------------------------------------*/
    // input values
    double tire_rim_diameter;
    int tire_production_year;
    string tire_speed_index;
    string tire_manufacturer;
    /*------------------------------------*/
    cout << "tire_rim_diameter: ";
    cin >> tire_rim_diameter;
    cout << "tire_production_year: ";
    cin >> tire_production_year;
    cout << "tire_speed_index: ";
    cin >> tire_speed_index;
    cout << "tire_manufacturer: ";
    cin >> tire_manufacturer;
    /*------------------------------------*/

    // init new tries
        // double rim_diameter, int production_year, string speed_index, string manufacturer
    tire t1(tire_rim_diameter, tire_production_year, tire_speed_index, tire_manufacturer);
    // output of tires
    cout << t1;

    /*--------------------------------------------------------------------------------------------*/

    Header("engines:");

    /*------------------------------------*/
    // input values
    int engine_number;
    string engine_fuel_type;
    int engine_power;
    double engine_n_consumption;
    int engine_production_day;
    int engine_production_month;
    int engine_production_year;
    /*------------------------------------*/
    cout << "engine_number: ";
    cin >> engine_number;
    cout << "engine_fuel_type: ";
    cin >> engine_fuel_type;
    cout << "engine_power: ";
    cin >> engine_power;
    cout << "engine_n_consumption: ";
    cin >> engine_n_consumption;
    cout << "engine_production_day: ";
    cin >> engine_production_day;
    cout << "engine_production_month: ";
    cin >> engine_production_month;
    cout << "engine_production_year: ";
    cin >> engine_production_year;
    /*------------------------------------*/
    // init new engines
        // int engine_number, string fuel_type, int power, double n_consumption, date_t production_date);
    date_t production_date_engine{ .day = engine_production_day , .month = engine_production_month , .year = engine_production_year };
    engine e1(engine_number,engine_fuel_type, engine_power, engine_n_consumption, production_date_engine);
    // output of engines
    cout << e1;

    /*--------------------------------------------------------------------------------------------*/

    Header("car:");

    /*------------------------------------*/
    // input values
    string car_type;
    string car_color;
    int car_serial_number;
    string car_production_place;
    string car_gearbox;
    string car_type_of_drive;
    int car_top_speed;
    int car_weight;
    int car_production_day;
    int car_production_month;
    int car_production_year;
    /*------------------------------------*/
    cout << "car_type: ";
    cin >> car_type;
    cout << "car_color: ";
    cin >> car_color;
    cout << "car_serial_number: ";
    cin >> car_serial_number;
    cout << "car_production_place: ";
    cin >> car_production_place;
    cout << "car_gearbox: ";
    cin >> car_gearbox;
    cout << "car_type_of_drive: ";
    cin >> car_type_of_drive;
    cout << "car_top_speed: ";
    cin >> car_top_speed;
    cout << "car_weight: ";
    cin >> car_weight;
    cout << "car_production_day: ";
    cin >> car_production_day;
    cout << "car_production_month: ";
    cin >> car_production_month;
    cout << "car_production_year: ";
    cin >> car_production_year;
    /*------------------------------------*/
    // init new cars
        // string type, string color, int serial_number, date_t production_date, string production_place, string gearbox, string type_of_drive, int top_speed, int weight, tire &tire, engine &engine );
    date_t production_date_car{ .day = car_production_day , .month = car_production_month , .year = car_production_year };
    car c1(car_type,car_color,car_serial_number,production_date_car,car_production_place,
            car_gearbox,car_type_of_drive,car_top_speed,car_weight,t1,e1);
    // output of cars
    cout << c1;

    /*--------------------------------------------------------------------------------------------*/

}