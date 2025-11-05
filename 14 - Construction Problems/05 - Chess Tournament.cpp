#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 31
#endif

const int MOD = 1e9 + 7;
const int INF = 1e18;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n; cin >> n;
  vector<int> v(n);
  for (auto& i : v) cin >> i;
  int sum = 0;
  for (auto& i : v) sum += i;

  if (sum & 1) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  
  vector<pair<int, int>> ans;
  priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
  for (int i = 0; i < n; i++) {
    if (v[i]) pq.push({v[i], i + 1});
  }

  while (!pq.empty()) {
    auto [val, node] = pq.top();
    debug(val, node);
    pq.pop();
    stack<pair<int, int>> s;
    while (val && pq.size()) {
      val--;
      auto [l, r] = pq.top();
      pq.pop();
      ans.push_back({node, r});
      if (l - 1) s.push({l - 1, r});
    }
    if (val) {
      cout << "IMPOSSIBLE";
      return 0;
    }
    while (!s.empty()) {
      pq.push(s.top());
      s.pop();
    }
  }

  
  cout << sum / 2 << endl;
  for (auto& [l, r] : ans) cout << l << ' ' << r << endl;

  return 0;
}