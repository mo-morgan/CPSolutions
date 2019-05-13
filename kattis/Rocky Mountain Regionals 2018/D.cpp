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
    int n;
    cin >> n;
    vector<int> cites(n);
    REP(i, n) {
        cin >> cites[i];
    }
    sort(cites.begin(), cites.end());
    unordered_map<int, int> counts;
    int c = 0;
    FORD(i, n-1, 0) {
        c++;
        counts[cites[i]] = c;
    }
    
    int cur = n, count = 0, last = cites[n-1];
    FORD(i, n-1, 0) {
        if (counts[cites[i]] >= cites[i]) {
            if (last > count && count > cites[i]) {
                cur = count;
            } else {
                cur = cites[i];
            }
            break;
        }
        last = cites[i];
        count++;
    }

    cout << cur << n1;
    
    return 0;
}
