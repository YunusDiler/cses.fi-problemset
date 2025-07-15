#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  auto Ask = [&](int x) -> bool {
    cout << "? " << x << endl;
    cout.flush();
    string s; cin >> s;
    return s == "YES";
  };

  auto Report = [&](int x) -> void {
    cout << "! " << x << endl;
    cout.flush();
  };

  int l = 1, r = 1e9, ans = -1;

  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (Ask(mid)) l = mid + 1;
    else {
      r = mid - 1;
      ans = mid;
    }
  }
  
  Report(ans);
  
  return 0;
}