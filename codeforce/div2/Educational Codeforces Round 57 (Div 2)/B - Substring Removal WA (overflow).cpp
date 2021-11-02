/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

// bool allCharactersSame(string s) 
// { 
//     return (s.find_first_not_of(s[0]) == string::npos); 
// } 

int main()
{
    int size;
    cin >> size;
    string word;
    cin >> word;
    
    int len = word.length();
    
    int firstCons = 0;
    for (int i = 0; i < len - 1; i++) {
        if (word.at(i) == word.at(i+1)) {
            firstCons++;
        } else {
            break;
        }
    }

    
    int lastCons = len - 1;
    int lastNum = 0;
    for (int i = len - 1; i > 0; i--) {
        if (word.at(i) == word.at(i-1)) {
            lastCons--;
            lastNum++;
        } else {
            break;
        }
    }
    
    bool firstLastSame = (word.at(len-1) == word.at(0) ? true : false);
    
    
    int ret = 0;
    if (firstLastSame) { // delete the middle only and it will work
        int mul = ++firstCons;
        for (int i = 0; i < mul + 1; i++) {
            ret += lastNum + 2;
        }
    } else { // delete from 0 - last cons    +    delete from first cons to lengh
        ret += lastNum + 2;
        ret += ++firstCons;
    }
    
    cout << ret % 998244353;
    // for (int i = 1; i < size - 1; i++) {
    //     for (int j = i; j < size; j++) {
    //         string sub;
    //         sub = word.erase(i-1, j-1);
    //         if (allCharactersSame(sub)) {
    //             ret++;
    //         }
    //     }
    // }
    
    // ret++;
    // cout << ret;
    return 0;
}