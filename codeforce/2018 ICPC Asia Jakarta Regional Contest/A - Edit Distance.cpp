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
    string n;
    cin >> n;
    
    int j = n.length();  
      
    // declaring character array 
    char char_array[j+1];  
      
    // copying the contents of the  
    // string to char array 
    strcpy(char_array, n.c_str()); 
    
    int cz=0, co=0;
    for (int i = 0; i < j; i++) {
        if (char_array[i] == '0'){
            cz++;    
        }else {
            co++;
        }
    }
    
    if (cz > co) {
        vector<int> b(j, 1);
        for (int i = 0; i < j; i++) {
            cout << b[i];
        }
        return 0;
    } else if (co > cz) {
        vector<int> b(j, 0);
        for (int i = 0; i < j; i++) {
            cout << b[i];
        }
    } else {
        if (char_array[0]=='0') {
            vector<int> b(j, 0);
            b[0] = 1;
            for (int i = 0; i < j; i++) {
                cout << b[i];
            }
        } else {
            vector<int> b(j, 1);
            b[0] = 0;
            for (int i = 0; i < j; i++) {
                cout << b[i];
            }
        }
    }
    return 0;
}
