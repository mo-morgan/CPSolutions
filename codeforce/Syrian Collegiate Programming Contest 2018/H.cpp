#include <bits/stdc++.h>
using namespace std;
#define desync				ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define EPS 				0.00000001
#define LL_MAX 				0x3f3f3f3f3f3f3f3f
#define LL_MIN				-0x3f3f3f3f3f3f3f3f
#define MAX					0x3f3f3f3f
#define MIN					-0x3f3f3f3f
#define MOD					1000000007
#define DEBUG(x) 			cout << '>' << #x << ':' << x << endl;
#define REP(i,n) 			for(int i=0;i<(n);i++)
#define FOR(i,a,b) 			for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) 		for(int i=(a);i>=(b);i--)
#define n1 					'\n'

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
#define TESTFILE "bugged"
int main()
{
	desync
#ifdef ONLINE_JUDGE
    freopen(TESTFILE ".in", "r", stdin);
#endif

    int t;
    cin >> t;
    vector<ll> ret(t);
    REP(i, t) {
        int n, m;
        cin >> n >> m;
        vector<ll> dist(n);
        REP(j, n) {
            cin >> dist[j];
        }
        vector<int> ar(m);
        unordered_map<int,int> start;
        unordered_map<int,int> end;
        REP(j, m) {
            int u, v;
            cin >> u >> v;
            v--;u--;
            ar[j] = abs(dist[v] - dist[u]);
            start[u]++;
            end[v]++;
        }
        bool allClear = true;
        for (auto it : start) {
            if (it.second != end[it.first]) {
                ret[i] = -1;
                allClear = false;
                break;
            }
        }
        if (!allClear) {
            ret[i] = -1;
            continue;
        }
        REP(j, m) {
            ret[i] += ar[j];
        }
    }

    REP(i, t) {
        cout << ret[i] << n1;
    }
    return 0;
}
