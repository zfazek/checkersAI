//   05  06  07  08
// 09  10  11  12
//   14  15  16  17
// 18  19  20  21
//   23  24  25  26
// 27  28  29  30
//   32  33  34  35
// 36  37  38  39

use crate::move_checkers::Move;

pub struct Board {
    board: Vec<i32>,
}

const WHITE_PAWN: i32 = 1;
const WHITE_KING: i32 = 12;
const BLACK_PAWN: i32 = -1;

const EMPTY: i32 = 0;
const INVALID: i32 = 3;

const WHITE: i32 = 1;
const BLACK: i32 = -1;

const BOARD_SIZE: usize = 44;

const BLACK_INITIAL_IDXS: [usize; 12] = [5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 17];
const WHITE_INITIAL_IDXS: [usize; 12] = [27, 28, 29, 30, 32, 33, 34, 35, 36, 37, 38, 39];
const EMPTY_INITIAL_IDXS: [usize; 8] = [18, 19, 20, 21, 23, 24, 25, 26];

impl Board {
    pub fn new() -> Self {
        let mut board: Vec<i32> = vec![INVALID; BOARD_SIZE];
        for i in 0..12 {
            board[WHITE_INITIAL_IDXS[i]] = WHITE_PAWN;
            board[BLACK_INITIAL_IDXS[i]] = BLACK_PAWN;
        }
        for i in 0..8 {
            board[EMPTY_INITIAL_IDXS[i]] = EMPTY;
        }
        board[17] = EMPTY;
        board[19] = WHITE_PAWN;
        board[21] = BLACK_PAWN;
        board[29] = BLACK_PAWN;
        Self { board }
    }

    pub fn get_score(&self, color: i32) -> i32 {
        let mut score = 0;
        for i in 0..BOARD_SIZE {
            if self.board[i] == color {
                score += self.board[i];
            }
            if self.board[i] == color * WHITE_KING {
                score += self.board[i];
            }
        }
        score
    }

    fn get_jumps(&self, color: i32) -> Vec<Move> {
        let jumps: Vec<Move> = Vec::new();
        jumps
    }

    fn get_moves(&self, color: i32) -> Vec<Move> {
        let mut moves: Vec<Move> = Vec::new();
        for i in 0..BOARD_SIZE {
            if self.board[i] != color {
                continue;
            }
            match self.board[i] {
                WHITE_PAWN => {
                    if self.board[i - 5] == EMPTY {
                        let m = Move {
                            idxs: vec![i, i - 5],
                        };
                        moves.push(m);
                    }
                    if self.board[i - 4] == EMPTY {
                        let m = Move {
                            idxs: vec![i, i - 4],
                        };
                        moves.push(m);
                    }
                }
                BLACK_PAWN => {
                    if self.board[i + 4] == EMPTY {
                        let m = Move {
                            idxs: vec![i, i + 4],
                        };
                        moves.push(m);
                    }
                    if self.board[i + 5] == EMPTY {
                        let m = Move {
                            idxs: vec![i, i + 5],
                        };
                        moves.push(m);
                    }
                }
                _ => {}
            }
        }
        moves
    }

    pub fn can_jump(&self, idx: usize, color: i32, dir: usize) -> bool {
        self.board[idx + dir] == color && self.board[idx + 2 * dir] == EMPTY
    }

    pub fn get_legal_moves(&self, color: i32) -> Vec<Move> {
        let jumps = self.get_jumps(color);
        if jumps.len() > 0 {
            return jumps;
        }
        self.get_moves(color)
    }

    pub fn print(&self) {
        println!(
            " 5:   {:2}  {:2}  {:2}  {:2}",
            self.board[5], self.board[6], self.board[7], self.board[8]
        );
        println!(
            " 9: {:2}  {:2}  {:2}  {:2}",
            self.board[9], self.board[10], self.board[11], self.board[12]
        );
        println!(
            "14:   {:2}  {:2}  {:2}  {:2}",
            self.board[14], self.board[15], self.board[16], self.board[17]
        );
        println!(
            "18: {:2}  {:2}  {:2}  {:2}",
            self.board[18], self.board[19], self.board[20], self.board[21]
        );
        println!(
            "23:   {:2}  {:2}  {:2}  {:2}",
            self.board[23], self.board[24], self.board[25], self.board[26]
        );
        println!(
            "27: {:2}  {:2}  {:2}  {:2}",
            self.board[27], self.board[28], self.board[29], self.board[30]
        );
        println!(
            "32:   {:2}  {:2}  {:2}  {:2}",
            self.board[32], self.board[33], self.board[34], self.board[35]
        );
        println!(
            "36: {:2}  {:2}  {:2}  {:2}",
            self.board[36], self.board[37], self.board[38], self.board[39]
        );
        println!(
            "\nScore: White: {}, Black: {}\n",
            self.get_score(WHITE),
            self.get_score(BLACK)
        );
    }
}
