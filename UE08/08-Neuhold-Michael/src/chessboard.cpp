//
// Created by Michael Neuhold on 05.12.19.
//
#include <iostream>
#include <cstdlib>
#include "chessboard.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"
#include "characters.h"
#include "io.h"

// reverse terminal colors
#define RESET   "\033[0m"
#define REVERSED "\u001b[7m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define RED "\033[0;31m"

// spacing
#define THREE_SPACING "   "
#define SINGLE_SPACE " "

// others
#define ALPHABET_LENGTH 26
#define SUB_LINE_LENGTH 3
#define SMALL_A 97
#define EMPTY_FIELD nullptr
//#define SIMULATION

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

chessboard::~chessboard() {
    for(int i = 0; i < m_chessboard_size; i++) {
        for(int j = 0; j < m_chessboard_size; j++) {
            delete m_chessboard[i][j];
        }
    }
    for(int i = 0; i < m_chessboard_size; i++) {
        delete m_chessboard[i];
        delete m_check_board[i];
    }
    delete [] m_chessboard;
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
                if(cb.m_check_board[i][j].killable) {
                    os << RED;
                }
                if(cb.m_activated_character != nullptr) {
                    os << (cb.m_chessboard[i][j] == cb.m_activated_character ? BOLDGREEN : "");
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
            os << RESET; // reset colors
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

    // traditional characters
    m_chessboard[first_row][0 + calculate_offset(m_chessboard_size)] = new rook(color);
    m_chessboard[first_row][1 + calculate_offset(m_chessboard_size)] = new knight(color);
    m_chessboard[first_row][2 + calculate_offset(m_chessboard_size)] = new bishop(color);
    m_chessboard[first_row][3 + calculate_offset(m_chessboard_size)] = new queen(color);
    m_chessboard[first_row][4 + calculate_offset(m_chessboard_size)] = new king(color);
    m_chessboard[first_row][5 + calculate_offset(m_chessboard_size)] = new bishop(color);
    m_chessboard[first_row][6 + calculate_offset(m_chessboard_size)] = new knight(color);
    m_chessboard[first_row][7 + calculate_offset(m_chessboard_size)] = new rook(color);


#ifndef SIMULATION
    // second row
    for(int j = 0; j < m_chessboard_size; j++) {
        m_chessboard[second_row][j] =  new pawn(color);
    }
#endif

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

bool chessboard::activate_character(pos position) {
    // check if own character stands on this position
    if(m_chessboard[position.x][position.y] == nullptr) {
        std::cout << "Empty Field" << std::endl;
        return false;
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
                }
            }
        }

        // check all valid moves
        m_activated_character -> calc_all_possible_moves(position, m_check_board, m_chessboard_size);

    } else {
        std::cout << "thats not your character";
        return false;
    }
    return true;
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

bool chessboard::move_character(pos target) {

    if(m_check_board[target.x][target.y].is_set && m_check_board[target.x][target.y].killable) {
        if(m_chessboard[target.x][target.y] -> get_name() == "king") {
            m_game_over = true;
            return true;
        }
        delete m_chessboard[target.x][target.y];
        m_chessboard[target.x][target.y] = m_activated_character;
        m_chessboard[activated_position.x][activated_position.y] = nullptr;
        m_activated_character = nullptr;
    } else if (m_check_board[target.x][target.y].moveable){
        m_chessboard[target.x][target.y] = m_activated_character;
        m_chessboard[activated_position.x][activated_position.y] = nullptr;
        m_activated_character -> set_first_move_done(true);
        m_activated_character = nullptr;
    } else {
        std::cout << "target pos.x = " << target.x << " pos.y = " << target.y << std::endl;
        std::cout << "no valid position!";
        return false;
    }
    // reset tmp check board for next activated character
    reset_check_board(m_check_board, m_chessboard_size);
    // toggle current user
    m_current_player = (m_current_player.get_color() == m_players[0].get_color() ? m_players[1] : m_players[0]);
    return true;
}

/*----------------------------------------------------------------------------*/

bool chessboard::get_game_over() {
    return m_game_over;
}

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
// not the best implementation for simulation ;)

void chessboard::simulate() {

    pos *current_color_characters = new pos[m_chessboard_size];
    int current_color_characters_count = 0;

    // store characters of current players
    for(int i = 0; i < m_chessboard_size; i++) {
        for(int j = 0; j < m_chessboard_size; j++) {
            if(m_chessboard[i][j] != nullptr && m_chessboard[i][j]->get_color() == m_current_player.get_color()) {
                pos current_pos(i,j);
                current_color_characters[current_color_characters_count] = current_pos;
                current_color_characters_count++;
            }
        }
    }

    // check for a random character all possible moves
        // if no move is possible -> take the next random character
    int current_moves_count;
    do {
        int random_index = std::rand() % (current_color_characters_count-1);
        activate_character(current_color_characters[random_index]);
        current_moves_count = 0;

        for (int j = 0; j < m_chessboard_size; j++) {
            for (int k = 0; k < m_chessboard_size; k++) {
                if (m_check_board[j][k].moveable || m_check_board[j][k].killable) {
                    current_moves_count++;
                }
            }
        }
    } while(current_moves_count > 0);

    // store all possible positions
    pos *current_moves = new pos[m_chessboard_size];
    int current_moves_c = 0;
    for (int j = 0; j < m_chessboard_size; j++) {
        for (int k = 0; k < m_chessboard_size; k++) {
            if (m_check_board[j][k].moveable || m_check_board[j][k].killable) {
                pos current_move_target(j,k);
                current_moves[current_moves_c] = current_move_target;
                current_moves_c++;
            }
        }
    }

    // select random move
    int random_index = std::rand() % (current_moves_c - 1);
    move_character(current_moves[random_index]);

    delete [] current_moves;
    delete [] current_color_characters;
}
