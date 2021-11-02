/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // TEAM FORMING
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> skills(n);
    for (int i = 0; i < n; i++) {
        cin >> skills[i];
    }
    
    sort(skills.begin(), skills.end());
    long long total = 0;
    for (int i = 0; i < n; i++) {
        if (i%2==0) {
            total-=skills[i];
        } else {
            total+=skills[i];
        }
    }
    
    cout << total;

    return 0;
}