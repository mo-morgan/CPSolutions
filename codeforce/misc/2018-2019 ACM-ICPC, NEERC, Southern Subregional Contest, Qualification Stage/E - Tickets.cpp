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
    map<int, int> scores;
    vector<int> all(1000000);
    for (int i = 0; i <= 999999; i++) {
        int firstD = i / 100000;
        int k = i%100000;
        int secondD = k/10000;
        k = k%10000;
        int thirdD = k/1000;
        k = k%1000;
        int fourthD = k/100;
        k = k%100;
        int fifthD = k/10;
        k = k%10;
        int sixthD = k;
        
        int score = abs((firstD+secondD+thirdD) - (fourthD+fifthD+sixthD));
        for (int j = 0; j < score; j++) {
            all[i] += scores[j];   
        }

        scores[score]++;
    }
    
    int n;
    cin >> n;
    vector<int> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    
    for (int i = 0; i < n; i++) {
        cout << all[g[i]] << "\n";
    }

    return 0;
}
