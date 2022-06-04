#pragma once

#include <stdio.h>

//   05  06  07  08
// 09  10  11  12
//   14  15  16  17
// 18  19  20  21
//   23  24  25  26
// 27  28  29  30
//   32  33  34  35
// 36  37  38  39

#define WHITE_PAWN 1
#define WHITE_KING 2
#define BLACK_PAWN -1
#define BLACK_KING -2
#define EMPTY 0
#define INVALID 3

int black_initial_idxs[] = {5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 17};
int white_initial_idxs[] = {27, 28, 29, 30, 32, 33, 34, 35, 36, 37, 38, 39};
int empty_initial_idxs[] = {18, 19, 20, 21, 23, 24, 25, 26};

int board[44];


void initialize_board() {
    for (int i = 0; i < 44; i++) {
        board[i] = INVALID;
    }
    for (int i = 0; i < 12; i++) {
        board[white_initial_idxs[i]] = WHITE_PAWN;
        board[black_initial_idxs[i]] = BLACK_PAWN;
    }
    for (int i = 0; i < 8; i++) {
        board[empty_initial_idxs[i]] = EMPTY;
    }
}

void print_board() {
    printf("  %2d  %2d  %2d  %2d\n", board[5], board[6], board[7], board[8]);
    printf("%2d  %2d  %2d  %2d\n", board[9], board[10], board[11], board[12]);
    printf("  %2d  %2d  %2d  %2d\n", board[14], board[15], board[16], board[17]);
    printf("%2d  %2d  %2d  %2d\n", board[18], board[19], board[20], board[21]);
    printf("  %2d  %2d  %2d  %2d\n", board[23], board[24], board[25], board[26]);
    printf("%2d  %2d  %2d  %2d\n", board[27], board[28], board[29], board[30]);
    printf("  %2d  %2d  %2d  %2d\n", board[32], board[33], board[34], board[35]);
    printf("%2d  %2d  %2d  %2d\n", board[36], board[37], board[38], board[39]);
    fflush(stdout);
}

