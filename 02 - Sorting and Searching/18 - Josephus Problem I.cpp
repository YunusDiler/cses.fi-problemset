#include <bits/stdc++.h>

#define ll long long
#define endl "\n"

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  int count = n, i = 0;
  bool kill = false;

  vector<bool> v(n, true);

  while (count) {
    if (v[i]) {
      if (kill) {
        v[i] = false;
        kill = false;
        count--;
        cout << i + 1 << ' ';
      } else
        kill = true;
    }
    i++;
    i %= n;
  }

  return 0;
}