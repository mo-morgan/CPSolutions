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

int a[10010], b[10010], c[10010];

int main()
{
	desync
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    for (int i = 0; i < t; i++) {
        int as = a[i], bs = b[i], cs = c[i];
        if (as > bs) swap(as, bs);
        int k = bs - as;
        if (bs > 2*k || cs > 2*k) {
            cout << -1 << nl;
        }
        else if (cs > k) {
            cout << cs - k << nl;
        } else {
            cout << cs + k << nl;
        }
    }

    return 0;
}
