#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  string s; cin >> s;
  vector<int> freq('Z' + 1);
  for (auto& c : s) freq[c]++;
  int mx = *max_element(freq.begin(), freq.end());
  if (mx > (s.size() + 1) / 2) {cout << -1; return 0;}
  string ans(s.size(), '#');
  int last = 'y';
  for (int i = 0; i < s.size(); i++) {
    char c = 'y'; int cnt = 0;
    for (int j = 'A'; j <= 'Z'; j++) {
      if (freq[j] > cnt) {
        c = j;
        cnt = freq[j];
      }
    } 
    if ((s.size() - i) % 2 == 1 && cnt > (s.size() - i) / 2) {
      last = ans[i] = c;
      freq[c]--;
      continue;
    }
    for (int j = 'A'; j <= 'Z'; j++) {
      if (j != last && freq[j]) {c = j; break;} 
    }
    last = ans[i] = c;
    freq[c]--;
  }

  cout << ans;
  
  
  return 0;
}