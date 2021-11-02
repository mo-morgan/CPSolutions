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
#define nl 					'\n'
#define PRINT(n)			cout << (n) << n1;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ld> pt;
typedef vector<pt> pol;

int ks[1010];

int main()
{
	desync
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> ks[i];
    }
    vector<int> polyn;
    polyn.push_back(1);

    for (int i = 1; i < 2000; i++) {
        if (i % 3 == 0 || to_string(i).back() == '3') {
            continue;
        }
        polyn.push_back(i);
    }
    for (int i = 0; i < t; i++) {
        cout << polyn[ks[i]] << nl;
    }
    
    return 0;
}
