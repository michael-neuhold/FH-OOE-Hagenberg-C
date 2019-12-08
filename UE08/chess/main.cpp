#include <iostream>
#include "./chessman.h"
#include "./chessboard.h"
#include "./types.h"
#include "./io.h"

/**
 *
 * TODO:
 *  - alle verschiedenen character anlegen und am Spielfeld platzieren
 *  - einfache die board funktionen von der Angabe einbauen
 *
 *
 */


using std::cout;

int main() {

    print_header("my chess implementation");

    // create new chessboard (default size = 8x8)
    chessboard cb;
    cout << cb;

    separator();

    // set initial game state
    cb.start_game();
    cb.activate_character({ .x = 1 , .y = 1 , .yc = 'a' });
    cb.player_config("Michael","Julian");
    cout << cb;

    separator();
    cb.character_at_position({ .x = 8 , .y = 1 , .yc = 'a' });

    separator();
    cb.get_chessboard_size();

    separator();
    cb.get_current_player();

    separator();
    cb.is_empty_field({.x = 7, .y = 0, .yc = 'b'});
    cb.is_empty_field({.x = 5, .y = 0, .yc = 'c'});


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