#include <bits/stdc++.h>
using namespace std;
#define EPS                 0.00000001
#define LL_MAX              1e18
#define LL_MIN              -1e18
#define MAX                 0x3f3f3f3f
#define MIN                 -0x3f3f3f3f
#define MOD                 1000000007
#define DEBUG(x)            cout << '>' << #x << ':' << x << endl;
#define REP(i,n)            for(int i=0;i<(n);i++)
#define FOR(i,a,b)          for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)         for(int i=(a);i>=(b);i--)
#define n1                  '\n'

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ld> pt;
typedef vector<pt> pol;

int T;

ll power(ll b, int e) {
    ll res = 1;
    for ( ; e>0; e/=2) {
        if (e&1) res = res*b % MOD;
        b = b*b % MOD;
    }
    return res;
}

inline void IOS() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

inline void addPrime(ll semi, set<ll> &primes) {
    ll count = 0;
    for (int i = 2; i*i <= semi; ++i) {
        if (semi % i == 0) {
            primes.insert(i);
            count++;
        }
        if (count >= 2) {
            break;
        }
    }
}

inline char findPrime(ll num, ll next, unordered_map<ll, char> map) {
    auto it = map.begin();
    ll prime1, prime2, prime3;

    while(it != map.end()) {
        if (num % it->first == 0) {
            prime1 = it->first;
            prime2 = num / prime1;
            break;
        }
    }
    it = map.begin();
    while(it != map.end()) {
        if (next % it->first == 0) {
            prime3 = it->first;
            if (prime3 % prime2 == 0) {
                return map.at(prime2);
            } else if (prime3 % prime1 == 0) {
                return map.at(prime1);
            } else {
                return map.at(prime3);
            }
            break;
        }
    }
    return 'A';
}

int main()
{
    IOS();
    cin >> T;
    vector<string> ret(T+1);
    REP(i, T) {
        unordered_map<ll, char> map;
        set<ll> primes;
        vector<ll> nums;
        ll n, l;
        cin >> n >> l;
        REP(j, l) {
            ll semi;
            cin >> semi;
            nums.push_back(semi);
            // find all the primes first, and then compair each pair
            addPrime(semi, primes);
        }
        sort(primes.begin(), primes.end());
        REP(j, primes.size()) {
            auto it = primes.find(j);
            char kk = (char) j + 'A';
            map.insert({*it, kk});
        }
        // compair each adjacent pair and decrypt the values
        REP(j, l-1) {
            ret[i+1] += findPrime(nums[j], nums[j+1], map);
        }
    }

    FOR(i, 1, T) {
        cout << "Case #" << i << ": ";
        cout << ret[i] << n1;
    }
    return 0;
}
