#include <bits/stdc++.h>
using namespace std;
#define desync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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

int n, m;

ll power(ll b, int e) {
    ll res = 1;
    for ( ; e>0; e/=2) {
        if (e&1) res = res*b % MOD;
        b = b*b % MOD;
    }
    return res;
}

//void dfs(vector<vector<int>> &g, int u, vector<int> &dp, vector<int> &in,
//vector<bool> &visited, int lev) {
//    if (in[u] <= 0) visited[u] = true;
//    dp[u] = max(dp[u], lev);
//    REP(i, g[u].size()) {
//        if (!visited[g[u][i]]) {
//            in[g[u][i]]--;
//            dfs(g, g[u][i], dp, in, visited, lev+1);
//        }
//    }
//}

void dfs(vector<vector<int>> &g, int u, vector<int> &dp, vector<int> &in,
vector<bool> &visited) {
    visited[u] = true;
    REP(i, g[u].size()) {
        dp[g[u][i]] = max(dp[g[u][i]], dp[u]+1);
        in[g[u][i]]--;
        if (in[g[u][i]] == 0) dfs(g, g[u][i], dp, in, visited);
    }
}


int main()
{
    desync
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> in(n, 0);
    vector<bool> visited(n, false);
    REP(i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        in[v]++;
    }
    // dp[i] stores the longest path it takes to reach node i
    vector<int> dp(n);
    REP(i, n) {
        if (!visited[i] && in[i] == 0) dfs(graph, i, dp, in, visited);
    }
    
    cout << *max_element(begin(dp), end(dp)) << n1;

    return 0;
}
