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

int main()
{
    IOS();
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    REP(i, n) {
        cin >> arr[i];
    }
    vector<int> dp(n, MAX);
    dp[0] = 0;
    FOR(i, 1, n-1) {
        FOR(j, max(0, i-k), i-1) {
            dp[i] = min(dp[i], abs(arr[i] - arr[j]) + dp[j]);
        }
    }
    cout << dp[n-1] << n1;
    return 0;
}
