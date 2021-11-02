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

#define TESTFILE "hello"

int main()
{
#ifdef ONLINE_JUDGE
    freopen(TESTFILE ".in", "r", stdin);
#endif
	
	desync
    int T;
    cin >> T;
    vector<string> ret(T);
    REP(i, T) {
        vector<int> ar(12);
        REP(j, 12) {
            cin >> ar[j];
        }
        int last = ar[0];
        bool allBigger = true;
        FOR(j, 1, 4) {
            if (ar[j] <= last) {
                allBigger = false;
                break;
            }
            last = ar[j];
        }
        if (!allBigger) {
            ret[i] = "no";
            continue;
        }
        int m = ar[3];
        FOR(j, 4, 11) {
            if (ar[j] <= m) {
                allBigger = false;
                break;
            }
        }
        ret[i] = (allBigger ? "yes" : "no");
    }

    REP(i, T) {
        cout << ret[i] << n1;
    }
    return 0;
}
