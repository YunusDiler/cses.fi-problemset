#include <bits/stdc++.h>

using namespace std;
 
int main() {
	int n; cin >> n;
	vector<pair<int, bool>> v(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		int x; cin >> x;
		v[i] = { x , i & 1 };
	}
 
	sort(v.begin(), v.end());
 
	int m = 0, all = 0;
	for (auto& x : v) {
		m -= 2 * x.second - 1;
		all = max(all, m);
	}
	cout << all;
}