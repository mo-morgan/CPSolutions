	void addEdge(vector<int> adj[], int u, int v) 
    { 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    } 
    
    bool isBipartite(vector<int> adj[], int v, 
                 vector<bool>& visited, vector<int>& color) 
    { 

        for (int u : adj[v]) { 

            // if vertex u is not explored before 
            if (visited[u] == false) { 

                // mark present vertic as visited 
                visited[u] = true; 

                // mark its color opposite to its parent 
                color[u] = !color[v]; 

                // if the subtree rooted at vertex v is not bipartite 
                if (!isBipartite(adj, u, visited, color)) 
                    return false; 
            } 

            // if two adjacent are colored with same color then 
            // the graph is not bipartite 
            else if (color[u] == color[v]) 
                return false; 
        } 
        return true; 
    } 
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> adj[N + 1]; 
        
        // to keep a check on whether 
        // a node is discovered or not 
        vector<bool> visited(N + 1); 
        
        // to color the vertices 
        // of graph with 2 color 
        vector<int> color(N + 1); 
        
        for (int i = 0; i < dislikes.size(); i++) {
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            addEdge(adj, u, v);
        }
        
        visited[1] = true;
        // marking the source node with a color 
        color[1] = 0; 

        for (int i = 1; i <= N; i++) {
            if (!isBipartite(adj, i, visited, color)) {
                return false;
             }     
        }
            
        return true;
    }