#include <bits/stdc++.h>

using namespace std;
 
int main() {
	int n; cin >> n;
	while (n --> 0) {
		long long y, x, c, m; cin >> y >> x;
		m = max(x, y);
		long long sq = m * m;
		if (m & 1) c = sq - y + 1 - m + x;
		else c = sq - x + 1 - m + y;
		cout << c << endl;
	}
}