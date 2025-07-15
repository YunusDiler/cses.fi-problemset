#include <bits/stdc++.h>

using namespace std;
 
int main() {
	string n; cin >> n;
	vector<int> v(26);
	bool d = false;
	char odd;
	string result = "";
	for (auto x : n) {
		v[x - 'A']++;
	}
	for (int i = 0; i < 26; i++) {
		if ((v[i] & 1) && d) {
			cout << "NO SOLUTION";
			return 0;
		}
		if (v[i] & 1) {
			odd = i + 'A';
			d = true;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < v[i]/2; j++)
		{
			result += i + 'A';
		}
	}
	string reversedResult = result;
	reverse(reversedResult.begin(), reversedResult.end());
	if (d) result += odd;
	result += reversedResult;
	cout << result;
 
}