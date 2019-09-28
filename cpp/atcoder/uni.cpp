#include <bits/stdc++.h>
using namespace std;
#define int long long
#define NDEBUG
#include <cassert>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
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
 
// ------------------------------------------------------------------------------------------
const int MAXN = 101024;

// Union Find >>>>>>>>>>>>>

class UnionFind{
private:
  std::vector<int> data_array;
  const int root(int id){
    if(data_array[id] >= 0)
      return data_array[id] = root(data_array[id]);
    else
      return id;
  }
public:
  UnionFind(size_t size) : data_array(size,-1){}
  // unionは予約語
  bool union_(int lhs, int rhs){
    lhs = root(lhs);
    rhs = root(rhs);
    bool is_union = (lhs != rhs);
    if(is_union){
      if( data_array[lhs] > data_array[rhs]){  std::swap(lhs,rhs);  }
      data_array[lhs] += data_array[rhs];
      data_array[rhs] = lhs;
    }
    return is_union;
  }
  bool find(int lhs, int rhs){
    return ( root(lhs) == root(rhs) );
  }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    UnionFind tree(N);

    for(int i = 0; i < Q; i++) {
        int p, x, y;
        cin >> p >> x >> y;
        if(p==0){
            tree.unite(x, y); // xの木とyの木を併合する
        }else{
            if(tree.same(x, y)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }

    return 0;
}

