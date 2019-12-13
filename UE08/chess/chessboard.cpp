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
#include "io.h"

#include <cstdlib>

// reverse terminal colors
#define RESET   "\033[0m"
#define REVERSED "\u001b[7m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define RED "\033[0;31m"

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
#define EMPTY_FIELD nullptr

/*----------------------------------------------------------------------------*/

chessboard::chessboard(const int size) : m_chessboard_size{size}{
    m_chessboard = new chessman**[m_chessboard_size];
    m_check_board = new check_board*[m_chessboard_size]; // check board
    for(int i = 0; i < m_chessboard_size; i++) {
        m_chessboard[i] = new chessman*[m_chessboard_size];
        m_check_board[i] = new check_board[m_chessboard_size]; // check board
        for(int j = 0; j < m_chessboard_size; j++) {
            (m_chessboard[i])[j] = nullptr;
        }
    }
}

/*----------------------------------------------------------------------------*/

static bool is_black_field(int i, int j) {
   return (i + j) % 2 == 0;
}

/*----------------------------------------------------------------------------*/
// print chessboard to terminal
/*----------------------------------------------------------------------------*/

static std::ostream & print_players(std::ostream& out, const player players[]) {
    out << "players:" << std::endl;
    for(int i = 0; i < 2; i++) {
        out << "name: " << players[i].get_name() << ", color: " << (players[i].get_color() == color::black? "black" : "white" );
        out << std::endl;
    }
    separator();
    return out;
}

/*--------------------------*/

static std::ostream & print_current_player(std::ostream& out,const  player &player) {
    out  << "current player: " << player.get_name() << " ("
        << (player.get_color() == color::black ? "black" : "white") << ")" << std::endl;
    separator();
    return out;
}

/*--------------------------*/

static std::ostream & print_horizontal_numbers(std::ostream& out, int size) {
    out << std::endl << THREE_SPACING << PIPE_SYMBOL;
    for(int i = 0; i < size; i++) {
        out << "[" << i / ALPHABET_LENGTH + 1 << "]";
    }
    out << PIPE_SYMBOL << std::endl;
    return out;
}

/*--------------------------*/

static std::ostream & print_horizontal_chars(std::ostream& out, int size, bool end_line) {
    out << THREE_SPACING;
    out << PIPE_SYMBOL;
    for(int i = 0; i < size; i++) {
        out << SINGLE_SPACE << char(SMALL_A + (i % ALPHABET_LENGTH)) << SINGLE_SPACE;
    }
    out << PIPE_SYMBOL;
    if(end_line) out << std::endl;
    return out;
}

/*--------------------------*/

static std::ostream & print_vertical_numbers_left(std::ostream& out, int index) {
    out << (index + 1 < 10 ? " " : "" ) << index + 1 << SINGLE_SPACE << PIPE_SYMBOL;
    return out;
}

/*--------------------------*/

static std::ostream & print_vertical_numbers_right(std::ostream& out, int index) {
    out << PIPE_SYMBOL << SINGLE_SPACE << (index + 1 < 10 ? SINGLE_SPACE : "" ) << index + 1;
    return out;
}

/*--------------------------*/

static std::ostream & print_horizontal_line(std::ostream& out, int size) {
    for(int i = 0; i < SUB_LINE_LENGTH; i++) out << BAR_SYMBOL;
    out << CROSS_SYMBOL;
    for(int i = 0; i < size * 3; i++) out << BAR_SYMBOL;
    out << CROSS_SYMBOL;
    for(int i = 0; i < SUB_LINE_LENGTH; i++) out << BAR_SYMBOL;
    out << std::endl;
    return out;
}

/*--------------------------*/

static std::ostream & print_tmp_array(std::ostream& out, int check_board) {
    out << "test";
    return out;
}

/*--------------------------*/

std::ostream& operator<<(std::ostream& os, const chessboard& cb) {

    // clear screen
    //os << "\033[1;1H";
    system("clear");

    // print chess players
    print_players(os,cb.m_players);

    // print current player
    print_current_player(os,cb.m_current_player);

    // print top labeling
    print_horizontal_numbers(os,cb.m_chessboard_size);
    print_horizontal_chars(os,cb.m_chessboard_size, true);

    // print top line
    print_horizontal_line(os, cb.m_chessboard_size);

    // print board
    for(int i = cb.m_chessboard_size - 1 ; i >= 0; i--) {

        print_vertical_numbers_left(os,i);
        for(int j = 0; j < cb.m_chessboard_size; j++) {
            os << (is_black_field(i,j) ? "" : REVERSED); // if white field -> invert terminal colors
            if(cb.m_chessboard[i][j] != EMPTY_FIELD) {
                // set color to green if current character is activated
                if(cb.m_check_board[i][j].killable) {
                    os << RED;
                }

                if(cb.m_activated_character != nullptr) {
                    os << (cb.m_chessboard[i][j] == cb.m_activated_character ? BOLDGREEN : ""); //
                }
                os << SINGLE_SPACE << cb.m_chessboard[i][j] -> get_figure() << SINGLE_SPACE;
            } else {
               if(cb.m_activated_character != nullptr && cb.m_check_board[i][j].moveable) {
                    os << BOLDYELLOW;
                    os << " * ";
                } else {
                    os << THREE_SPACING;
                }
            }
            os << RESET;   // if white field -> return to original colors
        }
        print_vertical_numbers_right(os,i);
        os << std::endl;
    }

    // print bottom line
    print_horizontal_line(os, cb.m_chessboard_size);

    // print bottom labeling
    print_horizontal_chars(os,cb.m_chessboard_size,false);
    print_horizontal_numbers(os,cb.m_chessboard_size);

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

    /*
    // second row
    for(int j = 0; j < m_chessboard_size; j++) {
        m_chessboard[second_row][j] =  new pawn(color);
    }
     */

    /**
     *
     * Testing:
     *
     */


    if(color == color::black){
        //m_chessboard[5][2] = new queen(color::white);
        m_chessboard[3][4] = new pawn(color::white);
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
        m_activated_character = m_chessboard[position.x][position.y];
        activated_position.x = position.x;
        activated_position.y = position.y;

        // update check board with current values
        for(int i = 0; i < m_chessboard_size; i++) {
            for(int j = 0; j < m_chessboard_size; j++) {
                if(m_chessboard[i][j] != nullptr) {
                    m_check_board[i][j].character_name = m_chessboard[i][j] -> get_name();
                    m_check_board[i][j].color = m_chessboard[i][j] -> get_color();
                    m_check_board[i][j].is_set = true;
                }  else {
                    m_check_board[i][j].is_set = false;
                    m_check_board[i][j].moveable = false;
                    m_check_board[i][j].killable = false;
                }
            }
        }

        // check all valid moves
        m_activated_character -> calc_all_possible_moves(position, m_check_board, m_chessboard_size);

        // fill arrays with positions t

    } else {
        std::cout << "thats not your character";
    }
}

/*----------------------------------------------------------------------------*/

void chessboard::character_at_position(pos position) {
    std::cout << "x = " << position.x << " y = " << position.y << std::endl;
    if(m_chessboard[position.x][position.y] != nullptr) {
        std::cout << m_chessboard[position.x][position.y] -> get_figure() << " -> ";
        std::cout << "(" << (m_chessboard[position.x][position.y] -> get_color() == color::black ? "black " : "white ")
                  << m_chessboard[position.x][position.y] -> get_name() << ")" << std::endl;
    } else {
        std::cout << "field is empty" << std::endl;
    }
}

/*----------------------------------------------------------------------------*/

void chessboard::get_chessboard_size() {
    std::cout << "chessboard size: " << m_chessboard_size << std::endl;
}

/*----------------------------------------------------------------------------*/

void chessboard::get_current_player() {
    std::cout   << m_current_player.get_name()
                << " (" << (m_current_player.get_color() == color::black ? "black" : "white") << ")" << std::endl;
}

/*----------------------------------------------------------------------------*/

void chessboard::is_empty_field(pos position) {
    std::cout << "is empty: " << (m_chessboard[position.x][position.y] == nullptr ? "TRUE" : "FALSE") << std::endl;
}

/*----------------------------------------------------------------------------*/

static void reset_check_board(check_board **cb, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cb[i][j].killable = false;
            cb[i][j].moveable = false;
            cb[i][j].is_set = false;
        }
    }
}

void chessboard::move_character(pos target) {
    if(m_check_board[target.x][target.y].is_set && m_check_board[target.x][target.x].killable) {
        delete m_chessboard[target.x][target.y];
        m_chessboard[target.x][target.y] = m_activated_character;
        m_activated_character = nullptr;
        reset_check_board(m_check_board, m_chessboard_size);
    } else if (!m_check_board[target.x][target.y].is_set && m_check_board[target.x][target.y].moveable){
        m_chessboard[target.x][target.y] = m_activated_character;
        m_chessboard[activated_position.x][activated_position.y] = nullptr;
        m_activated_character = nullptr;
    } else {
        std::cout << "no valid position!";
    }
}