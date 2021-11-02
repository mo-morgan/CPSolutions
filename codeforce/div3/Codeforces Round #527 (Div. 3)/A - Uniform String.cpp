/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<int> a(T);
    vector<int> b(T);
    for (int i = 0; i < T; i++) {
        cin >> a[i] >> b[i];
    }
    
    string res;
    for (int i = 0; i < T; i++) {
        res = "";
        int acc = 0;
        for (int j = 0; j < a[i]; j++) {
            if (acc == b[i]) {
                acc = 0;
            }
            char k = acc % 26 + 97;
            res += k;
            acc++;
        }
        cout << res << '\n';
    }
    
    return 0;
}