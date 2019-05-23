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
#define n1 					'\n'

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ld> pt;
typedef vector<pt> pol;

int n;

ll power(ll b, int e) {
	ll res = 1;
	for ( ; e>0; e/=2) {
		if (e&1) res = res*b % MOD;
		b = b*b % MOD;
	}
	return res;
}

bool collinear(pll a, pll b) {
	return a.first * b.second == a.second * b.first;
}

bool collinear(pll a, pll b, pll c) {
	return collinear(
		pll(b.first - a.first, b.second - a.second),
		pll(c.first - a.first, c.second - a.second)
	);
}

int main()
{
	desync
    cin >> n;
    vector<pair<pll, int>> pts(n);
    REP(i, n) {
        cin >> pts[i].first.first >> pts[i].first.second;
        pts[i].second = i+1;
    }
    sort(pts.begin(), pts.end());
	FOR(i, 2, n-1) {
		pll a = pts[i-2].first;
        pll b = pts[i-1].first;
        pll c = pts[i].first;

        if (!collinear(a, b, c)) {
            cout << pts[i-2].second << " " << pts[i-1].second << " "
            << pts[i].second << n1;
            break;
        }
	}

    return 0;
}
