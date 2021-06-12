use std::cmp::max;
struct SegmentTree<F, T> {
    size: usize,
    tree: Vec<T>,
    identity_element: T,
    eval_function: F,
}
impl<F: Fn(T, T) -> T, T: Copy + Eq + std::fmt::Debug> SegmentTree<F, T> {
    fn new(max: usize, identity_element: T, eval_function: F) -> Self {
        let size = max.next_power_of_two();//19->32 5->8など
        Self {
            size,
            tree: vec![identity_element; size * 2 - 1],
            identity_element,
            eval_function,
        }
    }
    fn get(&self, query_min: usize, query_max: usize) -> T {
        return self._get(query_min, query_max, 0, 0, self.size - 1);
    }
    fn _get(&self, query_min: usize, query_max: usize, current: usize, seg_min: usize, seg_max: usize) -> T {//例：1~4を0~7から
        if seg_max < query_min || query_max < seg_min {//完全範囲外
            self.identity_element
        } else if query_min <= seg_min && seg_max <= query_max {//完全範囲内
            self.tree[current]
        } else {
            (self.eval_function)(
                self._get(query_min, query_max, current * 2 + 1, seg_min, (seg_min + seg_max) / 2),//左側を見る 0~3
                self._get(query_min, query_max, current * 2 + 2, (seg_min + seg_max) / 2 + 1, seg_max),//右側を見る 4~7
            )
        }
    }
    pub fn update(&mut self, index: usize, value: T) {
        let mut i = self.size + index - 1;
        self.tree[i] = value;
        while i > 0 {
            i = (i - 1) / 2;
            self.tree[i] = (self.eval_function)(self.tree[i * 2 + 1], self.tree[i * 2 + 2]);
        }
    }
}

fn main() {
    let mut seg_tree = SegmentTree::new(7, 0, |a, b| max(a, b));//0はmaxの単位元
    //let mut seg_tree = SegmentTree::new(7, 0, |a, b| a ^ b);//クロージャ 0はxorの単位元
    //let mut seg_tree = SegmentTree::new(7, std::i64::MAX, |a, b| min(a, b));
    let vec = vec![5, 7, 1, 4, 2, 9, 8];
    for (i, v) in vec.iter().enumerate() {
        seg_tree.update(i, *v);
        println!("{}", seg_tree.get(0, 6));
    }
    println!("{}", "");
    seg_tree.update(1, 1);
    println!("{}", seg_tree.get(0, 4));
    seg_tree.update(2, 11);
    println!("{}", seg_tree.get(0, 4));
    seg_tree.update(2, 0);
    println!("{}", seg_tree.get(0, 4));
}
