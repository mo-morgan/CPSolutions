#include <bits/stdc++.h>
using namespace std;
#define desync              ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define EPS                 0.00000001
#define LL_MAX              0x3f3f3f3f3f3f3f3f
#define LL_MIN              -0x3f3f3f3f3f3f3f3f
#define MAX                 0x3f3f3f3f
#define MIN                 -0x3f3f3f3f
#define MOD                 1000000007
#define DEBUG(x)            cout << '>' << #x << ':' << x << endl;
#define REP(i,n)            for(int i=0;i<(n);i++)
#define FOR(i,a,b)          for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)         for(int i=(a);i>=(b);i--)
#define n1                  '\n'

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

int main()
{
    desync
    int q, m, s, l;
    cin >> q >> m >> s >> l;
    int fill = l/m;
    int leftover = l%m;
    ll shor = fill*q;
    ll tall = (fill+1)*q;
    ll remain;
    if (leftover == 0) {
        remain = 0;
        tall = shor;
    } else {
        remain = (m-leftover)*q;
    }
    s -= remain;
    if (s <= 0) {
        cout << tall << n1;
        return 0;
    }
    fill = s/m;
    leftover = s%m;
    if (leftover == 0) {
        cout << fill + tall << n1;
    } else {
        cout << fill+1+tall << n1;
    }
    return 0;
}
