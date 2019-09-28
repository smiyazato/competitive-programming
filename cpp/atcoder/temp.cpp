#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define vvi vector<vector<int>>
#define vec vector
#define pq priority_queue
#define all(v) (v).begin(), (v).end()
#define uniqueV(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());
//#define rep(i, n) for (int (i) = (0); (i) < (n); ++(i))
#define repp(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
#define dbg(x) cerr << #x << ": " << x << endl;
#define dbg2(x, y) cerr<<"("<<#x<<", "<<#y<<") = "<<"("<<x<<", "<<y<<")"<<endl;
#define dbg3(x, y, z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = "<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;
#define dbgB(value, size) cerr<<#value<<": "<<bitset<size>(value) << endl;
#define line() cerr << "---------------" << endl;
 
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const double PI = 3.14159265358979323846;
//using pii = pair<int, int>;
 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
 
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
 
int L, N;
deque<int> X;
// vector<int> X;
 
signed main() {
  cin >> L >> N;
  // X.resize(N);
  rep (i, N) {
    // cin >> X[i];
    int x; cin >> x;
    X.push_back(x);
  }

  
  int ans = 0;
  int pos = 0;
 
  while (X.size()) {
    // front
    int front = 0;
    if (pos < X.front()) {
      front = X.front() - pos;
    } else {
      front = (L - pos) + X.front();
    }
 
    // back
    int back = 0;
    if (pos < X.back()) {
      back = pos + (L - X.back());
    } else {
      back = pos - X.back();
    }
 
    // dbg2(front, back)
    if (front > back) {
      ans += front;
      pos = X.front();
      X.pop_front();
    } else {
      ans += back;
      pos = X.back();
      X.pop_back();
    }
  }
 
  cout << ans << endl;
 
  return 0;
}
