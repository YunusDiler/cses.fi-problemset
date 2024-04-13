#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n; cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int y, x; cin >> x >> y; 
		pair<int,int> p = {y, x};
		v.push_back(p);
	}
	
	sort(v.begin(), v.end());
	
	int m = 0, last = 0;
	for (int i = 0; i < n; i++) {
		if(v[i].second >= last) {
			m++;
			last = v[i].first;
		}
	}
	cout << m;
}