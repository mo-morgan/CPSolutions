/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int arr[200500];

int main()
{
    int n;
    cin >> n;
    
    int evenSum=0, oddSum=0;
    vector<int> indicies(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 1; i <= n ; i++) {
        if (i % 2 == 1) {
            oddSum += arr[i];
        } else {
            evenSum += arr[i];
        }
    }
    
    // bool removeOdd = true;
    // int diff = oddSum - evenSum;
    
    // if (diff > 0) {
    //     removeOdd = true;
    // }
    
    // diff = abs(diff);
    
    int newOdd = 0, newEven = 0;
    int ret = 0;
    
    for (int i = 1; i <= n; i++) {
        
        if (i % 2 == 1) {
            int o = evenSum - newEven + newOdd;
            int e = oddSum + newEven - arr[i] - newOdd;
            if (o == e) {
                ret++;
            }
            newOdd += arr[i];
        } else {
            int o = evenSum - arr[i] - newEven + newOdd;
            int e = oddSum - newOdd + newEven;
            if (o == e) {
                ret++;
            }
            newEven += arr[i]; 
        }
    }
    // else {
    //     for (int i = 1; i <= n; i++) {
    //         cout << arr[i] << endl;
    //         if (i % 2 == 0 && arr[i] == diff) {
    //             cout << sum << endl;
    //         }
    //     }
    // }
    cout << ret << endl;
    
    return 0;
}