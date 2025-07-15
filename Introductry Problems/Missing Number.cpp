#include <bits/stdc++.h>

using namespace std;

int main() {
  long long c;
  cin >> c;
  vector<bool> v(c, false);
  int n;
  while (cin >> n) v[n - 1] = true;
  for (size_t i = 0; i < c; i++) {
    if (!v[i]) {
      cout << ++i;
      return 0;
    }
  }
}