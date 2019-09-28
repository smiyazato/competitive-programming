#include <bits/stdc++.h>
using namespace std;
#define NDEBUG
#include <cassert>

 
// ------------------------------------------------------------------------------------------
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
int n, m;
int a, b;
signed main()
{
    cin >> n >> m;
    deque<int> adv[n];
    int c[m];
    int d[m];
    rep(i, 0, m)
    {
        cin >> a >> b;
        c[i] = a - 1;
        d[i] = b - 1;
        adv[c[i]].push_back(d[i]);
        adv[d[i]].push_back(c[i]);
    }
    vector<vector<bool>> F(n, vector<bool>(n, false));
    rep (j, 0, n) {
        queue<int> q1;
        rep(i, j, n) {
            F[j][i] = true;
            q1.push(i);
            while(q1.empty() == false) {
                q1.pop();
                for (auto u = adv[i].begin(); u != adv[i].end(); ++u) {
                    if (F[j][*u] == false) {
                        F[j][*u] = true;
                        q1.push(*u);
                    }
                }
            }
        }
    }
    int fu = 0;
    
    rep(i, 0, m)
    {
        adv[c[i]].pop_front();
        adv[d[i]].pop_front();
        rep (j, 0, n) {
            vector<vector<bool>> F2(n, vector<bool>(n, false));
            queue<int> q1;
            rep(i, j, n) {
                
                    F2[j][i] = true;
                    q1.push(i);
                    while(q1.empty() == false) {
                        q1.pop();
                        for (auto u = adv[i].begin(); u != adv[i].end(); ++u) {
                            if (F2[*u][j] == false) {
                                F2[*u][j] = true;
                                q1.push(*u);
                           }
                        }
                    }
                    
                
            }
            
            
            rep (j, 0, n) {
            rep(i, j, n) {if (F[i][j] == true && F2[i][j] == false) {
                        fu = fu + 1;
                        F[i][j] == false;
            }
            }
            }
        }
        cout << fu << endl;
    }
    

    return 0;
}