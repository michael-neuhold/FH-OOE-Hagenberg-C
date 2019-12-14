//
// Created by Michael Neuhold on 14.12.19.
//

#pragma once

// activate this define to play my chess implementation on windows
//#define WINDOWS

#ifndef WINDOWS

// unicode bishop
#define WHITE_BISHOP "\u2657"
#define BLACK_BISHOP "\u265D"

// unicode rook
#define WHITE_BISHOP "\u2656"
#define BLACK_BISHOP "\u265C"

// unicode kings
#define WHITE_KING "\u2654"
#define BLACK_KING "\u265A"

// unicode queen
#define WHITE_QUEEN "\u2655"
#define BLACK_QUEEN "\u265B"

// unicode knight
#define WHITE_BISHOP "\u2658"
#define BLACK_BISHOP "\u265E"

// unicode pawn
#define WHITE_PAWN "\u2659"
#define BLACK_PAWN "\u265F"

// unicode characters
#define PIPE_SYMBOL "\u2503"
#define CROSS_SYMBOL "\u254B"
#define BAR_SYMBOL "\u2501"

#else

// char bishop
#define WHITE_BISHOP "b"
#define BLACK_BISHOP "B"

// char rook
#define WHITE_BISHOP "r"
#define BLACK_BISHOP "R"

// char kings
#define WHITE_KING "k"
#define BLACK_KING "K"

// char queen
#define WHITE_QUEEN "q"
#define BLACK_QUEEN "Q"

// char knight
#define WHITE_BISHOP "k"
#define BLACK_BISHOP "K"

// char pawn
#define WHITE_PAWN "p"
#define BLACK_PAWN "P"

// char characters
#define PIPE_SYMBOL "|"
#define CROSS_SYMBOL "+"
#define BAR_SYMBOL "-"

#endif

