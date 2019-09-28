#include <bits/stdc++.h>
using namespace std;
#define NDEBUG
#include <cassert>
using ll = long long;
#define rep(i,a,n) for (int i=a;i<n;i++)
const ll LINF = 1e18;

 
// ------------------------------------------------------------------------------------------
int a;
int b;
int c;
long long d, e, f;
int main()
{
    cin >> a >> b >> c;
    long long x[a];
    long long y[b];
    long long z[c];
    rep(i, 0, a) { 
       cin >> d;
       x[i] = d;
    }
    rep(i, 0, b) { 
       cin >> e;
       y[i] = e;
    }
    rep(i, 0, c) { 
        cin >> f;
        z[i] = f;
    }
        
    rep(j, 0, c) { 
        long long min = mins[];
        long long stop = 0;
        rep(i, 0, a)
        {
            if (abs(z[j] - x[i]) <= min) {
                min = abs(z[j] - x[i]);
                stop = x[i];
            }
        }
        long long min2 = LINF;
        rep(i, 0, b)
        {
            if (min + abs(stop - y[i]) <= min2) {
                min2 = min + abs(stop - y[i]);
            }
        }
        long long min3 = LINF;
        long long stop2 = 0;
        rep(i, 0, b)
        {
            if (abs(z[j] - y[i]) <= min3) {
                min3 = abs(z[j] - y[i]);
                stop2 = y[i];
            }
        }
        long long min4 = LINF;
        rep(i, 0, a)
        {
            if (min3 + abs(stop2 - x[i]) <= min4) {
                min4 = min3 + abs(stop2 - x[i]);
            }
        }
        if (min2 > min4) {
            cout << min4 << endl;
        } else {
            cout << min2 << endl;
        }
    }
    return 0;
}