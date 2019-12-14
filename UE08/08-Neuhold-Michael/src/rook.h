//
// Created by Michael Neuhold on 07.12.19.
//

#pragma once


#include "chessman.h"

class rook : public chessman {
public:
    rook(color color);
    ~rook();

    color get_color() const;
    std::string get_figure() const;
    std::string get_name() const;
    bool is_essential() const;
    void calc_all_possible_moves(pos origin, check_board **cb, const int size);
    void set_first_move_done(bool moved);

private:
    color m_color;
    std::string m_figure;
    std::string m_name{"rook"};
    bool m_essential{false};
    bool m_first_move_done{false};
};



