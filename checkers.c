#include <stdio.h>

#include "board.h"
#include "move.h"
#include "moves.h"

move_t legal_moves[64];
int color_to_move;

void toggle_color_to_move() {
    color_to_move = -color_to_move;
}

int main() {
    int n_moves;
    color_to_move = BLACK;
    board_initialize();
    board_print();
    n_moves = board_get_legal_moves(color_to_move, legal_moves);
    moves_print(n_moves, legal_moves);
    toggle_color_to_move();
    n_moves = board_get_legal_moves(color_to_move, legal_moves);
    moves_print(n_moves, legal_moves);
}

