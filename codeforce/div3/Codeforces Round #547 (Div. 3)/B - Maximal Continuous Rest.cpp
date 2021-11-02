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
	int max = 0;
	int cur = 0;
	vector<int> hours(3*n);
	for (int i = n; i < 2*n; i++) {
	    cin >> hours[i];
	}
	for (int i = 0; i < n; i++) {
	    hours[i] = hours[i+n];
	}
	
	for (int i = 2*n; i < 3*n; i++) {
	    hours[i] = hours[i-n];
	}
	
	for (int i = 0; i < 3*n; i++) {
	    if (hours[i]==1) {
	        cur++;
	    } else {
	        if (max < cur) {
	            max = cur;
	        }
	        cur = 0;
	        continue;
	    }
	}
	if (max < cur) {
	    max = cur;
	}

    cout << max << endl;
    return 0;
}