/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

int main() {
	string t;
	cin >> t;
	
	if (t.length() % 2 == 0) {
		int init = t.length() / 2 - 1;
		string res = "";
		int counter = 1;
		bool isPlus = true;
		for (int i = 0; i < t.length(); i++) {
			res += t.at(init);
			if (isPlus) {
				init += counter;
			} else {
				init -= counter;
			}
			isPlus = !isPlus;
			counter++;
		}
		
		cout << res << endl;
	} else {
	    int init = t.length() / 2;
	    		string res = "";
		int counter = 1;
		bool isPlus = true;
		for (int i = 0; i < t.length(); i++) {
			res += t.at(init);
			if (isPlus) {
				init += counter;
			} else {
				init -= counter;
			}
			isPlus = !isPlus;
			counter++;
		}
		
		cout << res << endl;
	}
	return 0;
}