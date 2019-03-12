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

int n;

int main()
{
	IOS();
	
	cin >> n;
	vector<int> pg(n+1);
    REP(i, n) {
        int beg, end;
        cin >> beg >> end;
        
        pg[i+1] = end;
    }
    int k;
    cin >> k;
    
    int count = 0;
    REP(i, n) {
        if (pg[i+1] >= k) {
            cout << n-count << endl;
            return 0;
        }
        count++;
    }
    
    cout << 0 << endl;
    
    
    return 0;
}