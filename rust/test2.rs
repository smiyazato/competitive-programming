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
/*
fn main() {
    let s: String = read();
    println!("{}", s.chars().filter(|&c| c == '1').count());
}
*/

fn main() {
    let s: Vec<char> = read::<String>().chars().collect();
    let mut cnt = 0;
    if s[0] == '1' { cnt += 1; }
    if s[1] == '1' { cnt += 1; }
    if s[2] == '1' { cnt += 1; }
    println!("{}", cnt);
}
