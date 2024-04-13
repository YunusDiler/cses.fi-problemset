#include <bits/stdc++.h>

using namespace std;
 
int main() {
	long long n; cin >> n;
	if (((n & 3) == 1) || ((n & 3) == 2)) {
		cout << "NO";
		return 0;
	}
	long long half = n * (n + 1) / 4;
	vector<int> r;
	vector<int> l;
	while (half - n > 0) {
		r.push_back(n);
		half -= n;
		n--;
	}
	r.push_back(half);
	while (n > 0) {
		if (n == half) {
			n--;
			continue;
		}
		l.push_back(n);
		n--;
	}
 
	cout << "YES\n" << l.size() << "\n";
	for (auto x : l) cout << x << " ";
	cout << "\n" << r.size() << "\n";
	for (auto x : r) cout << x << " ";
 
	//1 3 6 10 15 21 28 36 45 55 66 78
	//1 2 3 4  5  6  7  8  9  10 11 12
}