#型
* [i32; 3]
* String
* "hello"[0] // error!
"あいうえお".as_bytes()[0] // => 227: u8
"あいうえお".chars().nth(0) // => Some('あ'): Option<char>
配列が欲しい = Vec
連想配列が欲しい = HashMap
連想配列が欲しい & キーの順序が重要 = BTreeMap
スタックが欲しい = Vec
キューが欲しい = VecDeque
outer
rustc -A dead_code main.rs
