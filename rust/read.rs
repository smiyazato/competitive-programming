//rustc
use std::io;
use std::str::FromStr;

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin.read_line(&mut buf).ok();
    let mut times = buf.split_whitespace().map(|n| usize::from_str(n).unwrap());
    for x in 0..(times.next().unwrap()) {
        stdin.read_line(&mut buf).ok();
        let mut v_e = buf.split_whitespace().map(|n| usize::from_str(n).unwrap());
        for x in 0..(v_e.next().unwrap()) {
            
        }
    }
    //println!("N: {}, M: {}", n, m);
}
