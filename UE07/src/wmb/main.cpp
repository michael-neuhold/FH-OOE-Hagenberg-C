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

    /*--------------------------------------------------------------------------------------------*/

    Header("tires:");
    // init new tries
        // double rim_diameter, int production_year, string speed_index, string manufacturer
    tire t1(25.3, 2009, F, "Pirelli");
    // output of tires
    cout << t1;

    /*--------------------------------------------------------------------------------------------*/

    Header("engines:");
    // init new engines
        // int engine_number, fuel_t fuel_type, int power, double n_consumption, date_t production_date);
    date_t production_date_engine{ .day = 3 , .month = 6 , .year = 2019 };
    engine e1(1,diesel, 140, 5.5, production_date_engine);
    // output of engines
    cout << e1;

    /*--------------------------------------------------------------------------------------------*/

    Header("car:");
    // init new cars
        // string type, color_t color, int serial_number, date_t production_date, string production_place, string gearbox, string type_of_drive, int top_speed, int weight, tire &tire, engine &engine );
    date_t production_date_car{ .day = 12 , .month = 11 , .year = 2018 };
    car c1("Audi A3",black,12345,production_date_car,"München",
            "Handschaltung","Quattro",200,1400,t1,e1);
    // output of cars
    cout << c1;

    /*--------------------------------------------------------------------------------------------*/

}