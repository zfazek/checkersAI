#pragma once

#include <stdio.h>

#include "move.h"

#define WHITE_PAWN 1
#define WHITE_KING 12
#define BLACK_PAWN -1
#define BLACK_KING -12

#define EMPTY 0
#define INVALID 3

#define WHITE 1
#define BLACK -1

void board_initialize();
int board_get_score(int color);
void board_print();
int board_get_legal_moves(int color, move_t *legal_moves);
