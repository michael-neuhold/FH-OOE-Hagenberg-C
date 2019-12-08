//
// Created by Michael Neuhold on 05.12.19.
//
#include <iostream>
#include "chessboard.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"
#include "types.h"

// reverse terminal colors
#define RESET   "\033[0m"
#define REVERSED "\u001b[7m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"

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

static bool check_activation(int i,int j, pos *possible_moves) {
    for(int k = 0; k < 2; k++) {
        if(i == possible_moves[k].x && j == possible_moves[k].y) {
            return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const chessboard& cb) {

    os << "players:" << std::endl;
    for(player player : cb.m_players) {
        os << "name: " << player.get_name() << ", color: " << (player.get_color() == color::black? "black" : "white" );
        os << std::endl;
    }

    os  << "current player: " << cb.m_current_player.get_name() << " ("
        << (cb.m_current_player.get_color() == color::black ? "black" : "white") << ")" << std::endl;

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
    for(int i = cb.m_chessboard_size - 1 ; i >= 0; i--) {
        os << (cb.m_chessboard_size - i < 10 ? SINGLE_SPACE : "" ) << i + 1  << SINGLE_SPACE << PIPE_SYMBOL;
        for(int j = 0; j < cb.m_chessboard_size; j++) {
            os << (is_black_field(i,j) ? "" : REVERSED); // if white field -> invert terminal colors
            if(cb.m_chessboard[i][j] != nullptr) {
                // set color to green if current character is activated
                if(cb.m_activated_character != nullptr) {
                    os << (cb.m_chessboard[i][j] == cb.m_activated_character ? BOLDGREEN : ""); //
                }
                // draw placed character
                os << SINGLE_SPACE << cb.m_chessboard[i][j] -> get_figure() << SINGLE_SPACE;
            } else {
                // draw empty sub square
                os << THREE_SPACING;
            }
            os << RESET;   // if white field -> return to original colors
        }
        os << PIPE_SYMBOL << SINGLE_SPACE << (cb.m_chessboard_size - i < 10? SINGLE_SPACE:"" ) << i + 1;
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

static int calculate_offset(int size) {
    return (size - 8) / 2;
}

void chessboard::init_characters(int first_row, int second_row, color color) {

    // first row
    if(m_chessboard_size > 8) {
        for(int i = 0; i < calculate_offset(m_chessboard_size); i++ ){
            m_chessboard[first_row][i] =  new pawn(color);
        }
        for(int i = calculate_offset(m_chessboard_size) + 8; i < m_chessboard_size; i++ ){
            m_chessboard[first_row][i] =  new pawn(color);
        }
    }

    m_chessboard[first_row][0 + calculate_offset(m_chessboard_size)] = new rook(color);
    m_chessboard[first_row][1 + calculate_offset(m_chessboard_size)] = new knight(color);
    m_chessboard[first_row][2 + calculate_offset(m_chessboard_size)] = new bishop(color);
    m_chessboard[first_row][3 + calculate_offset(m_chessboard_size)] = new queen(color);
    m_chessboard[first_row][4 + calculate_offset(m_chessboard_size)] = new king(color);
    m_chessboard[first_row][5 + calculate_offset(m_chessboard_size)] = new bishop(color);
    m_chessboard[first_row][6 + calculate_offset(m_chessboard_size)] = new knight(color);
    m_chessboard[first_row][7 + calculate_offset(m_chessboard_size)] = new rook(color);

    // second row
    for(int j = 0; j < m_chessboard_size; j++) {
        m_chessboard[second_row][j] =  new pawn(color);
    }
}

/*----------------------------------------------------------------------------*/

void chessboard::start_game() {
    // init gameboard characters
    init_characters(0,1,color::black);
    init_characters(m_chessboard_size-1,m_chessboard_size-2,color::white);
}

/*----------------------------------------------------------------------------*/

void chessboard::player_config(std::string player_a, std::string player_b) {
    player a(player_a, color::black);
    player b(player_b, color::white);
    m_players[0] = a;
    m_players[1] = b;
    m_current_player = m_players[0];
}

/*----------------------------------------------------------------------------*/

void chessboard::activate_character(pos position) {
    // check if own character stands on this position
    if(m_chessboard[position.x][position.y] == nullptr) {
        std::cout << "Empty Field" << std::endl;
        return;
    }

    if(m_current_player.get_color() == m_chessboard[position.x][position.y] -> get_color()) {
        // activate character
        m_activated_character = m_chessboard[position.x][position.y];
        // calculate possible moves

    } else {
        std::cout << "thats not your character";
    }
}

/*----------------------------------------------------------------------------*/

void chessboard::character_at_position(pos position) {
    std::cout << "position[" << position.x << "][" << position.y << "]: ";
    if(m_chessboard[position.x][position.y] != nullptr) {
        std::cout << m_chessboard[position.x][position.y] -> get_figure() << " -> ";
        std::cout << "(" << (m_chessboard[position.x][position.y] -> get_color() == color::black ? "black " : "white ")
                  << m_chessboard[position.x][position.y] -> get_name() << ")" << std::endl;
    } else {
        std::cout << "field is empty" << std::endl;
    }
}

void chessboard::get_chessboard_size() {
    std::cout << "chessboard size: " << m_chessboard_size << std::endl;
}

void chessboard::get_current_player() {
    std::cout   << "current player: "
                << m_current_player.get_name()
                << " (" << (m_current_player.get_color() == color::black ? "black" : "white") << ")" << std::endl;
}

void chessboard::is_empty_field(pos position) {
    std::cout << "is empty: " << (m_chessboard[position.x][position.y] == nullptr ? "TRUE" : "FALSE") << std::endl;
}