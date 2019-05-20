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
#define TESTFILE "tour"

int main()
{
	desync
#ifdef ONLINE_JUDGE
    freopen(TESTFILE ".in", "r", stdin);
#endif
    int t;
    cin >> t;
    REP(i, t) {
        int n;
        cin >> n;
        vector<int> h(n+1);
        int most = -1, mosti = -1;
        REP(j, n) { 
            cin >> h[j+1];
            if (h[j+1] > most) {
                most = h[j+1];
                mosti = j+1;
            }
        }
        stack<pii> s;
        s.push({1, h[1]});
        vector<vector<int>> graph(n+1);
        FOR(j, 2, n) {
            if (s.top().second > h[j]) {
                graph[j].push_back(s.top().first);
                graph[s.top().first].push_back(j);
                s.push({j, h[j]});
            } else {
                while (!s.empty() && s.top().second < h[j]) {
                    pii u = s.top();
                    s.pop();
                    graph[u.first].push_back(j);
                    graph[j].push_back(u.first);
                }
                s.push({j, h[j]});
            }
        }

        queue<int> bfs;
        vector<int> color(n+1, 0);
        bfs.push(mosti);
        int count = 0;
        while(!bfs.empty()) {
            int u = bfs.front();
            bfs.pop();
            unordered_set<int> used;
            used.insert(0);
            for (int k = 0; k < graph[u].size(); k++) {
                used.insert(color[graph[u][k]]);
                if (color[graph[u][k]] == 0) {
                    bfs.push(graph[u][k]);
                }
            }
            if (used.find(1) == used.end()) {
                color[u] = 1;
                used.insert(1);
            }
            else if (used.find(2) == used.end()) {
                color[u] = 2;
                used.insert(2);
            }
            else {
                color[u] = 3;
                used.insert(3);
            }
            count = (count > used.size() - 1 ? count : used.size() - 1);
        }
        cout << count << n1;
        REP(j, n) {
            cout << color[j+1] << " ";
        }
    }
    return 0;
}
