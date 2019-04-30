#include <bits/stdc++.h>
using namespace std;
#define desync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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

int h, w;
char mat[1001][1001];
ll dp[1001][1001];

ll power(ll b, int e) {
    ll res = 1;
    for ( ; e>0; e/=2) {
        if (e&1) res = res*b % MOD;
        b = b*b % MOD;
    }
    return res;
}

int main()
{
    desync
    cin >> h >> w;
    vector<string> ss(h);
    REP(i, h) cin >> ss[i];
    REP(i, h) REP(j, w) mat[i][j] = ss[i].at(j);
    REP(i, h) {
        if (mat[i][0] == '.') dp[i][0] = 1;
        if (mat[i][0] == '#') break;
    }
    REP(j, w) {
        if (mat[0][j] == '.') dp[0][j] = 1;
        if (mat[0][j] == '#') break;
    }
    
    FOR(i, 1, h-1) {
        FOR(j, 1, w-1) {
            if (mat[i][j] == '#') dp[i][j] = 0;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    
    cout << (dp[h-1][w-1] + MOD) % MOD << n1;
    return 0;
}
