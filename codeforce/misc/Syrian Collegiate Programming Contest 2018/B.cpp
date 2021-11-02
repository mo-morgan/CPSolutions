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
#define TESTFILE "hamming"

int main()
{
	desync
#ifdef ONLINE_JUDGE
    freopen(TESTFILE ".in", "r", stdin);
#endif
    int t;
    cin >> t;
    vector<int> ret(t);
    REP(i, t) {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end(), greater<char>());
        int cur = 0;
        REP(j, n) {
            if (s1[j] != s2[j]) {
                cur++;
            }
        }
        ret[i] = cur;
    }
    REP(i, t) {
        cout << ret[i] << n1;
    }

    return 0;
}
