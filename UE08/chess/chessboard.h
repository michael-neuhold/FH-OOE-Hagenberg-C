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
    chessboard(const int size = 8);
    ~chessboard();
    void player_config(std::string player_a, std::string player_b);
    void start_game();
    bool activate_character(pos position);
    void character_at_position(pos position);
    void get_chessboard_size();
    void get_current_player();
    void is_empty_field(pos position);
    bool move_character(pos target);
    bool get_game_over();
    void simulate();

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
