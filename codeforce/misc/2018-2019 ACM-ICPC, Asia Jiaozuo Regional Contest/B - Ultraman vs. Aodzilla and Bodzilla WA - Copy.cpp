/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    long long HPa, HPb, ATa, ATb;
    long long min;
    long long currAtt;
    int numIter1, numIter2;
    numIter2 = numIter1 = 0;
    string res1, res2;
    bool Alive, Blive;
    
    for (int i = 0; i < n; i++) {
        cin >> HPa >> HPb >> ATa >> ATb;
        long long HPaa = HPa;
        long long HPbb = HPb;
        int score = 0;
        Alive = Blive = true;
        currAtt = 1;
        res1 = res2 = "";
        
        // first kill A
        while(Alive || Blive) {
            numIter1++;
            if (Alive) {
                score += ATa;
                HPa -= currAtt;
                res1 += "A";
            }
            if (Blive) {
                score += ATb;
                if (!Alive) {
                    HPb -= currAtt;
                    res1 += "B";
                }
            }
            // cout << "score" << score << endl;
            // cout << "Hpa" << HPa << endl;
            // cout << "HPb" << HPb << endl;

            if (HPa <= 0) { // A is dead
                Alive = false;
            }
            if (HPb <= 0) {
                Blive = false;
                break;
            }
            currAtt++;
        }
        min = score;
        score = 0;
        currAtt = 1;
        Alive = Blive = true;
        // first kill B
        while(Alive || Blive) {
            numIter2++;
            if (Blive) {
                score += ATb;
                HPbb -= currAtt;
                res2 += "B";
            }
            if (Alive) {
                score += ATa;
                if (!Blive) {
                    HPaa -= currAtt;
                    res2 += "A";
                }
            }
            // cout << "score" << score << endl;
            // cout << "Hpa" << HPa << endl;
            // cout << "HPb" << HPb << endl;

            if (HPbb <= 0) { // B is dead
                Blive = false;
            }
            if (HPaa <= 0) {
                Alive = false;
                break;
            }
            currAtt++;
        }
    
        
        if (min < score) {
            cout << min << " " << res1 << '\n';
        } else if (score < min) {
            cout << score << " " << res2 << '\n';
        } else {// ==
            if (numIter1 <= numIter2) {
                cout << min << " " << res1 << '\n';
            } else {
                cout << score << " " << res2 << '\n';
            }
        }
    }
    return 0;
}