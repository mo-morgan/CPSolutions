//https://www.hackerrank.com/challenges/bigger-is-greater/problem

#include <bits/stdc++.h>

// trivial solution with usage of next_permutation in C++.
// problem is much harder in other languages

using namespace std;

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        bool val = next_permutation(w.begin(), w.end());

        if (val == false)
            fout << "no answer" << "\n";
        else 
            fout << w << "\n";
    }

    fout.close();

    return 0;
}

