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
    
    vector<string> a(n);
    vector<bool> b(n, false);
    b[n-1] = true;
    
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for (int i = n-1; i >= 1; i--) {
        if (a[i] == "TRUTH" && b[i]) {
            b[i-1] = true;
        } else if (a[i] == "TRUTH") {
            b[i-1] = false;
        } else if (a[i] == "LIE" && b[i]) {
            b[i-1] = false;
        } else {
            b[i-1] = true;
        }
    }
    
    if (a[0] == "TRUTH" && b[0] == true) {
        cout << "TRUTH" << endl;
    } else if (a[0] == "TRUTH") {
        cout << "LIE" << endl;
    } else if (a[0] == "LIE" && b[0] == true) {
        cout << "LIE" << endl;
    } else {
        cout << "TRUTH" << endl;
    }
    
    return 0;
}
