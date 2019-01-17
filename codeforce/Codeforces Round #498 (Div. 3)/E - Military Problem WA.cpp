/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <list>

using namespace std;

typedef long long ll;


vector<priority_queue<int, vector<int>, greater<int>>> graph;


void preorder(int u, int pos) {
    if (pos == 1) {
        cout << u << endl;
        cout << "RETURNED!" << endl;
        return;
    }
    
    cout << u << " " << pos << endl;
    
    for (int i = 0; i < graph[u].size(); i++) {
        int j = graph[u].top();
        graph[u].pop();
        pos--;
        preorder(j, pos);
    }
}

int printArray(int u, int pos) {
    preorder(u, pos);
}


int main()
{
    int n, q;
    cin >> n >> q;
    
    // pi is superior of i
    // Graph graph(n+1);
    
    graph.resize(n+1);
    
    
    for (int i = 2; i <= n; i++) {
        int k;
        cin >> k;
        
        graph[k].push(i);
    }
    
    for (int i = 0; i < q; i++) {
        int u, pos;
        cin >> u >> pos;
        
        printArray(u, pos);
        cout << "NEXT!" << endl;
    }

    return 0;
}
