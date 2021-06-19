use std::collections::BinaryHeap;//優先度付きヒープ
use std::cmp::Ordering;//優先度設定
#[derive(Copy, Clone, Eq, PartialEq)]
struct Edge {
    to: usize,
    cost: usize
}
impl Ord for Edge {
    fn cmp(&self, other: &Self) -> Ordering {
        other.cost.cmp(&self.cost)
            .then_with(|| self.to.cmp(&other.to))
    }
}
impl PartialOrd for Edge {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}
fn main() {
    let mut heap_test = BinaryHeap::new();
    heap_test.push(Edge { cost: 4, to: 1 });
    heap_test.push(Edge { cost: 3, to: 2 });
    heap_test.push(Edge { cost: 5, to: 3 });
    while let Some(Edge { to, cost }) = heap_test.pop() {
        println!("{} {}", to, cost);
    }
    let adj_list = vec![
        vec![Edge { to: 2, cost: 10 }, Edge { to: 1, cost: 1 }],
        vec![Edge { to: 3, cost: 2 }],
        vec![
            Edge { to: 1, cost: 1 },
            Edge { to: 3, cost: 3 },
            Edge { to: 4, cost: 1 },
        ],
        vec![Edge { to: 0, cost: 7 }, Edge { to: 4, cost: 2 }],
        vec![],
    ];
    let mut distant = vec![usize::max_value(); 5];
    let mut previous = vec![0; 5];
    let mut heap = BinaryHeap::new();
    distant[0] = 0;
    heap.push(Edge { cost: 0, to: 0 });
    while let Some(Edge { to, cost }) = heap.pop() {
        for edge in &adj_list[to] {
            let next = Edge { cost: cost + edge.cost, to: edge.to };
            if next.cost < distant[next.to] {
                heap.push(next);
                distant[next.to] = next.cost;
                previous[next.to] = to;
            }
        }
    }
    println!("{:?}",distant);
    println!("{:?}", previous);
}
