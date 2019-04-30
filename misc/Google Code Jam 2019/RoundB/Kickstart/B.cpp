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
    int T; cin >> T;
    vector<int> ret(T+1);
    REP(w, T) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        multiset<int> mul;
        REP(i, n) {
            cin >> a[i];
            mul.insert(a[i]);
        }
        int max = -1;
        int left = 0, right = n-1;
        while(1) {
            if (left > right) break;
            int count = 0;
            FOR(i, left, right) {
                if (mul.count(a[i]) <= s) count++;
            }
            auto it1 = mul.find(a[left]);
            auto it2 = mul.find(a[right]);
            if (count > max) {
                max = count;
            }
            if (a[left] == a[right] && mul.count(a[left]) > s) {
                left++;
                if (it1 != mul.end()) mul.erase(it1);
                continue;
            }
            if (mul.count(a[left]) > s && mul.count(a[right]) > s) {
                left++;
                right--;
                if (it1 != mul.end()) mul.erase(it1);
                if (it2 != mul.end()) mul.erase(it2);
                continue;
            }
            if (mul.count(a[left] > s)) {
                left++;
                if (it1 != mul.end()) mul.erase(it1);
                continue;
            }
            if (mul.count(a[right] > s)) {
                right--;
                if (it2 != mul.end()) mul.erase(it2);
                continue;
            }
            left++;
            if (it1 != mul.end()) mul.erase(it1);
        }
        ret[w+1] = max;
    }
    FOR(i, 1, T) {
        cout << "Case #" << i << ": " << ret[i];
        cout << n1;
    }
    return 0;
}
