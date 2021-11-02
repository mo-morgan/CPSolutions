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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pt;

inline void IOS() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	IOS();
	int n;
	cin >> n;
	vector<ll> xs(n);
	vector<ll> dp(n);
	REP(i, n) {
	    cin >> xs[i];
	}
	ll ret = xs[n-1];
	dp[n-1] = ret;
	
    FORD(i, n-2, 0) {
	    if (xs[i] < dp[i+1]) {
	        ret += xs[i];
	        dp[i] = xs[i];
	    } else if (dp[i+1] - 1 <= 0) {
	        dp[i] = 0;
	        break;
	    } else {
	        ret += dp[i+1] - 1;
	        dp[i] = dp[i+1] - 1;
	    }
	}
	
	cout << ret << endl;
    return 0;
}