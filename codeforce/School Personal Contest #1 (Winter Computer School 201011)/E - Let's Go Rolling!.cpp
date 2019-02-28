#include <bits/stdc++.h>

using namespace std;

long long cost[4010];
long long ret[4010];

int main()
{
    int n;
    cin >> n;
    
	vector<pair<long long, long long>> graph(n);

    for (int i = 0; i < n; i++) {
        long long k, c;
        cin >> k >> c;
        graph[i] = make_pair(k, c);
    }
    sort(graph.begin(), graph.end());

    
    cost[0] = graph[0].second;
    ret[0] = graph[0].second;

    for (int i = 1; i < n; i++) {
        
        long long curr = 0;
        int k = 1;
        cost[i] = graph[i].second + ret[i-1];
        ret[i] = cost[i];
        
        for (int j = i - 1; j >= 0; j--) {
            curr += (graph[j+1].first - graph[j].first) *k;
            k++;
            ret[i] = min(ret[i], curr + cost[j]);
        }
    }
    
    cout << ret[n-1] << endl;
    
    return 0;
}