#include <bits/stdc++.h>

using namespace std;

int main() {
  set<int> s;
  map<int, int> mp;
  int n;
  cin >> n;
  int k = 0, ans = 0, size = 0, m = 0, i = 0;
  while (n--) {
    cin >> k;

    s.insert(k);
    if (s.size() == size)
      m = min(i - mp[k], m + 1);
    else {
      m++;
      size++;
    }
    ans = max(ans, m);
    mp[k] = i;
    i++;
  }
  cout << ans;
  return 0;
}