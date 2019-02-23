/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

long long ret[510];

int main()
{
    int q;
    cin >> q;
    
    long long n, a, b;
    for (int i = 0; i < q; i++) {
        cin >> n >> a >> b;
        if (2*a <= b || n < 2) {
            ret[i] = n * a;
        } else {
                // ret[i] = (n / b) * b;
                // ret[i] += (n - ret[i]) * a;
            ret[i] = ((n % 2) * a) + ((n / 2) *b);
        }
    }
    
    for (int i = 0 ; i < q; i++) {
        cout << ret[i] << endl;
    }
    
    
    return 0;
}