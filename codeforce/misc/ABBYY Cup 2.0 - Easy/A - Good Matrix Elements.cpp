/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int back = n - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cur;
            cin >> cur;
            if (i == j) {
                sum += cur;
            } else if (i == n/2) {
                sum += cur;
            } else if (j == n/2) {
                sum += cur;
            } else if (j == back) {
                sum += cur;
            }
        }
        back--;
    }
    cout << sum << endl;
    return 0;
}
