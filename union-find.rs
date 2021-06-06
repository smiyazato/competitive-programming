struct Unionfind {
    parent: Vec<i64>,
}
impl Unionfind {
    fn root(&mut self, x: usize) -> i64 {
        if self.parent[x] as usize == x {
            return self.parent[x];
        } else {
            return self.root(self.parent[x] as usize);
        }
    }
    fn unite(&mut self, x: usize, y: usize) {
        let rx = self.root(x);
        let ry = self.root(y);
        if rx == ry {
            return;
        }
        self.parent[rx as usize] = ry;
    }
    fn same(&mut self, x: usize, y: usize) -> bool {
        return self.root(x) == self.root(y)
    }
}

fn main() {
    let n = 8;
    let mut unionfind = Unionfind { parent: (0..n).collect() };
    unionfind.unite(1, 2);
    unionfind.unite(3, 2);
    println!("{:?}", unionfind.same(1, 3));
    println!("{:?}", unionfind.same(1, 4));
    unionfind.unite(2, 4);
    println!("{:?}", unionfind.same(4, 1));
    unionfind.unite(0, 0);
    println!("{:?}", unionfind.same(0, 0));
}
