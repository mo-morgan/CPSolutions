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
    int n;
    cin >> n;
    vector<int> arr(n);
    REP(i, n) cin >> arr[i];
    string s;
    cin >> s;
    vector<pii> lrs;
    int numsorts = 0;
    REP(i, s.length()) {
        int l = i, r = i;
        if (s[i] == '0') continue;
        while (s[i] == '1') {
            r = ++i;
        }
        numsorts++;
        lrs.push_back(make_pair(l, r));
    }
    
    REP(i, numsorts) {
        sort(arr.begin()+lrs[i].first, arr.begin()+lrs[i].second+1);
    }
    if (is_sorted(arr.begin(), arr.end())) {
        cout << "YES" << n1;
    } else  {
        cout << "NO" << n1;
    }
    return 0;
}
