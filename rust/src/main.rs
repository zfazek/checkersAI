use board::Board;
use move_checkers::Move;

mod board;
mod move_checkers;

const WHITE: i32 = 1;
const BLACK: i32 = -WHITE;

fn main() {
    println!("Hello, world!");
    let mut color_to_move = BLACK;
    let board = Board::new();
    board.print();
    let legal_moves = board.get_legal_moves(color_to_move);
    print_moves(legal_moves);
    color_to_move = toggle_color_to_move(color_to_move);
    let legal_moves = board.get_legal_moves(color_to_move);
    print_moves(legal_moves);
}

fn toggle_color_to_move(color: i32) -> i32 {
    -color
}

fn print_moves(moves: Vec<Move>) {
    for m in moves {
        m.print();
    }
    println!("");
}
