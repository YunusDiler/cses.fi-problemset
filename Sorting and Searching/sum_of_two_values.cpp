#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n, a; cin >> n >> a;
	vector<pair<int, int>> v;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		pair<int,int> p = {x,i};
		v.push_back(p);
	}
	
	sort(v.begin(), v.end());
	
	int l = 0, r = n - 1, sum;
	while (l < r){
		sum = v[l].first + v[r].first;
		if (sum < a) l++;
		else if (sum > a) r--;
		else {
			cout << v[l].second << " " << v[r].second;
			return 0;
		}
	}
	cout << "IMPOSSIBLE";
}