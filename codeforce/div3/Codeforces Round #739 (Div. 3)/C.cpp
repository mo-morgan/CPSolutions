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

ll perf[100010];

int main()
{
	desync
    // create perfect squares
    for (int i = 0; i < 100000; i++) {
        perf[i] = i*i;
    }
    int t;
    cin >> t;
    REP(i, t) {
        ll a;
        cin >> a;
        int ind = 0;
        for (int i = 0; i < 100000; i++) {
            if (a <= perf[i]) {
                ind = i - 1;
                break;
            }
        }
        int lenStrip = perf[ind+1] - perf[ind];
        int dist = a - perf[ind];
        int middle = ind + 1;
        if (dist > middle) {
            // bottom left
            cout << ind + 1 << " " << middle - ((dist - middle))  << nl;
        } else {
            // top right
            cout << dist << " " << ind + 1 << nl;
        }
    }

    return 0;
}
