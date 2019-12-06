//
// Created by Michael Neuhold on 05.12.19.
//

#pragma once

#include <iostream>
#include "./chessman.h"

class chessboard {

    // print function overloading << operator
    friend std::ostream &operator<<(std::ostream &os, const chessboard &cb);

public:
    chessboard(const int size = 8);

    // set characters on board (start game)
    void start_game();

private:
    void init_black_characters();
    void init_white_characters();
    int m_chessboard_size;
    chessman ***m_chessboard{nullptr}; // is not used
};
