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
string toBinary(int n)
{
        string r;
        while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
        return r;
}
ll power(ll b, int e) {
	ll res = 1;
	for ( ; e>0; e/=2) {
		if (e&1) res = res*b % MOD;
		b = b*b % MOD;
	}
	return res;
}

int main()
{
	desync
    int n;
    cin >> n;
    string bin = toBinary(n);
    int curr = 1;
    unordered_map<int, int> m;
    REP(i, 32) {
        m[i] = i+1;
    }
    vector<int> res;
    int j = 0;
    FORD(i, bin.size()-1, 0) {
        if (bin[i] == '1') {
            res.push_back(m[j]);
        }
        j++;
    }
    FORD(i, res.size()-1, 0) {
        cout << res[i];
        if (i == 0) cout << n1;
        else cout << " ";
    }
    return 0;
}
