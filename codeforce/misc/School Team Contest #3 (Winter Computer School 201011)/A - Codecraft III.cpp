/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

string calendar[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main()
{
    string m;
    cin >> m;
    int n;
    cin >> n;
    
    int c;
    for (int i = 0; i < 12; i++) {
        if (calendar[i] == m) {
            c = i;
        }
    }
    
    int mod = n % 12;
    c += mod;
    c %= 12;
    cout << calendar[c] << endl;

    return 0;
}
