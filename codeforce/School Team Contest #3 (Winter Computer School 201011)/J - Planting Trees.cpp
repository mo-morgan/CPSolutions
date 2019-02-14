#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[110][110];

int main() {
    cin >> n >> m;

    if (n+m==3 or n+m==4) {
        cout << "-1" << endl;
    }
    
    else{
        int num=2;
        if (n>=m) {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++){
                    if (num > m*n) {
                        num=1;
                    }
                    a[i][j]=num;
                    num += 2;
                }
        }
        else
            for (int j = 1; j <= m; j++) {
                for (int i = 1; i <= n; i++){
                    if (num > m*n) {
                        num = 1;
                    }
                    a[i][j] = num;
                    num += 2;
                }
            }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++){
                cout << a[i][j];
                if (j == m) {
                    cout << "\n";
                }
                else {
                    cout << " ";
                }
            }
        }
    }
    return 0;
}