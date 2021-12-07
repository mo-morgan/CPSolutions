#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
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
#define nl 					'\n'
#define PRINT(n)			cout << (n) << n1;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ld> pt;
typedef vector<pt> pol;

int main()
{
	desync
    ll hor = 0;
    ll ver = 0;
    while(getline(cin, line)) {
        boost::split(strs, line, boost::is_any_of("\t "));
        ll dist = boost::lexical_cast<ll>(strs[1]);
        if (strs[0] == "forward") {
            hor += dist;
        } else if (strs[0] == "down") {
            ver += dist;
        } else {
            ver -= dist;
        }
    }
    cout << hor * ver << endl;
    return 0;
}
