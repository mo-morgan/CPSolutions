#include <bits/stdc++.h>
using namespace std;
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

inline void IOS() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

namespace short_dynamic_hull {
//*/
// WARNING: could overflow for values ~1e9, use __int128 instead
// WARNING: tested only with integer and rational types
const ll is_query = -(1LL<<62);
struct Line {
  ll m, b;
  mutable function<const Line*()> succ;
  bool operator<(const Line& rhs) const {
    if (rhs.b != is_query) return m < rhs.m;
    const Line* s = succ();
    if (!s) return 0;
    ll x = rhs.m;
    return b - s->b < (s->m - m) * x;
  }
};
// will maintain upper hull for maximum
struct HullDynamic : public multiset<Line> {
  bool bad(iterator y) {
    auto z = next(y);
    if (y == begin()) {
      if (z == end()) return 0;
      return y->m == z->m && y->b <= z->b;
    }
    auto x = prev(y);
    if (z == end()) return y->m == x->m && y->b <= x->b;
    // could overflow
    return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m);
  }
  void insert_line(ll m, ll b) {
    m = -m; b = -b; // for lower hull
    auto y = insert({ m, b });
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad(y)) { erase(y); return; }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
  }
  ll eval(ll x) {
    auto l = *lower_bound((Line) { x, is_query });
    //return l.m * x + l.b; 
    return -(l.m * x + l.b); // for lower hull
  }
};
}

int main()
{
    IOS();
    ll n, c;
    cin >> n >> c;
    vector<ll> arr(n);
    REP(i, n) {
        cin >> arr[i];
    }
    vector<ll> dp(n, MAX);
    short_dynamic_hull::HullDynamic hull;
    dp[0] = 0;
    ll k = c + arr[1]*arr[1];
    hull.insert_line(-2*arr[0], arr[0]*arr[0]);
    FOR(i, 1, n-1) {
        dp[i] = hull.eval(arr[i]) + c + arr[i] * arr[i];
        hull.insert_line(-2*arr[i], dp[i] + arr[i] * arr[i]);
    }
    cout << dp[n-1] << n1;   
    return 0;
}

/*
dp[i] = min j<i  dp[j] + C + hi^2 + hj^2 - 2*hi*hj
      = hi^2  +  min j<i  (dp[j] + C + hj^2) - (2*hj)*hi

i=1:  y = -2*h1 * x + (C + h1^2)
i=2:  y = -2*h2 * x + (dp[2] + C + h2^2)

*/
