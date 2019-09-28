#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define NDEBUG
#include <cassert>

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
const int INF = INT_MAX;
struct LazySegmentTree {
private:
    int n;
    vector<int> node, lazy;

public:
    LazySegmentTree(vector<int> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }
    // k 番目のノードについて遅延評価を行う
void eval(int k, int l, int r) {

    // 遅延配列が空でない場合、自ノード及び子ノードへの
    // 値の伝播が起こる
    if(lazy[k] != 0) {
        node[k] += lazy[k];

        // 最下段かどうかのチェックをしよう
        // 子ノードは親ノードの 1/2 の範囲であるため、
        // 伝播させるときは半分にする
        if(r - l > 1) {
            lazy[2*k+1] += lazy[k] / 2;
            lazy[2*k+2] += lazy[k] / 2;
        }

        // 伝播が終わったので、自ノードの遅延配列を空にする
        lazy[k] = 0;
    }
}
void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
    if(r < 0) r = n;

    // k 番目のノードに対して遅延評価を行う
    eval(k, l, r);

    // 範囲外なら何もしない
    if(b <= l || r <= a) return;
    
    // 完全に被覆しているならば、遅延配列に値を入れた後に評価
    if(a <= l && r <= b) {
        lazy[k] += (r - l) * x;
        eval(k, l, r);
    }

    // そうでないならば、子ノードの値を再帰的に計算して、
    // 計算済みの値をもらってくる
    else {
        add(a, b, x, 2*k+1, l, (l+r)/2);
        add(a, b, x, 2*k+2, (l+r)/2, r);
        node[k] = node[2*k+1] + node[2*k+2];
    }
}
ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
    if(r < 0) r = n;
    if(b <= l || r <= a) return 0;

    // 関数が呼び出されたら評価！
    eval(k, l, r);
    if(a <= l && r <= b) return node[k];
    ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
    ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
    return vl + vr;
}
int find(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return INF;
        if(a <= l && r <= b) return node[k];
        int vl = find(a, b, 2*k+1, l, (l+r)/2);
        int vr = find(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};
int main() {
    cin >> N >> Q;
    LazySegmentTree seg( vector<int>(N, INF) );
    for(int i=0; i<Q; i++) {
        int query; cin >> query;
        if(query == 0) {
            int s, t, x; cin >> s >> t >> x;
            seg.add(s, t+1, x);
        }
        else {
            int s, t; cin >> s >> t;
            cout << seg.find(s, t+1) << endl;
        }
    }
    return 0;
}
