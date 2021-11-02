/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

const int N = 1e5 + 1;
const double EPS = 1e-8;
// double dist[T-1];
long long X[N];
long long n, k;

using namespace std;

// bool bin(double d, int num) {
//     int c = 1;
//     double prev = X[0];
    
//     for (int i = 1; i < k; i++) {
//         // cout << "X[i] - prev = " << X[i] - prev << endl;
//         if (X[i] - prev >= d) {
//             c++;
//             prev = X[i];
//         }
//     }
//     if (c >= num) {
//         return true;
//     } else {
//         return false;
//     }
// }

int main()
{
    cin >> n >> k;
    X[0] = 1;
    for (int i = 1; i <= k - 1; i++) {
        long long j;
        cin >> j;
        X[i] = X[i-1] + j;
    }
    
    long long dp[k+1];
    long long outerDist = X[k-1] - X[0];
    
    long long front = 0;
    long long back = k-1;
    bool isEven = false;
    vector<long long> chosen;
    
    // binary search on the answer
    for (long long i = 1; i <= k; i++) { // k number of queries
        if (i == 1) {
            chosen.push_back(X[front]);
            cout << 0;
            dp[i] = 0;
            front++;
            isEven = true;
            
            continue;
        }
        
        if (i == 2) {
            chosen.push_back(X[back]);
            cout << " " << X[k-1] - X[0];
            dp[i] = X[k-1] - X[0];
            back--;
            isEven = false;
            continue;
        }
        
        if (i == 3) {
            chosen.push_back(X[front]);
            cout << " " << (X[k-1] - X[0]) * 2;
            dp[i] = dp[i-1] * 2;
            front++;
            isEven = true;
            continue;
        }
        
        // find i - 2 elements such that their distance is maximized
        // if i is even, choose the farthest ones
        // if i is odd, choose the farthest ones + one random middle one
        dp[i] = dp[i-1] + outerDist;
        if (isEven) {
            //adding back to dp
            for (int j = 2; j < chosen.size(); j++) {
                dp[i] += abs(X[back] - chosen[j]);
                // cout << chosen.size() << " ";
            }
            chosen.push_back(X[back]);
            back--;
            cout << " " << dp[i];
            isEven = false;
        } else {
            //adding front to dp
            for (int j = 2; j < chosen.size(); j++) {
                dp[i] += abs(X[front] - chosen[j]);
            }
            chosen.push_back(X[front]);
            front++;
            cout << " " << dp[i];
            isEven = true;
        }
        
        // double left = X[0], right = X[k-1] - X[0];
        // // cout << "left" << left << endl;
        // // cout << "right" << right << endl;

        // while (right - left > EPS) {
        //     double mid = (left + right) / 2;
        //     if (bin(mid, i)) {
        //         left = mid;
        //     } else {
        //         right = mid;
        //     }
        // }
        
        // cout << left << " ";
    }
    
    return 0;
}