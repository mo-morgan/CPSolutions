/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    ll max = 0;
    
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    } 
    
    if (n == 2) {
        if (arr[0] == arr[1]) {
            cout << arr[0];
        } else {
            cout << 0 << endl;
        }
        return 0;
    }
    
    ll last = arr[n-1];
    ll first = arr[0];
    
    if (last == first) {
        max = last;
    }
    
    int front=1, back=n-2;
    
    for (int i = 0; i < n - 1; i++) {
        bool isFront;
        // cout << "first: " << first << endl;
        // cout << "last: " << last << endl;
        if (last == first) {
            max = last;
            isFront = true; // arbitrary chosen
        } else {
            isFront = (last > first ? true : false);
        }
        // cout << "max:" << max << endl;

        
        if (isFront) {
            first += arr[front];
            front++;
        } else {
            last += arr[back];
            back--;
        }
        
        // cout << "first: " << first << endl;
        // cout << "last: " << last << endl;
        // cout << "max:" << max << endl;
        
    }
    
    cout << max << endl;
    
    return 0;
}