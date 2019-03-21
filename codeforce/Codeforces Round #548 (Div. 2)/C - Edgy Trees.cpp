#include <bits/stdc++.h>
using namespace std;
#define EPS                 0.00000001
#define MAX                 1e18
#define MIN                    -1e18
#define MOD                    1000000007
#define DEBUG(x)             cout << '>' << #x << ':' << x << endl;
#define REP(i,n)             for(int i=0;i<(n);i++)
#define FOR(i,a,b)             for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)         for(int i=(a);i>=(b);i--)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pt;

inline void IOS() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int n, k;

ll power(ll i, ll v) {
    ll k = i;
    for (int j = 0; j < v-1; j++) {
        i *= k;
        i %= MOD;
    }
    return i;
}

ll DFS(vector<vector<pair<ll, ll>>> graph, int n) 
{ 
    ll ret = 0;
    ll cur = 0;
    vector<bool> visited(n+1, false);
    for (int j = 1; j <= n; j++) {
        stack<ll> stack; 
      
        stack.push(j); 
        while (!stack.empty()) 
        { 
            int s = stack.top(); 
            stack.pop(); 
      
            if (!visited[s]) 
            { 
                cur++;
                visited[s] = true; 
            } 
            
            for (ll i = 0; i < graph[s].size(); i++) {
                if (!visited[graph[s][i].first] && graph[s][i].second == 0) {
                    stack.push(graph[s][i].first);
                }
            }
        }
        
        ret += power(cur, k);
        ret %= MOD;
        cur = 0;
    }
    
    return ret;
} 

int main()
{
    IOS();
    cin >> n >> k;
    ll sol = power(n, k) % MOD;
    vector<vector<pair<ll, ll>>> g(n+1);
    REP(i, n-1) {
        int u, v, b;
        cin >> u >> v >> b;
        pair<ll, ll> pp = make_pair(v, b);
        pair<ll, ll> kk = make_pair(u, b);
        g[u].push_back(pp);
        g[v].push_back(kk);
    }
    
    ll ret = DFS(g, n);
    
    cout <<  ((sol - ret) % MOD + MOD) % MOD << endl;
    return 0;
}