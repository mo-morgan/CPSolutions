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

inline void IOS() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	IOS();
	
	int n, IDX;
	cin >> n >> IDX;
	
	int sum = 6;
	
	if (n == 2) {
	    cout << 6 << endl;
	    return 0;
	}
	
	int cur = IDX;
	
	if (IDX == 1 || IDX == n) {
	    sum -= 3;
	}
	
	if (IDX < n / 2 + 1) { // left side
	    while(cur - 1 > 1) {
	        sum += 3;
	        cur--;
	    }
	    sum += IDX - 1;
	    sum += (n - IDX)*3;
	} else { //right side
	    while(cur + 1 < n) {
	        sum += 3;
	        cur++;
	    }
	    sum += n - IDX;
	    sum += (IDX - 1) * 3;
	}
	
    cout << sum << endl; 

    return 0;
}