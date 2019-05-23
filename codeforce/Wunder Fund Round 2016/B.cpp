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

ll power(ll b, int e) {
	ll res = 1;
	for ( ; e>0; e/=2) {
		if (e&1) res = res*b % MOD;
		b = b*b % MOD;
	}
	return res;
}

struct S{
    int a, b;
    bool operator <(const S &p) const {
        return a<p.a;
    }
}P[60];

int main()
{
	desync
    int n;
    cin >> n;
    vector<vector<int>> A(n+1, vector<int>(n+1));
    int weight[55];
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cin >> A[i][j];
            if (weight[i] < A[i][j]) weight[i] = A[i][j];
        }
		P[i].b = i;
        P[i].a = weight[i];
    }
    sort(P+1, P+n+1);
    vector<int> ret(n+1);
    FOR(i, 1, n) {
        ret[P[i].b] = i;
    }
    FOR(i, 1, n) {
        cout << ret[i] << " ";
    }
    return 0;
}
