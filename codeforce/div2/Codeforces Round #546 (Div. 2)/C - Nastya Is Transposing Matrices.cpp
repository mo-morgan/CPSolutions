#include <bits/stdc++.h>
using namespace std;
#define EPS 				0.00000001
#define MAX 				1e18
#define MIN					-1e18
#define MOD					1000000007
#define DEBUG(x) 			cout << '>' << #x << ':' << x << endl;
#define REP(i,n) 			for(int i=0;i<(n);i++)
#define FOR(i,a,b) 			for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) 		for(int i=(a);i>=(b);i--)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void IOS() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	IOS();
	int n, m;
	cin >> n >> m;
	
	int k = max(n, m);
	// pad with zeroes?
	vector<vector<int>> matA;
	vector<vector<int>> diagA;
	vector<vector<int>> matB;
	vector<vector<int>> diagB;

    bool nGreater = true;
    if (n < m) {
        nGreater = false;
    }

    if (nGreater) {
        // more rows than columns
	    vector<int> inner(k);
	    vector<int> innerB(k);
    	FOR(i, 0, k-1) {
    	    FOR(j, 0, k-1) {
    	        if (j >= m) {
    	            inner[j] = 0;
    	        } else {
    	            cin >> inner[j];
    	        }
    	    }
    	    matA.push_back(inner);
    	}
    	
    	FOR(i, 0, k-1) {
    	    FOR(j, 0, k-1) {
    	        if (j >= m) {
    	            innerB[j] = 0;
    	        } else {
    	            cin >> innerB[j];
    	        }
    	    }
    	    matB.push_back(innerB);
    	}
    	
    } else { // more columns than rows
    	vector<int> inner(k);
    	vector<int> innerB(k);
        FOR(i, 0, k-1) {
    	    FOR(j, 0, k-1) {
    	        if (i >= n) {
    	            inner[j] = 0;
    	        } else {
    	            cin >> inner[j];
    	        }
    	    }
    	    matA.push_back(inner);
    	}
    	FOR(i, 0, k-1) {
    	    FOR(j, 0, k-1) {
    	        if (i >= n) {
    	            innerB[j] = 0;
    	        } else {
    	            cin >> innerB[j];
    	        }
    	    }
    	    matB.push_back(innerB);
    	}
    }
    
	for (int slice = 0; slice < 2 * k - 1; ++slice) {
        int z = (slice < k) ? 0 : slice - k + 1;
        vector<int> d;
        for (int j = z; j <= slice - z; ++j) {
            d.push_back(matA[j][slice-j]);
        }
        diagA.push_back(d);
    }
    
	for (int slice = 0; slice < 2 * k - 1; ++slice) {
        int z = (slice < k) ? 0 : slice - k + 1;
        vector<int> d;
        for (int j = z; j <= slice - z; ++j) {
            d.push_back(matB[j][slice-j]);
        }
        diagB.push_back(d);
    }
    
    REP(i, diagA.size()) {
        sort(diagA[i].begin(), diagA[i].end());
        sort(diagB[i].begin(), diagB[i].end());
        
        REP(j, diagA[i].size()) {
            if (diagA[i][j] != diagB[i][j]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    return 0;
}