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
    let a: u32 = read();
    let b: u32 = read();
    let ans = if (a * b) % 2 == 0 { "Even" } else { "Odd" };
    println!("{}", ans);
    let s: Vec<char> = read::<String>().chars().collect();
    let mut cnt = 0;
    if s[0] == '1' { cnt += 1; }
    if s[1] == '1' { cnt += 1; }
    if s[2] == '1' { cnt += 1; }
    println!("{}", cnt);
    for i in 0..10 + 2 {
        println!("a");
    }
    let h = read();
    for i in 0..h {
        let n = read();
        let mut v: Vec<(i32, i32, i32)> = (0..n).map(|_| (read(), read(), read())).collect();
        println!("{}", v[0].0);
    }
}
