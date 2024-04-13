#include <bits/stdc++.h>

using namespace std;
 
int main() {
	long long n; cin >> n;
	int a; cin >> a;
	int s = a;
	long long t = 0;
	while (cin >> a) {
		t += max(s - a, 0);
		s = max(s, a);
	}
	cout << t;
}