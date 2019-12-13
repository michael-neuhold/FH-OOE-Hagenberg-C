#include <iostream>
#include "./chessman.h"
#include "./chessboard.h"
#include "./types.h"
#include "./io.h"


using std::cout;
using std::endl;
using std::cin;

int main() {

    /*----------------------------------------------------------------------------*/

    // INIT create new chessboard (default size = 8x8)
    chessboard cb;

    /*----------------------------------------------------------------------------*/

    separator();

    // set initial game state
    cb.start_game();

    // pos position1(2,1,'a');
    // constructor of pos struct parses string to get coordinates
    //pos position1("4,[1,e]");
    //cb.activate_character(position1);
    //cb.player_config("Michael","Julian");
    cout << cb;

    /*----------------------------------------------------------------------------*/
    // game

    std::string user_coordinates;
    bool valid;
    //pos user_pos("5,[1,d]");
    //cb.activate_character(user_pos);
    //cout << cb;

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

}