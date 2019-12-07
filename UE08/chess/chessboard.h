//
// Created by Michael Neuhold on 05.12.19.
//

#pragma once

#include <iostream>
#include "./chessman.h"
#include "./player.h"

class chessboard {

    // print function overloading << operator
    friend std::ostream &operator<<(std::ostream &os, const chessboard &cb);

public:

    // constructor with default chessboard size of 8 x 8
    chessboard(const int size = 8);

    // set player names
    void player_config(std::string player_a, std::string player_b);

    // set characters on board (start game)
    void start_game();

private:
    void init_black_characters();
    void init_white_characters();

    player m_players[2] = {
                            {"Player A", color::black},
                            {"Player B", color::white}
                          };

    int m_chessboard_size;
    chessman ***m_chessboard{nullptr};
};
