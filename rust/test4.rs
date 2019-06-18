use std::io::*;
use std::str::FromStr;
fn read<T: FromStr>() -> T {
    let stdin = stdin();
    let stdin = stdin.lock();
    let token: String = stdin
        .bytes()
        .map(|c| c.expect("failed to read char") as char) 
        .skip_while(|c| c.is_whitespace())
        .take_while(|c| !c.is_whitespace())
        .collect();
    token.parse().ok().expect("failed to parse token")
}
#[allow(unused_variables, unused_mut)]
fn main() {
    let h = read();
    for i in 0..h {
        let n = read();
        let mut v: Vec<(i32, i32, i32)> = (0..n).map(|_| (read(), read(), read())).collect();
        println!("{}", v[0].0);
    }
}
