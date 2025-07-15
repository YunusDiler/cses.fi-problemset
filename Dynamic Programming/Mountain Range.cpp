#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n; cin >> n;
  vector<int> v(n);
  for (auto& i : v) cin >> i;
  
  vector<int> dp(n, 1), l(n, -1), r(n, -1), deg(n);
  stack<pair<int, int>> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && st.top().first < v[i]) {
      r[st.top().second] = i;
      deg[i]++;
      st.pop(); 
    }
    st.push(make_pair(v[i], i));
  }
  while (!st.empty()) st.pop();
  for(int i = n - 1; i >= 0; i--) {
    while (!st.empty() && st.top().first < v[i]) {
      l[st.top().second] = i;
      deg[i]++;
      st.pop(); 
    }
    st.push(make_pair(v[i], i));
  }
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) q.push(i);
  }
  while (!q.empty()) {
    int from = q.front();
    q.pop();
    if (l[from] != -1) {
      dp[l[from]] = max(dp[l[from]], dp[from] + 1);
      deg[l[from]]--;
      if (deg[l[from]] == 0) q.push(l[from]);
    }
    if (r[from] != -1) {
      dp[r[from]] = max(dp[r[from]], dp[from] + 1);
      deg[r[from]]--;
      if (deg[r[from]] == 0) q.push(r[from]);
    }
  }
  int ans = 1;
  for (int i = 0; i < n; i++) ans = max(dp[i], ans);
  cout << ans;
  
  return 0;
}