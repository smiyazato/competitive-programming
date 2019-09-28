#include <bits/stdc++.h>
using namespace std;
#define NDEBUG
#include <cassert>
 
// ------------------------------------------------------------------------------------------
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
int a, b, c;
int mx, mn;
// vector<int> X;
signed main() {
  cin >> a >> b >> c;
  mx = b;
  mn = a;
  if (a > b) {
      mx = a;
      mn = b;
  }
  while (c > 0) {
    if (a % mn == 0 && b % mn == 0) {
            c = c - 1;
    }
    mn = mn - 1;
  }
  cout << mn+1 << endl;
 
  return 0;
}
