#include "board.h"
#include <stdio.h>

//   05  06  07  08
// 09  10  11  12
//   14  15  16  17
// 18  19  20  21
//   23  24  25  26
// 27  28  29  30
//   32  33  34  35
// 36  37  38  39

#define BOARD_SIZE 44

int black_initial_idxs[] = {5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 17};
int white_initial_idxs[] = {27, 28, 29, 30, 32, 33, 34, 35, 36, 37, 38, 39};
int empty_initial_idxs[] = {18, 19, 20, 21, 23, 24, 25, 26};

static int board[BOARD_SIZE];

void board_initialize() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = INVALID;
    }
    for (int i = 0; i < 12; i++) {
        board[white_initial_idxs[i]] = WHITE_PAWN;
        board[black_initial_idxs[i]] = BLACK_PAWN;
    }
    for (int i = 0; i < 8; i++) {
        board[empty_initial_idxs[i]] = EMPTY;
    }
    board[17] = EMPTY;
    board[19] = WHITE_PAWN;
    board[21] = BLACK_PAWN;
    board[29] = BLACK_PAWN;
}

int board_get_score(int color) {
    int score = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] == color) {
            score += board[i];
        }
        if (board[i] == color * WHITE_KING) {
            score += board[i];
        }
    }
    return score;
}

int can_jump(int idx, int color, int dir) {
    return board[idx + dir] == -color && board[idx + 2 * dir] == EMPTY;
}

int get_jumps(int color, move_t *legal_moves) {
    int dir;
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] != color) {
            continue;
        }
        switch (board[i]) {
            case WHITE_PAWN: {
                                 while (can_jump(i, color, -5, legal_moves, &count) ||
                                        can_jump(i, color, -4, legal_moves, &count)) {
                                 }
                                 //                if (board[i - 5] == -color && board[i - 10] == EMPTY) {
                                 //                    move_t move;
                                 //                    move.idxs[0] = i;
                                 //                    move.idxs[1] = i - 5;
                                 //                    move.idxs[2] = i - 10;
                                 //                    move.len = 3;
                                 //                    legal_moves[count++] = move;
                                 //                }
                                 //                if (board[i - 4] == -color && board[i - 8] == EMPTY) {
                                 //                    move_t move;
                                 //                    move.idxs[0] = i;
                                 //                    move.idxs[1] = i - 4;
                                 //                    move.idxs[2] = i - 8;
                                 //                    move.len = 3;
                                 //                    legal_moves[count++] = move;
                                 //                }
                                 break;
                             }
            case BLACK_PAWN:
                             if (board[i + 5] == -color && board[i + 10] == EMPTY) {
                                 move_t move;
                                 move.idxs[0] = i;
                                 move.idxs[1] = i + 5;
                                 move.idxs[2] = i + 10;
                                 move.len = 3;
                                 legal_moves[count++] = move;
                             }
                             if (board[i + 4] == -color && board[i + 8] == EMPTY) {
                                 move_t move;
                                 move.idxs[0] = i;
                                 move.idxs[1] = i + 4;
                                 move.idxs[2] = i + 8;
                                 move.len = 3;
                                 legal_moves[count++] = move;
                             }
                             break;
        }
    }
    return count;
}

int get_moves(int color, move_t *legal_moves) {
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] != color) {
            continue;
        }
        switch (board[i]) {
            case WHITE_PAWN:
                if (board[i - 5] == EMPTY) {
                    move_t move;
                    move.idxs[0] = i;
                    move.idxs[1] = i - 5;
                    move.len = 2;
                    legal_moves[count++] = move;
                }
                if (board[i - 4] == EMPTY) {
                    move_t move;
                    move.idxs[0] = i;
                    move.idxs[1] = i - 4;
                    move.len = 2;
                    legal_moves[count++] = move;
                }
                break;
            case BLACK_PAWN:
                if (board[i + 4] == EMPTY) {
                    move_t move;
                    move.idxs[0] = i;
                    move.idxs[1] = i + 4;
                    move.len = 2;
                    legal_moves[count++] = move;
                }
                if (board[i + 5] == EMPTY) {
                    move_t move;
                    move.idxs[0] = i;
                    move.idxs[1] = i + 5;
                    move.len = 2;
                    legal_moves[count++] = move;
                }
                break;
        }
    }
    return count;
}

int board_get_legal_moves(int color, move_t *legal_moves) {
    int count = get_jumps(color, legal_moves);
    if (count > 0) {
        return count;
    }
    count = get_moves(color, legal_moves);
    return count;
}

void board_print() {
    printf(" 5:   %2d  %2d  %2d  %2d\n", board[5], board[6], board[7], board[8]);
    printf(" 9: %2d  %2d  %2d  %2d\n", board[9], board[10], board[11], board[12]);
    printf("14:   %2d  %2d  %2d  %2d\n", board[14], board[15], board[16], board[17]);
    printf("18: %2d  %2d  %2d  %2d\n", board[18], board[19], board[20], board[21]);
    printf("23:   %2d  %2d  %2d  %2d\n", board[23], board[24], board[25], board[26]);
    printf("27: %2d  %2d  %2d  %2d\n", board[27], board[28], board[29], board[30]);
    printf("32:   %2d  %2d  %2d  %2d\n", board[32], board[33], board[34], board[35]);
    printf("36: %2d  %2d  %2d  %2d\n", board[36], board[37], board[38], board[39]);
    printf("\nScore: White: %d, Black: %d\n", board_get_score(WHITE), board_get_score(BLACK));
    fflush(stdout);
}

