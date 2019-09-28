#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define NDEBUG
//#include <cassert>

#define per(i,a,n) for (unsigned int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define For(i,a,b) for(unsigned int i=(a);i<(b);++i)
#define rep(i,a,n) for (unsigned int i=a;i<n;i++)
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif
#define vvi vector<vector<int>>
#define vec vector
#define pq priority_queue
#define all(v) (v).begin(), (v).end()
#define uniqueV(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());
#define repp(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
#define dbg(x) cerr << #x << ": " << x << endl;
#define dbg2(x, y) cerr<<"("<<#x<<", "<<#y<<") = "<<"("<<x<<", "<<y<<")"<<endl;
#define dbg3(x, y, z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = "<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;
#define dbgB(value, size) cerr<<#value<<": "<<bitset<size>(value) << endl;
#define line() cerr << "---------------" << endl;
using ll = long long;
using Double = long double ;
using ull = unsigned long long;
using ii = pair<int,int>;
using llll = pair<ll,ll>;
using dd = pair<double,double>;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const double PI = 3.14159265358979323846;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
#define pcnt __builtin_popcount
#define buli(x) __builtin_popcountll(x)
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
template<typename T, typename U>
void print1(T Array, U size) {
  for (int i = 0; i < size; i++) {
    cout << Array[i] << " ";
  }
  cout << endl;
}
 
template<typename T>
void print(T Array, int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << " " << Array[i][j];
    }
    cout << endl;
  }
}

int N, Q;
    int const INF = INT_MAX;
struct SegmentTree {
private:
    int n;
    vector<int> node;

public:
    // 元配列 v をセグメント木で表現する
    SegmentTree(vector<int> v) {
        // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
        // セグメント木全体で必要なノード数は 2n-1 個である
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);

        // 最下段に値を入れたあとに、下の段から順番に値を入れる
        // 値を入れるには、自分の子の 2 値を参照すれば良い
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }
    void update(int x, int val) {
    // 最下段のノードにアクセスする
    x += (n - 1);

    // 最下段のノードを更新したら、あとは親に上って更新していく
    node[x] = val;
    while(x > 0) {
        x = (x - 1) / 2;
        node[x] = min(node[2*x+1], node[2*x+2]);
    }
    }
    int getmin(int a, int b, int k=0, int l=0, int r=-1) {
    // 最初に呼び出されたときの対象区間は [0, n)
    if(r < 0) r = n;

    // 要求区間と対象区間が交わらない -> 適当に返す
    if(r <= a || b <= l) return INF;

    // 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
    if(a <= l && r <= b) return node[k];

    // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
    // 左側の子を vl ・ 右側の子を vr としている
    // 新しい対象区間は、現在の対象区間を半分に割ったもの
    int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
    int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
    return min(vl, vr);
    }
};
int main() {
    cin >> N >> Q;
    SegmentTree seg( vector<int>(N, INF) );
    for(int i=0; i<Q; i++) {
        int c, x, y; cin >> c >> x >> y;
        if(c == 0) seg.update(x, y);
        else cout << seg.getmin(x, y+1) << endl;
    }
    return 1;
}
