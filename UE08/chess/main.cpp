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
    chessboard cb(8);

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
    cout << "HELP: " << endl;
    cout << "coordinateinput: x <int> , [ y <int> , yc <char> ]" << endl;
    cout << "activate character of player: ";
    cb.get_current_player();
    cin >> user_coordinates;
    pos user_pos(user_coordinates);
    cb.activate_character(user_pos);
    cout << cb;
    /*-------*/
    cout << "coordinateinput: x <int> , [ y <int> , yc <char> ]" << endl;
    cout << "move activated character of player: ";
    cb.get_current_player();
    cout << " to position: " << endl;
    cin >> user_coordinates;
    pos user_pos_target(user_coordinates);
    cb.move_character(user_pos_target);
    cout << cb;

    /*
    separator();
    pos position2(8,1,'a');
    cb.character_at_position(position2);

    separator();
    cb.get_chessboard_size();

    separator();
    cb.get_current_player();

    separator();
    pos position3(7,1,'b');
    pos position4(5,1,'c');
    cb.is_empty_field(position3);
    cb.is_empty_field(position4);

    */
    // Testcases for index translation
    /*
    pos position1 = convert_to_internal_pos({2,1,'a'});
    std::cout << "from user position to internal: (2,a) x = " << position1.x << " y = " << position1.y << std::endl;

    user_pos userpos1 = convert_to_user_pos({2,0});
    std::cout << "from user position to internal: (2,0) x = " << userpos1.x << " y = " << userpos1.y << " yc = " << userpos1.yc << std::endl;

    pos position2 = convert_to_internal_pos({3,4,'a'});
    std::cout << "from user position to internal: (2,a) x = " << position2.x << " y = " << position2.y << std::endl;
    */
}