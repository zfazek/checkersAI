project(checkersAI)

set(CMKAE_C_FLAGS "-g -O2 -Wall")

add_executable(checkers
    checkers.c
    board.c
    moves.c
    )
