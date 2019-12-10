#include <iostream>
#include "./chessman.h"
#include "./chessboard.h"
#include "./types.h"
#include "./io.h"


using std::cout;

int main() {

    print_header("my chess implementation");

    // create new chessboard (default size = 8x8)
    chessboard cb(8);
   // cout << cb;

    separator();

    // set initial game state
    cb.start_game();
    pos position1(2,1,'a');
    cb.activate_character(position1);
    cb.player_config("Michael","Julian");
    cout << cb;

    separator();
    pos position2(8,1,'a');
    cb.character_at_position(position2);

    separator();
    cb.get_chessboard_size();

    separator();
    cb.get_current_player();

    separator();
    pos position3(7,0,'b');
    pos position4(5,0,'c');
    cb.is_empty_field(position3);
    cb.is_empty_field(position4);


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