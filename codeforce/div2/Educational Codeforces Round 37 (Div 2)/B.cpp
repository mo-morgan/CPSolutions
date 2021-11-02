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
    int t;
    cin >> t;
    vector<vector<int>> ret(t);
    REP(i, t) {
        int n;
        cin >> n;
        queue<int> students;
        vector<pii> ls, rs;
        REP(j, n) {
            int l, r;
            cin >> l >> r;
            ls.push_back(make_pair(l, j+1));
            rs.push_back(make_pair(r, j+1));
        }
        sort(ls.begin(), ls.end());
        REP(j, n) {
            students.push(ls[j].second);
        }
        int time = 1;
        vector<int> arr;
        while(!students.empty()) {
            int curr = students.front();
            students.pop();
            if (rs[curr-1].first >= time) {
                arr.push_back(time);
                time++;
            } else {
                arr.push_back(0);
            }
        }
        ret[i] = arr;
    }

    REP(i, t) {
        REP(j, ret[i].size()) {
            cout << ret[i][j] << " ";
        }
        cout << n1;
    }
    return 0;
}
