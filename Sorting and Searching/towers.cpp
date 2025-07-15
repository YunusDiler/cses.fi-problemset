#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, towers = 0;
  cin >> n;
  map<int, int> mp;

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    mp[k]++;
    auto it = mp.find(k);
    it++;
    if (it == mp.end())
      towers++;
    else {
      if (--(*it).second == 0) mp.erase(it);
    }
  }
  cout << towers;

  return 0;
}