#include <iostream>
#include "./chessman.h"
#include "./chessboard.h"
#include "./types.h"
#include "./io.h"


using std::cout;

int main() {

    print_header("my chess implementation");

    // create new chessboard (default size = 8x8)
    chessboard cb;
    cout << cb;

    separator();

    // set initial game state
    cb.start_game();
    cout << cb;

    separator();

}