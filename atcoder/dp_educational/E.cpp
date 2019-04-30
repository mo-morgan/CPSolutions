#include <bits/stdc++.h>
using namespace std;
#define EPS                 0.00000001
#define LL_MAX              0x3f3f3f3f3f3f3f3f
#define LL_MIN              -0x3f3f3f3f3f3f3f3f
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

int main()
{
    IOS();
    int n, w;
    cin >> n >> w;
    vector<ll> ws(n+1);
    vector<ll> vs(n+1);
    FOR(i, 1, n) {
        cin >> ws[i];
        cin >> vs[i];
    }
    // dp stores the minimum weight to get total value of j with i items
    ll dp[n+1][100050];
    FOR(i, 0, n) {
        dp[i][0] = 0;
        FOR(j, 1, 100000) {
            dp[i][j] = LL_MAX;
        }
    }
     
    FOR(i, 1, n) {
        FOR(j, 1, 100000) {
            dp[i][j] = dp[i-1][j];
            if (j >= vs[i]) dp[i][j] = min(dp[i][j], dp[i-1][j-vs[i]] + ws[i]);
        }
    }

    ll ret = 0;
    FORD(i, 100000, 0) {
        if (dp[n][i] <= w) {
            ret = i;
            break;
        }
    }

    cout << ret << n1;
    
    return 0;
}
