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
    int T;
    cin >> T;
    vector<int> ret(T+1);
    REP(i, T) {
        int n, q;
        cin >> n >> q;
        string s; cin >> s;
        REP(j, q) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            string sub = s.substr(l, r-l+1);
            unordered_set<char> m;
            REP(w, sub.size()) {
                char c = sub[w];
                auto it = m.find(c);
                if (it == m.end()) {
                    m.insert(c);
                } else {
                    m.erase(c);
                }
            }        
            if (m.size() == 0 || (m.size() == 1 && sub.size() % 2 == 1)) {
                ret[i+1]++;
            }
        }
    }
    FOR(i, 1, T) {
        cout << "Case #" << i << ": " << ret[i];
        cout << n1;
    }
    return 0;
}
