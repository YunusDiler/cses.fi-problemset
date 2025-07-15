#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> v = {1, 2, 4, 8, 16, 32, 63};
  int s = 7;
  while (n >= s) {
    v.push_back(
        (v[s - 1] + v[s - 2] + v[s - 3] + v[s - 4] + v[s - 5] + v[s - 6]) %
        (int)(1e9 + 7));
    s++;
  }
  cout << v[n - 1];
  return 0;
}