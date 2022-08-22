pub struct Move {
    pub idxs: Vec<usize>,
}

impl Move {
    pub fn print(&self) {
        for idx in &self.idxs {
            print!("{} ", idx);
        }
        println!("");
    }
}
