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
	int n, m;
	cin >> n >> m;
	int k = m%n;
	if (k != 0) {
	    cout << -1 << endl;
	    return 0;
	}
	
	k = m / n;
	
	int ret = 0;
	while(1) {
	    if (k <= 1) {
	        cout << ret << endl;
	        return 0;
	    }
	    if (k % 2 == 0) {
	        k/=2;
	        ret++;
	    } else if (k%3==0) {
	        k/=3;
	        ret++;
	    } else {
	        cout << -1 << endl;
	        return 0;
	    }
	}
	cout << ret << endl;
    return 0;
}