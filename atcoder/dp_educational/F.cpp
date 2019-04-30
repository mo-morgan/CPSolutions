#include <bits/stdc++.h>
using namespace std;
#define desync              ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define EPS                 0.00000001
#define LL_MAX              1e18
#define LL_MIN              -1e18
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

string LCS(string s, string t) {
    // construct the substring length matrix
    int n = s.length(), m = t.length();
    int mat[n+1][m+1];
    REP(i, n+1) {
        REP(j, m+1) {
            if (i == 0 || j == 0) mat[i][j] = 0;
            else if (s[i-1] == t[j-1]) mat[i][j] = 1 + mat[i-1][j-1];
            else mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
        }
    }
    int i = n, j = m;
    string ret = "";
    while(i > 0 && j > 0) {
        if (s[i-1] == t[j-1]) {
            ret.insert(0, 1, s[i-1]);
            i--;j--;
        } else if (mat[i][j] == mat[i-1][j]) i--;
        else j--;
    }
    return ret;
}

int main()
{
    desync
    string s, t;
    cin >> s >> t;
    cout << LCS(s, t) << n1;
    return 0;
}
