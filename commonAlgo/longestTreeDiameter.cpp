/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

class Graph 
{ 
    int V;              // No. of vertices 
    list<int> *adj;     // Pointer to an array containing 
                        // adjacency lists 
public: 
    Graph(int V);              // Constructor 
    void addEdge(int v, int w);// function to add an edge to graph 
    int longestPathLength();  // prints longest path of the tree 
    pair<int, int> bfs(int u); // function returns maximum distant 
                               // node from u with its distance 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V + 1]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w);    // Add w to v’s list. 
    adj[w].push_back(v);    // Since the graph is undirected 
} 
  
//  method returns farthest node and its distance from node u 


pair<int, int> Graph::bfs(int u) 
{ 
    int dis[V + 1]; 
    memset(dis, -1, sizeof(dis)); 
  
    queue<int> q; 
    q.push(u); 
  
    dis[u] = 0; 
  
    while (!q.empty()) 
    { 
        int t = q.front();       
        q.pop(); 
  
        for (auto it = adj[t].begin(); it != adj[t].end(); it++) 
        { 
            int v = *it;
            // if visited, don't push
            if (dis[v] == -1) 
            { 
                q.push(v); 
  
                // make distance of v, one more 
                // than distance of t 
                dis[v] = dis[t] + 1; 
            } 
        }
    } 
  
    int maxDis = 0; 
    int nodeIdx; 
  
    //  get farthest node distance and its index 
    for (int i = 1; i < V + 1; i++) 
    { 
        if (dis[i] > maxDis) 
        { 
            maxDis = dis[i]; 
            nodeIdx = i; 
        }
    } 
    return make_pair(nodeIdx, maxDis); 
} 
  
//  method prints longest path of given tree 
int Graph::longestPathLength() 
{ 
    pair<int, int> t1, t2; 
  
    // first bfs to find one end point of 
    // longest path 
    t1 = bfs(1); 
  
    //  second bfs to find actual longest path 
    t2 = bfs(t1.first);
  
    return t2.second;
} 

// EXPLANATION:
// first we realized that this is a tree, because we have k nodes, and k-1 edges, and we know that its connected
// that means that it has to be a tree
// because it is a tree, ther is no cycle so we dont have to worry about looping back
// therefore, we can use some sort of dp structure to store each distance as we go down the tree
// so one solution is to use bfs to find one end vertex of the longest path,
// then we will run bfs on that vertex to find the other end of the longest path
// first step, we choose an arbitrary node and set that distance to be 0
// so basically we run bfs but we store the distance from our source in a dp
// the highest distance will be one end of our longest path
// then, we just run bfs on the other end and it will give us the longest distance

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int S;
    cin >> S;
    
    int sum = 0;
    
    for (int i = 0; i < S; i++) {
        int n;
        cin >> n;
        
        Graph g(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        }
        sum += g.longestPathLength();
    }
    
    cout << sum;

    return 0;
}
