#include <bits/stdc++.h>
using namespace std;
#define EPS                 0.00000001
#define LL_MAX              1e18
#define LL_MIN              -1e18
#define MAX                 0x3f3f3f3f
#define MIN                 -0x3f3f3f3f
#define MOD                 1000000007
#define DEBUG(x)            cout << '>' << #x << ':' << x << endl;
#define REP(i,n)            for(int i=0;i<(n);i++)
#define FOR(i,a,b)          for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)         for(int i=(a);i>=(b);i--)
#define n1                  '\n'

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ld> pt;
typedef vector<pt> pol;

ll power(ll b, int e) {
    ll res = 1;
    for ( ; e>0; e/=2) {
        if (e&1) res = res*b % MOD;
        b = b*b % MOD;
    }
    return res;
}

inline void IOS() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ll knapsack(vector<ll> w, vector<ll> v, int N, ll W) {
    ll K[N+1][W+1];
    FOR(i, 0, N) {
        FOR(j, 0, W) {
            if (i==0 || j==0) K[i][j] = 0;
            else if (w[i-1] <= j) {
                K[i][j] = max(v[i-1] + K[i-1][j-w[i-1]], K[i-1][j]);
            } else {
                K[i][j] = K[i-1][j];
            }
        }   
    }
    
    return K[N][W];
}

int main()
{
    IOS();
    int n, w;
    cin >> n >> w;
    vector<ll> ws(n);
    vector<ll> vs(n);
    REP(i, n) {
        cin >> ws[i];
        cin >> vs[i];
    }
    cout << knapsack(ws, vs, n, w) << n1;
    
    return 0;
}
