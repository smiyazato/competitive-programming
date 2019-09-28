#include <bits/stdc++.h>
using namespace std;

#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }

int L, N; // 円周, 木の本数
int X[2222]; // 初期位置からの距離(左回り), 1-indexed
int Y[2222]; // 初期位置からの距離(右回り), 1-indexed
int dp[2222][2222][2]; // dp[左回りで燃やした本数][右回りで燃やした本数][現在地]

signed main() {
  cin >> L >> N;
  for (int i = 1; i <= N; i++) {
    cin >> X[i];
    Y[N-i+1] = L - X[i]; // あらかじめ計算しておく
  }

  for (int li = 0; li <= N; li++) { // 左回りで燃やした本数
    for (int ri = 0; ri <= N; ri++) { // 右回りで燃やした本数
      // 左へ
      if (li > 0) {
        chmax(dp[li][ri][0], dp[li-1][ri][0] + X[li] - X[li-1]); // 今左
        chmax(dp[li][ri][0], dp[li-1][ri][1] + X[li] + Y[ri]); // 今右
      }

      // 右へ
      if (ri > 0) {
        chmax(dp[li][ri][1], dp[li][ri-1][0] + X[li] + Y[ri]); // 今左
        chmax(dp[li][ri][1], dp[li][ri-1][1] + Y[ri] - Y[ri-1]); // 今右
      }
    }
  }

  int ans = 0;
  for (int li = 0; li <= N; li++) {
    // li + ri = Nなので
    int ri = N - li;
    chmax(ans, dp[li][ri][0]);
    chmax(ans, dp[li][ri][1]);
  }

  cout << ans << endl;


  return 0;
}
