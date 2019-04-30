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

int n;

int main()
{
    IOS();
    cin >> n;
    vector<int> a(n), b(n), c(n);
    REP(i, n) {
        cin >> a[i] >> b[i] >> c[i];
    }
    int ret[n][3];
    ret[0][0] = a[0];
    ret[0][1] = b[0];
    ret[0][2] = c[0];
    FOR(i, 1, n-1) {
        ret[i][0] = max(ret[i-1][1] + a[i], ret[i-1][2] + a[i]);
        ret[i][1] = max(ret[i-1][0] + b[i], ret[i-1][2] + b[i]);
        ret[i][2] = max(ret[i-1][0] + c[i], ret[i-1][1] + c[i]);
    }
    cout << max(ret[n-1][0], max(ret[n-1][1], ret[n-1][2])) << n1;
    return 0;
}
