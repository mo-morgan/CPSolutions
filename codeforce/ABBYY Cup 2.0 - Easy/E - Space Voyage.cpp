/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

typedef long long ll;
ll M;
ll n, c;
ll a[100005], b[100005];

using namespace std;

ll check(ll mid) {
    ll sum = 0;
	for (ll i = 1; i <= n; i++){
		if (a[i] > M / mid) return 1;
		ll day=1 + a[i] * mid / b[i];
		if (day > c || sum > c - day) return 1;
		sum += day;
	}
	if (sum > c) {
	    return 1;
	}
	if (sum == c) {
	    return 0;
	}
	if (sum < c) {
	    return -1;
	}
    
    return 0;
}

int main()
{
    M = (ll) 1e18;
    cin >> n >> c;
    
    ll ret = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    for (ll i = 1; i <=n; i++) {
        if (a[i] != 0) {
            ret = (ll) -1e9;
        } else {
            ret += 1;
        }
    }
    
    if (ret == c) {
        cout << -1 << endl;
        return 0;
    }
    
    ll lo = 0, hi = M, mid;
    while(lo < hi) {
        mid = (lo + hi) / 2;
        if (lo == mid) {
            mid++;
        }
        
        ll j = check(mid);
        if (j < 0) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    
    ll Low, High;
    
    Low = lo;
    lo = 0, hi = M;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (lo == mid) {
            mid++;
        }
        ll j = check(mid);
        if (j <= 0) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    
    High = hi;
    
    cout << High - Low << endl;
    
    return 0;
}
