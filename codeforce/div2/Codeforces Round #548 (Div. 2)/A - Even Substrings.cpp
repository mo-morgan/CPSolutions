
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

void subString(string s, int n)  
{ 
    int ret = 0;
    for (int i = 0; i < n; i++)  {
        if (s.at(i) % 2 == 0) {
            ret += i + 1;
        }
    }
    cout << ret << endl;
} 

int main()
{
	IOS();
	int n;
	cin >> n;
	string s;
	cin >> s;
	subString(s, n);
    return 0;
}