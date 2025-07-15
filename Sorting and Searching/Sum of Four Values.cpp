#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, target;
  cin >> n >> target;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<pair<int, pair<int, int>>> arr;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      arr.push_back({v[i] + v[j], {i + 1, j + 1}});
  sort(arr.begin(), arr.end());

  int l = 0, r = arr.size() - 1;
  bool left = true;
  while (l < r) {
    if (arr[l].second.second == arr[r].second.second ||
        arr[l].second.first == arr[r].second.first ||
        arr[l].second.first == arr[r].second.second ||
        arr[l].second.second == arr[r].second.first) {
      if (left) {
        l++;
        continue;
      } else {
        r--;
        continue;
      }
    }

    if (arr[l].first + arr[r].first == target) {
      cout << arr[l].second.first << ' ' << arr[l].second.second << ' '
           << arr[r].second.first << ' ' << arr[r].second.second;
      return 0;
    }
    if (arr[l].first + arr[r].first < target) {
      l++;
      left = true;
    } else {
      r--;
      left = false;
    }
  }
  cout << "IMPOSSIBLE";

  return 0;
}