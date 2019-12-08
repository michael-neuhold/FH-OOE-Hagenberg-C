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
    cb.activate_character({.x = 0, .y = 0});
    cb.player_config("Michael","Julian");
    cout << cb;

    separator();
    cb.character_at_position({.x = 1, .y = 1});

    separator();
    cb.get_chessboard_size();

    separator();
    cb.get_current_player();

    separator();
    cb.is_empty_field({.x = 1, .y = 1});
    cb.is_empty_field({.x = 5, .y = 5});

}