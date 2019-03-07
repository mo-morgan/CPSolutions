/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int smallestDivisor(int n) 
{ 
    // if divisible by 2 
    if (n % 2 == 0) 
        return 2; 
  
    // iterate from 3 to sqrt(n) 
    for (int i = 3; i * i <= n; i += 2) { 
        if (n % i == 0) 
            return i; 
    } 
  
    return n; 
} 

int main()
{
    int n;
    cin >> n;
    int res = 0;
    while(1) {
        res += n;
        n/=smallestDivisor(n);

        
        if (n<=1) {
            break;
        }
    }

    res += 1;
    cout << res << endl;
    
    return 0;
}
