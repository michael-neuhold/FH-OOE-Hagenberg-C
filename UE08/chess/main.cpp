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
    cb.player_config("Michael","Julian");
    cout << cb;


    separator();

}