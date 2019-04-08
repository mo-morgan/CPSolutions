#include <bits/stdc++.h>
using namespace std;
#define EPS 				0.00000001
#define MAX 				1e18
#define MIN					-1e18
#define MOD					1000000007
#define DEBUG(x) 			cout << '>' << #x << ':' << x << endl;
#define REP(i,n) 			for(int i=0;i<(n);i++)
#define FOR(i,a,b) 			for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) 		for(int i=(a);i>=(b);i--)
#define n1 					'\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pt;

int T;

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
	cin >> T;
	vector<string> ret(T+1);
	REP(w, T) {
	    int n;
	    cin >> n;
	    string s;
	    cin >> s;
	    REP(i, s.length()) {
	        if (s[i] == 'E')
	            ret[w+1] += "S";
	        else
	            ret[w+1] += "E";
	    }
	}
	
	FOR(i, 1, T) {
	    cout << "Case #" << i << ": ";
	    cout << ret[i] << n1;
	}

    return 0;
}