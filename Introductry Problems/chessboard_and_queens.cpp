#include <bits/stdc++.h>

using namespace std;
 
bool c(vector<string>& b, vector<int>& p) {
	for (int i = 0; i < 8; i++)
	{
		int j = p[i];
		if (b[i][j] == '*') return false;
		for (int x = i + 1, y = j + 1; x < 8 && y < 8; x++, y++)
		{
			if (p[x] == y) return false;
		}
		for (int x = i + 1, y = j - 1; x < 8 && y >= 0; x++, y--)
		{
			if (p[x] == y) return false;
		}
	}
	return true;
}
 
int main()
{
	vector<string> v;
	string x; while (cin >> x) v.push_back(x);
	vector<int> p{ 0,1,2,3,4,5,6,7 };
	int s = 0;
	do if (c(v, p)) s++;
	while (next_permutation(p.begin(), p.end()));
	cout << s;
}