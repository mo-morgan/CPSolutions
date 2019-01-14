/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <utility>
#include <vector>
#include <climits>
#include <queue>
#include <functional>

using namespace std;


#define INF LONG_MAX
typedef long int li;
typedef pair<long int, long int> pairli;

// This function returns true if the first pair is "less"
// than the second one according to some metric
// In this case, we say the first pair is "less" if the second element of the first pair
// is less than the second element of the second pair
bool pairCompare(const pair<int, int>& firstElem, const pair<int, int>& secondElem) {
    return firstElem.second < secondElem.second;
}

int main()
{
    // fast io
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int V, E;
    cin >> V >> E;
    int source;
    cin >> source;
    // vector<pair<li, li>> graph(V + 1);
    vector<vector<pair<li, li>>> graph(V + 1);
    
    // constructing graph
    for (int i = 1; i <= E; i++) {
        li from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back(make_pair(to, weight));
        graph[to].push_back(make_pair(from, weight));
    }
    
    // dijkstra's
    priority_queue<pairli, vector<pairli>, greater<pairli>> pq;
    vector<li> dist(V + 1, INF);
    
    pq.push(make_pair(0, source));
    dist[source] = 0;
    
    while(!pq.empty()) {
        li u = pq.top().second;
        pq.pop();
        
        for (int i = 0; i < graph[u].size(); i++) {
            pair<li, li> p = graph[u][i];
            
            li v = p.first;
            li w = p.second;
            
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    
    // print out all of the shortest path
    if (dist[1] == INF) {
        dist[1] = -1;
    }
    cout << dist[1];
    for (int i = 2; i < V + 1; i++) {
        if (dist[i] == INF) {
            dist[i] = -1;
        }
        
        cout << " " << dist[i];
    }
    
    return 0;
}
