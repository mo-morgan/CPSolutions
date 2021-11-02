#include <bits/stdc++.h>
using namespace std;
#define EPS                 0.00000001
#define MAX                 1e18
#define MIN                 -1e18
#define MOD                 1000000007
#define DEBUG(x)            cout << '>' << #x << ':' << x << endl;
#define REP(i,n)            for(int i=0;i<(n);i++)
#define FOR(i,a,b)          for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)         for(int i=(a);i>=(b);i--)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void IOS() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    // IOS();
    int n;
    cin >> n;
    vector<int> qs(n);
    vector<int> pre(n+1);
    for (int i = 1; i < n; i++) {
        cin >> qs[i];
        pre[i+1] += qs[i] + pre[i];
    }

    int max = -1e9;
    int ind = -1;
    FOR(i, 1, n) {
        if (max < pre[i]) {
            ind = i;
            max = pre[i];
        } 
    }

    vector<int> ret(n+1);
    int j = ind;
    ret[ind] = n;
    while(ind < n) {
        ret[ind+1] = ret[ind] + qs[ind];
        ind++;
    }
    while(j > 1) {
        ret[j-1] = ret[j] - qs[j-1];
        j--;
    }
    
    vector<int> ss(n+1);
    FOR(i, 1, n) {
        ss[i] = i;
    }
    
    vector<int> sum(n+1);
    
    FOR(i, 1, n) {
        if (ret[i] < 1 || ret[i] > n) {
            cout << -1 << endl;
            return 0;
        }
        sum[i] = ret[i];
    }
    
    sort(sum.begin(), sum.end());
    FOR(i, 1, n) {
        if (sum[i] != ss[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    FOR(i, 1, n) {
        cout << ret[i] << " ";
    }
    return 0;
}