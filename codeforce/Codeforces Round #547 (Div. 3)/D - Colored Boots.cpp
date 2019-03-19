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
typedef complex<double> pt;

inline void IOS() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	IOS();
	int n;
	cin >> n;
	vector<pll> sf(n);
	vector<pll> ss(n);
	string s1, s2;
	cin >> s1 >> s2;
	REP(i, n) {
	    if (s1[i] == 63) {
	        pll k = make_pair(150, i);
	        sf[i] = k;
	        continue;
	    }
	    pll k = make_pair(s1[i], i);
	    sf[i] = k;
	}
	
	REP(i, n) {
	    if (s2[i] == 63) {
	        pll k = make_pair(150, i);
	        ss[i] = k;
	        continue;
	    }
	    pll k = make_pair(s2[i], i);
	    ss[i] = k;
	}
	
	sort(sf.begin(), sf.end());
	sort(ss.begin(), ss.end());
	
	ll first = 0, second = 0;
	vector<pll> ind;
	ll countQ1 = 0, countQ2 = 0;
	int tot = n;
	
	vector<int> used1(n, 0);
	vector<int> used2(n, 0);
	
    ll q1 = -1, q2 = -1;
	REP(i, n) {
	    if (i >= n) {
	        break;
	    } 
	    
	    if (sf[i].first == 150) {
	        q1 = i;
	        break;
	    }
	}
	REP(i, n) {
	    if (i >= n) {
	        break;
	    } 
	    
	    if (ss[i].first == 150) {
	        q2 = i;
	        break;
	    }
	}
	
	while(1) {
	    if (first >= n || second >= n) {
	        break;
	    }
	    
	    if (sf[first].first == 150 || ss[second].first == 150) {
	        break;
	    }
	    
	    if (sf[first].first == ss[second].first) {
	        pll p = make_pair(sf[first].second, ss[second].second);
	        ind.push_back(p);
	        tot--;
	        used1[first] = 1;
	        used2[second] = 1;
	        first++;
	        second++;
	    } else if (sf[first].first > ss[second].first) {
	        second++;
	    } else if (sf[first].first < ss[second].first) {
	        first++;
	    }
	}
	
	first = q1, second = 0;
	if (q1 != -1) {
	    while(1) {
	        if (first >= n || second >= n) {
    	        break;
	        }   
	    
    	    if (sf[first].first == 150 && used2[second] == 0 && used1[first] == 0) {
    	        pll p = make_pair(sf[first].second, ss[second].second);
    	        ind.push_back(p);
    	        tot--;
    	        used1[first] = 1;
    	        used2[second] = 1;
    	        first++;
    	        second++;
    	    } else if (used2[second] != 0 && used1[first] != 0) {
    	        first++;
    	        second++;
    	    } else if (used2[second] != 0) {
    	        second++;
    	    } else {
    	        first++;
    	    }
	    }
	}

	first = 0, second = q2;
	if (q2 != -1) {
	    while(1) {
	        if (first >= n || second >= n) {
    	        break;
	        }   
	    
    	    if (ss[second].first == 150 && used2[second] == 0 && used1[first] == 0) {
    	        pll p = make_pair(sf[first].second, ss[second].second);
    	        ind.push_back(p);
    	        tot--;
    	        used1[first] = 1;
    	        used2[second] = 1;
    	        first++;
    	        second++;
    	    } else if (used2[second] != 0 && used1[first] != 0) {
    	        first++;
    	        second++;
    	    } else if (used2[second] != 0) {
    	        second++;
    	    } else {
    	        first++;
    	    }
	    }
	}
	
	cout << n - tot << endl;
	
	REP(i, ind.size()) {
	    cout << (ind[i].first)+1 << " " << (ind[i].second)+1 << endl;
	}

    return 0;
}