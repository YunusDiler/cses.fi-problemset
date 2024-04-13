#include <bits/stdc++.h>

using namespace std;
 
int main() {
	long long n, x; cin >> n >> x;
	vector<long long> v(n);
 
	for (int i = 0; i < n; i++) {
		int a; cin >> a; v[i] = a;
	}
	
	sort(v.begin(), v.end());
	int c = 0;
	int i = 0, j = n - 1;
	for (;i <= j;)
	{
		if (v[j] + v[i] <= x)
		{
			c++;
			j--;
			i++;
		}
		else {
			j--;
			c++;
		}
	}
	cout << c;
}
