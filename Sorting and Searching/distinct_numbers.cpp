#include <bits/stdc++.h>

using namespace std;
 
int main() {
	int n; cin >> n;
	set<int> s;
	int x; while (cin >> x) s.emplace(x);
	cout << s.size();
}