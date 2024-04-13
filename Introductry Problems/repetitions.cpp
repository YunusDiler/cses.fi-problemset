#include <bits/stdc++.h>

using namespace std;
 
int main() {
	string c; cin >> c;
	int l = 0;
	char a = c[0];
	int m = 1;
	for (auto x : c) {
		if (a == x) {
			l++;
			m = max(m, l);
		}
		else {
			a = x;
			l = 1;
			m = max(m, l);
		}
	}
	cout << m;
}