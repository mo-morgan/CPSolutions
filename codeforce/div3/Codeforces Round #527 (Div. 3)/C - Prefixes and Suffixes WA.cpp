#include <iostream>
#include <vector>
#include <string>
#include <set>

#define PX          0
#define SX          1
#define ASCII_OFFSET    97

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> hints;
    vector<vector<int>> buckets(n, vector<int>(26, 0));
    for (int i = 0; i < 2*n - 2; i++) {
        string temp;
        cin >> temp;
        hints.push_back(temp);
        // place prefix buckets
        for (int j = 0; j < temp.size(); j++) {
            buckets[j][temp.at(j) - ASCII_OFFSET]++;
        }
        // place in suffix buckets
        int offset = n - temp.size();
        for (int j = 0; j < temp.size(); j++) {
            buckets[j+offset][temp.at(j) - ASCII_OFFSET]++;
        }
    }
    
    // build string
    vector<int> ivans(n);
    for (int i = 0; i < n; i++) {
        //pick the most popular bucket
        int bucket = 0;
        int count = -1;
        for (int j = 0; j < 26; j++) {
            if (buckets[i][j] > count) {
                count = buckets[i][j];
                bucket = j;
            }
        }
        ivans[i] = bucket;
    }
    
    set<string> seenPX;
    set<string> seenSX;
    vector<int> seen(n);
    
    for (int i = 0; i < hints.size(); i++) {
        //evaluate all the hints
        string hint = hints[i];
        bool prefix = true;
        
        if (seenPX.find(hint) != seenPX.end()) {
            prefix = false; //is suffix
        } else if (seenSX.find(hint) != seenSX.end()) {
            prefix = true;  //is prefix
        } else {
            for (int j = 0; j < hint.size(); j++) {
                //check all chars for match
                // cout << "hint: " << (hint.at(j) - ASCII_OFFSET) << "ivans: " << ivans[j] << "\n";
                if ((hint.at(j) - ASCII_OFFSET) != ivans[j]) {
                    prefix = false;
                    break;
                }
            }
        }
        if (prefix) {
            cout << "P";
            // seen[hint.size()] = PX;
            seenPX.insert(hint);
        } else {
            cout << "S";
            // seen[hint.size()] = SX;
            seenSX.insert(hint);
        }
    }

    return 0;
}