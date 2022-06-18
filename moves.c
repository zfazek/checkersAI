#include "moves.h"
#include "move.h"

#include <stdio.h>

void moves_print(int n_moves, move_t *moves) {
    for (int i = 0; i < n_moves; ++i) {
        for (int j = 0; j < moves[i].len; ++j) {
            printf("%d ", moves[i].idxs[j]);
        }
        puts("");
    }
    puts("");
}
