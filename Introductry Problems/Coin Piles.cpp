#include <bits/stdc++.h>

using namespace std;
 
int main() {
	long long n; cin >> n;
	while (n--) {
		int a, b; cin >> a >> b;
		int mi = min(a, b);
		int ma = max(a, b);
		if (ma - mi <= mi && (mi - (ma - mi)) % 3 == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}