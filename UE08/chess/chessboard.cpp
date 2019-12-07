//
// Created by Michael Neuhold on 05.12.19.
//
#include <iostream>
#include "chessboard.h"
#include "king.h"
#include "types.h"

// reverse terminal colors
#define RESET   "\033[0m"
#define REVERSED "\u001b[7m"

// unicode characters
#define PIPE_SYMBOL "\u2503"
#define CROSS_SYMBOL "\u254B"
#define BAR_SYMBOL "\u2501"

// spacing
#define THREE_SPACING "   "
#define SINGLE_SPACE " "

// others
#define ALPHABET_LENGTH 26
#define SUB_LINE_LENGTH 3
#define SMALL_A 97

/*----------------------------------------------------------------------------*/

chessboard::chessboard(const int size) : m_chessboard_size{size}{
    m_chessboard = new chessman**[m_chessboard_size];
    for(int i = 0; i < m_chessboard_size; i++) {
        m_chessboard[i] = new chessman*[m_chessboard_size];
        for(int j = 0; j < m_chessboard_size; j++) {
            (m_chessboard[i])[j] = nullptr;
        }
    }
}

/*----------------------------------------------------------------------------*/

static bool is_black_field(int i, int j) {
   return (i + j) % 2 == 0;
}

std::ostream& operator<<(std::ostream& os, const chessboard& cb) {

    os << "players:" << std::endl;
    for(player player : cb.m_players) {
        os << "name: " << player.get_name() << ", color: " << (player.get_color() == color::black? "black" : "white" );
        os << std::endl;
    }


    // print top labeling
    os << THREE_SPACING;
    os << PIPE_SYMBOL;
    for(int i = 0; i < cb.m_chessboard_size; i++) {
        os << SINGLE_SPACE << char(SMALL_A + (i % ALPHABET_LENGTH)) << SINGLE_SPACE;
    }
    os << PIPE_SYMBOL;

    // print additional column index if i > 26
    if(cb.m_chessboard_size > ALPHABET_LENGTH) {
        os << std::endl << THREE_SPACING << PIPE_SYMBOL;
        for(int i = 0; i < cb.m_chessboard_size; i++) {
            os << "[" << i / ALPHABET_LENGTH + 1 << "]";
        }
        os << PIPE_SYMBOL;
    }

    os << std::endl;

    // print top line
    for(int i = 0; i < SUB_LINE_LENGTH; i++) os << BAR_SYMBOL;
    os << CROSS_SYMBOL;
    for(int i = 0; i < cb.m_chessboard_size * 3; i++) os << BAR_SYMBOL;
    os << CROSS_SYMBOL;
    for(int i = 0; i < SUB_LINE_LENGTH; i++) os << BAR_SYMBOL;
    os << std::endl;

    // print board
    for(int i = 0; i < cb.m_chessboard_size; i++) {
        os << (cb.m_chessboard_size - i < 10? SINGLE_SPACE : "" ) << cb.m_chessboard_size - i  << SINGLE_SPACE << PIPE_SYMBOL;
        for(int j = 0; j < cb.m_chessboard_size; j++) {
            os << (is_black_field(i,j) ? "" : REVERSED); // if white field -> invert terminal colors
            if(cb.m_chessboard[i][j] != nullptr) {
                // draw placed character
                os << SINGLE_SPACE << cb.m_chessboard[i][j] -> get_figure() << SINGLE_SPACE;
            } else {
                // draw empty sub square
                os << THREE_SPACING;
            }
            os << (is_black_field(i,j) ? "" : RESET);   // if white field -> return to original colors
        }
        os << PIPE_SYMBOL << SINGLE_SPACE << (cb.m_chessboard_size - i < 10? SINGLE_SPACE:"" ) << cb.m_chessboard_size - i;
        os << std::endl;
    }

    // print bottom line
    for(int i = 0; i < SUB_LINE_LENGTH; i++) os << BAR_SYMBOL;
    os << CROSS_SYMBOL;
    for(int i = 0; i < cb.m_chessboard_size * 3; i++) os << BAR_SYMBOL;
    os << CROSS_SYMBOL;
    for(int i = 0; i < SUB_LINE_LENGTH; i++) os << BAR_SYMBOL;
    os << std::endl;

    // print bottom labeling
    os << THREE_SPACING << PIPE_SYMBOL;
    for(int i = 0; i < cb.m_chessboard_size; i++) {
        os << SINGLE_SPACE << char(SMALL_A + (i % ALPHABET_LENGTH)) << SINGLE_SPACE;
    }
    os << PIPE_SYMBOL;
    if(cb.m_chessboard_size > ALPHABET_LENGTH) {
        os << std::endl << THREE_SPACING << PIPE_SYMBOL;
        for(int i = 0; i < cb.m_chessboard_size; i++) {
            os << "[" << i / ALPHABET_LENGTH + 1 << "]";
        }
        os << PIPE_SYMBOL;
    }

    return os;
}

/*----------------------------------------------------------------------------*/

void chessboard::init_black_characters() {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < m_chessboard_size; j++) {
            m_chessboard[i][j] =  new king(color::black);
            m_chessboard[i][j] -> set_is_valid(true);
        }
    }
}

/*----------------------------------------------------------------------------*/

void chessboard::init_white_characters() {
    for(int i = m_chessboard_size - 1; i > m_chessboard_size - 3; i--) {
        for(int j = 0; j < m_chessboard_size; j++) {
            m_chessboard[i][j] =  new king(color::white);
            m_chessboard[i][j] -> set_is_valid(true);
        }
    }
}

/*----------------------------------------------------------------------------*/

void chessboard::start_game() {
    // init gameboard characters
    init_black_characters();
    init_white_characters();
}

/*----------------------------------------------------------------------------*/

void chessboard::player_config(std::string player_a, std::string player_b) {
    player a(player_a, color::black);
    player b(player_b, color::white);
    m_players[0] = a;
    m_players[1] = b;
}

/*----------------------------------------------------------------------------*/