#include <bits/stdc++.h>
using namespace std;
#define desync              ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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

int main()
{
    desync
    int t;
    cin >> t;
    vector<int> ret(t);
    REP(i, t) {
        int n, k;
        cin >> n >> k;
        vector<int> taps(k);
        unordered_set<int> watered;
        REP(j, k) {
            int tap;
            cin >> tap;
            tap--;
            taps[j] = tap;
        }
        FOR(j, 1, 200) {
            REP(w, taps.size()) {
                FOR(k, taps[w] - (j-1), taps[w] + (j-1)) {
                    if (k >= 0 && k < n) {
                        watered.insert(k);
                    }
                }
            }
            if (watered.size() >= n) {
                cout << j << n1;
                break;
            }
        }
    }
    
    return 0;
}
