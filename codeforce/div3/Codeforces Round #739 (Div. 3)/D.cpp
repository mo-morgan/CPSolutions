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

ll lookup[100];

ll Hamm(string s, string ans) {
    ll dist = 0;
    ll n = s.length();
    ll m = ans.length();
    ll i = 0, j = 0;
    while(i < n && j < m) {
        if (s[i] != ans[j]) {
            dist++;
            i++;
        } else {
            i++; j++;
        }
    }
    dist += m - j + (n - i);
    return dist;
}

int main()
{
	desync
    for (int i = 0; i < 100; i++) {
        lookup[i] = pow(2, i);
    }
    int t;
    cin >> t;
    REP(i, t) {
        string n;
        cin >> n;
        ll dist = MAX;
        for (int i = 0; i < 100; i++) {
            ll k = Hamm(n, to_string(lookup[i]));
            dist = (k < dist ? k : dist);
        }

        cout << dist << nl;
    }
    return 0;
}