#include <bits/stdc++.h>

using namespace std;
 
int main() {
	int n; cin >> n;
	long long sum = 0;
	long long m = INT_MIN;
	int x;
	while (n--) {
		cin >> x;
		sum += x;
		m = max(sum, m);
		if (sum < 0) sum = 0;
	}
	cout << m;
}