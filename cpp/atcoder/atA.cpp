#include <bits/stdc++.h>
using namespace std;
#define NDEBUG
#include <cassert>
 
// ------------------------------------------------------------------------------------------
int a, b, c;
int main()
{
    scanf("%d/%d/%d", &a, &b, &c);
    if (a < 2019) {
        cout << "Heisei" << endl;
    } else if (a > 2019) {
        cout << "TBD" << endl;
    } else if (b < 4) {
        cout << "Heisei" << endl;
    } else if (b > 4) {
        cout << "TBD" << endl;
    } else if (c <= 30) {
        cout << "Heisei" << endl;
    } else {
      cout << "TBD" << endl;
    }
    return 0;
}