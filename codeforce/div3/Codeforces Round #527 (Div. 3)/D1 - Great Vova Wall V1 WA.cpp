/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // fast io
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    
    // long long diff = 0;
    if (n == 1) {
        cout << "YES";
        return 0;
    }
    
    if (n == 2 && abs(height[0] - height[1]) % 2 == 0) {
        cout << "YES";
        return 0;
    } else if (n == 2) {
        cout << "NO";
        return 0;
    }
    
    if (n == 3) {
        long long left = height[1] - height[0];
        long long right = height[2] - height[1];
        if ((left + right) % 2 == 1) {
            cout << "YES";
            return 0;
        }
        if (left == 0 && right == 0) {
            cout << "YES";
            return 0;
        }
        if (left % 2 == 1 && right % 2 == 1) {
            cout << "NO";
            return 0;
        }
        
        cout << "YES";
        return 0;
    }
    
    for (int i = 0; i < n - 3; i++) {
        long long r = abs(height[i+1] - height[i]);
        if (r % 2 == 0) {
            continue;
        }
        
        long long rr = abs(height[i+2] - height[i+1]);
        if (rr % 2 == 0) {
            continue;
        }
        
        long long rrr = abs(height[i+3] - height[i+2]);
        if (rrr != 0) {
            cout << "NO";
            return 0;
        } else {
            continue;
        }
    }
    
    cout << "YES";
    
    // if (diff == 0) {
    //     cout << "YES";
    // }
    // else if (diff % 2 == 0) {
    //     cout << "NO";
    // } else {
    //     cout << "YES";
    // }
    return 0;
}