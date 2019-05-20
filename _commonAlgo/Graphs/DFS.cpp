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