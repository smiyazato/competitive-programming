#include <bits/stdc++.h>
using namespace std;
#define NDEBUG
#include <cassert>
#define rep(i,a,n) for (int i=a;i<n;i++)

 
// ------------------------------------------------------------------------------------------
int a;
double b;
double c;
string d;
double r = 0.0;
int main()
{
    cin >> a;
    rep(i, 0, a) {
       cin >> c >> d;
       if (d == "JPY") {
           r = r + c;
       }
       else if (d == "BTC")
       {
           r = r + c * 380000.0;
       }
    }
    cout << r << endl;
    return 0;
}