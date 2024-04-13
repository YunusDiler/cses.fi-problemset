#include <bits/stdc++.h>

using namespace std;
 
int main() {
	int n; cin >> n;
	while (n--) {
		long long k; cin >> k;
		long long div = 9, doksan = 90;
		long long seg = 1;
		while (k - div > 0) {
			k -= div;
			div *= 10;
			div += doksan;
			doksan *= 10;
			seg++;
		}
		long long mins = pow(10, seg - 1);
		k--;
		long long a = k % seg;
		k += seg;
		k /= seg;
		k--;
		k += mins;
		cout << to_string(k)[a] << endl;
	}
}