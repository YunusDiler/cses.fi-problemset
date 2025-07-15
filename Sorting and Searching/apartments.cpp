#include <bits/stdc++.h>

using namespace std;
 
int main() {
	ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	
	long long n, m, k; cin >> n >> m >> k;
	vector<long long> d(n);
	vector<long long> a(m);
	for (int i = 0; i < n; i++) {
		int x; cin >> x; d[i] = x;
	}
	for (int i = 0; i < m; i++)
	{
		int x; cin >> x; a[i] = x;
	}
	sort(d.begin(), d.end());
	sort(a.begin(), a.end());
	
	int i = 0, c = 0;
 
	for (auto x : d) {
		while (i < m) {
			if (x + k >= a[i] && x - k <= a[i]) {
				c++;
				i++;
				break;
			}
			if (x + k < a[i]) break;
			i++;
		}
	}
	cout << c;
}