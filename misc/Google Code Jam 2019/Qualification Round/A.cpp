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
#define n1 					'\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pt;

ll power(ll b, int e) {
	ll res = 1;
	for ( ; e>0; e/=2) {
		if (e&1) res = res*b % MOD;
		b = b*b % MOD;
	}
	return res;
}

unsigned GetNumberOfDigits (unsigned i)
{
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

void pickDigits(int * arr, int d, int length, int i,
    vector<vector<int>> &ret, vector<vector<int>> &fed) 
{ 
    // // Breal loop if d is present as digit
    vector<int> rowRet;
    vector<int> rowFed;
    bool leadingZero = true;
    REP(j, length) {
        if (arr[j] == 4) {
            rowRet.push_back(1);
            rowFed.push_back(3);
            leadingZero = false;
        } else {
            if (!leadingZero) {
                rowRet.push_back(0);
            }
            rowFed.push_back(arr[j]);
        }
    }
    ret[i] = rowRet;
    fed[i] = rowFed;
}


inline void IOS() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	IOS();
	int T;
	cin >> T;
	vector<vector<int>> ret(T+1);
	vector<vector<int>> fed(T+1);
	
	REP(i, T) {
	    string k;
	    cin >> k;
	    const char* cstr = k.c_str();
        int len = k.length();
        int* intArray = new int[len];
        
        int j;
        for (j=0; j < len; j++) {
            intArray[j] = cstr[j] - '0';
        }
            
        

	    pickDigits(intArray, 4, len, i+1, ret, fed);
	    delete[] intArray;
	}
	
	FOR(i, 1, T) {
	    cout << "Case #" << i << ": ";
	    REP(j, ret[i].size()) {
	        cout << ret[i][j];
	    }
	    cout << " ";
	    REP(j, fed[i].size()) {
	        cout << fed[i][j];
	    }
	    cout << n1;
	}

    return 0;
}