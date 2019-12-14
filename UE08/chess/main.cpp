#include <iostream>
#include "./chessman.h"
#include "./chessboard.h"
#include "./types.h"
#include "./io.h"

#define INTERACTIVE

using std::cout;
using std::endl;
using std::cin;

int main() {

    // for user interaction
    std::string user_coordinates;
    bool valid;

    /*----------------------------------------------------------------------------*/

    separator();

    chessboard cb;      // init board
    cb.start_game();    // init characters
    cb.player_config("Michael","Julian");
    cout << cb;

    /*----------------------------------------------------------------------------*/
    // game

#ifdef INTERACTIVE

    while (!cb.get_game_over()) {
        do {
            cout << "HELP: " << endl;
            cout << "coordinateinput: x <int> , [ y <int> , yc <char> ]" << endl;
            cout << "activate character of player: ";
            cb.get_current_player();
            cin >> user_coordinates;
            pos user_pos(user_coordinates);
            valid = cb.activate_character(user_pos);
        } while(!valid);
        cout << cb;



        do {
            cout << "coordinateinput: x <int> , [ y <int> , yc <char> ]" << endl;
            cout << "move activated character of player: ";
            cb.get_current_player();
            cout << " to position: " << endl;
            cin >> user_coordinates;
            pos user_pos_target(user_coordinates);
            valid = cb.move_character(user_pos_target);
        } while(!valid);
        cout << cb;
    }

    cout << "Winner: ";
    cb.get_current_player();

#else

   cb.simulate();
   cout << cb;
   cb.simulate();
   cout << cb;
   cb.simulate();
   cout << cb;
   cb.simulate();
   cout << cb;
   cb.simulate();
   cout << cb;
   cb.simulate();
   cout << cb;

#endif

}