#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s(n, '0');
  vector<string> list;
  list.push_back(s);
  for (int i = 0; i < n; i++) {
    int loop = 1 << i;
    for (int j = 0; j < loop; j++) {
      string a = list[loop - j - 1];
      a[n - i - 1] = '1';
      list.push_back(a);
    }
  }
  for (auto x : list) {
    cout << x << "\n";
  }
}