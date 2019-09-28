    #include <bits/stdc++.h>
    using namespace std;
     
    #define NDEBUG
    #include <cassert>
     
     
    using ll = long long;
    using Double = long double ;
    using ull = unsigned long long;
    using ii = pair<int,int>;
    using llll = pair<ll,ll>;
    using dd = pair<double,double>;
     
    using vi = vector<int>;
    using vvi = vector<vector<int>>;
    using vii = vector<ii>;
    using vvii = vector<vector<ii>>;
    using vll = vector<ll>;
    using vvll = vector<vector<ll>>;
    using vllll = vector<llll>;
    using vb = vector<bool>;
    using vs = vector<string>;
    using vd = vector<double> ;
    using vD = vector<long double>;
     
    #define sz(a)  int((a).size())
    #define pb  push_back
    #define eb  emplace_back
    #define FOR(var,from,to) for(int var=(from);var<=(to);++var)
    #define rep(var,n)  for(int var=0;var<(n);++var)
    #define rep1(var,n)  for(int var=1;var<=(n);++var)
    #define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
    #define repC3(vari,varj,vark,n)  for(int vari=0;vari<(n)-2;++vari)for(int varj=vari+1;varj<(n)-1;++varj)for(int vark=varj+1;vark<(n);++vark)
    #define ALL(c)  (c).begin(),(c).end()
    #define RALL(c)  (c).rbegin(),(c).rend()
    #define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
    #define found(s,e)  ((s).find(e)!=(s).end())
    #define mset(arr,val)  memset(arr,val,sizeof(arr))
    #define mid(x,y) ((x)+((y)-(x))/2)
    #define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
    #define cons make_pair
     
    template<class T> inline void amin(T & a, T const & b) { a = min(a, b); }
    template<class T> inline void amax(T & a, T const & b) { a = max(a, b); }
    template<typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
    template<typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }
     
     
    ll gcd(ll a, ll b) { while(a) swap(a, b%=a); return b; }
     
    const ll MOD=1000000007LL;
     
    ll ADD(ll x, ll y) { return (x+y) % MOD; }
    ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
    ll MUL(ll x, ll y) { return x*y % MOD; }
    ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
    ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }
     
    const ll half = DIV(1LL, 2LL);
     
    inline ll avg(ll a, ll b) {
        return MUL(ADD(a, b), half);
    }
     
    ll solve(int N, int Q, vi& a, vi& qx, vi& qy) {
        vector<vll> dp(N, vll(N, 0));
        rep(i,N) rep(j,N) if (a[i] > a[j]) dp[i][j] = 1;
     
        rep(q,Q) {
            int x = qx[q], y = qy[q];
            rep(i,N) {
                if (i != x && i != y) {
                    dp[x][i] = dp[y][i] = avg(dp[x][i], dp[y][i]);
                    dp[i][x] = dp[i][y] = avg(dp[i][x], dp[i][y]);
                }
                dp[x][y] = dp[y][x] = avg(dp[x][y], dp[y][x]);
            }
        }
     
        ll ans = 0;
        repC2(i,j,N) ans = ADD(ans, dp[i][j]);
        ans = MUL(ans, POW(2, Q));
        return ans;
    }
     
    int main() {
        int N,Q; scanf("%d%d", &N, &Q);
        vi a(N);
        rep(i,N) scanf("%d", &a[i]);
        vi x(Q), y(Q);
        rep(i,Q) {
            scanf("%d%d", &x[i], &y[i]);
            --x[i]; --y[i];
        }
        cout << solve(N,Q,a,x,y) << endl;
        return 0;
    }