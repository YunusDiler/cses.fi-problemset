#include <bits/stdc++.h>

using namespace std;
 
int main() {
	int n; cin >> n;
	cout << (1 << n) - 1 << endl;
	vector<int> v(16, 1);
 
	static const int MultiplyDeBruijnBitPosition[32] = {
	  0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
	  31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9
	};
	for (unsigned int i = 1; i < (1 << n); i++) {
		int r;
		r = MultiplyDeBruijnBitPosition[((uint32_t)((i & -i) * 0x077CB531U)) >> 27];
		if (n & 1) {
			cout << v[r] << ' ';
			if ((r + 1) & 1) v[r]--;
			else v[r]++;
			if (v[r] == 0) v[r] += 3;
			else if (v[r] == 4) v[r] -= 3;
			cout << v[r] << endl;
		}
		else {
			cout << v[r] << ' ';
			if ((r + 1) & 1) v[r]++;
			else v[r]--;
			if (v[r] == 0) v[r] += 3;
			else if (v[r] == 4) v[r] -= 3;
			cout << v[r] << endl;
		}
	}
 
	/*
	1 3 - 1
	1 2 - 2
	3 2 - 1
	1 3 - 3
	2 1 - 1
	2 3 - 2
	1 3 - 1
	1 2 - 4
	3 2 - 1
	3 1 - 2
	2 1 - 1
	3 2 - 3
	1 3 - 1
	1 2 - 2
	3 2 - 1
	*/
}