/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, d;
    cin >> n >> m >> d;
    int dist = d+1;
    map<int, int> minutes;
    int res[250009];
    
    for (int i = 1; i <= n; i++) {
        int minute;
        cin >> minute;
        minutes[minute] = i; //stores a map of minutes, each minute maps to its position
    }
    
    
    int i;
    for (i = 1; !minutes.empty(); i++) { // i represents day i
        int min = minutes.begin()->first; // min is the amount of the minute
        int pos = minutes.begin()->second; // pos is the position of the minutes
        res[pos] = i; // res[pos] stores the day
        
        minutes.erase(minutes.begin());
        
        for (int k = min;;) {
            auto y = minutes.lower_bound(k + dist); // the lower bound of min + dist
            if (y == minutes.end()) { // no such number for this day
                break;
            }
            k = y->first;

            if (k - min > m) { // out of bounds
                break;
            }

            res[y->second] = i;

            minutes.erase(y);
        }
    }
    
    cout << i-1 << endl;
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    
    return 0;
}
