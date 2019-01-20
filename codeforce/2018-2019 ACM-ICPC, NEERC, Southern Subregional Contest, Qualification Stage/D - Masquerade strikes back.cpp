/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
}

bool isPerfectSquare(long double x) 
{   
  // Find floating point value of  
  // square root of x. 
  long double sr = sqrt(x); 
  
  // If square root is an integer 
  return ((sr - floor(sr)) == 0); 
}

int main()
{
    int n;
    cin >> n;
    
    map<int, int> map; // a map of how freqent each answer appeared
    
    unordered_set<pair<int, int>> used; // the set of used pairs
    vector<int> vec(n); // the list of answers
    
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        map[key]++;
        vec[i] = key;
    }
    
    for (int i = 0; i < n; i++) {
        if (map[vec[i]] == 0) {
            cout << "NO" << endl;
            return 0;
        }
        if (vec[i] == 1) { // add [1, 1] to used
            map[vec[i]]--;
            used.insert(make_pair(1, 1));
        } else if (isPrime(vec[i])) {
            
        } else if (isPerfectSquare((double) vec[i])) {
            
        } else { // not a perfect square
            for (int j=1; j<=sqrt(vec[i]); j++) { 
                if (n%j == 0) { 
                    //i, n/i are factors of this
                } 
            } 
        }
    }
    
    // yes so we can 

    return 0;
}
