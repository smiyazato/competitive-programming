use std::io::*;
macro_rules! get {
      ($t:ty) => {
          {
              let mut line: String = String::new();
              stdin().read_line(&mut line).unwrap();
              line.trim().parse::<$t>().unwrap()
          }
      };
      ($($t:ty),*) => {
          {
              let mut line: String = String::new();
              stdin().read_line(&mut line).unwrap();
              let mut iter = line.split_whitespace();
              (
                  $(iter.next().unwrap().parse::<$t>().unwrap(),)*
              )
          }
      };
      ($t:ty; $n:expr) => {
          (0..$n).map(|_|
              get!($t)
          ).collect::<Vec<_>>()
      };
      ($($t:ty),*; $n:expr) => {
          (0..$n).map(|_|
              get!($($t),*)
          ).collect::<Vec<_>>()
      };
      ($t:ty ;;) => {
          {
              let mut line: String = String::new();
              stdin().read_line(&mut line).unwrap();
              line.split_whitespace()
                  .map(|t| t.parse::<$t>().unwrap())
                  .collect::<Vec<_>>()
          }
      };
      ($t:ty ;; $n:expr) => {
          (0..$n).map(|_| get!($t ;;)).collect::<Vec<_>>()
      };
}
#[allow(unused_variables, unused_mut)]
fn main() {
    let (n, q) = get!(u32, u32);
    let m = n as usize;
    println!("{}", m);
    let mut vec = vec![0;m];
    for i in 0..m {
        vec[i] = i;
        println!("{}", i);
    }
    /*
    for i in 0..q {
        let (p, a, b) = get!(u32, u32, u32);
        
        println!("{}, {}, {}", p, a, b);
    }*/
}
