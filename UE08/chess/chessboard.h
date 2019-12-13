//
// Created by Michael Neuhold on 05.12.19.
//

#pragma once

#include <iostream>
#include "./types.h"
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

    // activate character
    bool activate_character(pos position);

    // print character at position X
    void character_at_position(pos position);

    // get chessboard size
    void get_chessboard_size();

    // print current player
    void get_current_player();

    // chessboard field is empty
    void is_empty_field(pos position);

    // move character to position
    bool move_character(pos target);

    // returns game_over
    bool get_game_over();

private:
    void init_characters(int first_row, int second_row, color color);

    player m_players[2] = {
                            {"Player A", color::black},
                            {"Player B", color::white}
                          };

    player m_current_player{"Player A", color::black};
    int m_chessboard_size;
    chessman ***m_chessboard{nullptr};
    chessman *m_activated_character{nullptr};
    pos activated_position;
    check_board **m_check_board{nullptr};
    bool m_game_over{false};
};
