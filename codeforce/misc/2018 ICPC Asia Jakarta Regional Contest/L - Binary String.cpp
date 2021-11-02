/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

#define EPS 0.0000001

using namespace std;

typedef long long ll;

ll k;

int main()
{
    cin >> k;
    string b;
    cin >> b;
    
    ll lower_b = log2(k) + EPS;
    ll upper_b = lower_b + 1;
    
    ll len = b.length();
    
    int lower = len - upper_b;
    int upper = len - lower_b;
    
    
    if ((pow(2, len) - 1) - k < EPS) {
        cout << 0 << endl;
        return 0;
    }
    
    int onesErased = 0;
    // erase all 1's until lower bound first
    for (int i = 0; i < lower; i++) {
        auto it = b.begin()+1;
        while(it!=b.end()) {
            if (*it == '1') {
                b.erase(it);
                onesErased++;
                break;
            }
            it++;
        }
    }
    
    if (onesErased < lower) {
        b.erase(b.end()-(lower-onesErased), b.end());
    }
    
    // if still greater than k, erase one more
    if (stoll(b, nullptr, 2) > k) {
        cout << upper << endl;
    } else {
        cout << lower << endl;
    }
    
    return 0;
}
