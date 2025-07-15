#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec;
  int x;
  int tempN = n;
  while (tempN--) {
    cin >> x;
    vec.push_back(x);
  }

  string s(n, '0');
  vector<string> list;
  list.push_back(s);
  for (int i = 0; i < n; i++) {
    int loop = 1 << i;
    for (int j = 0; j < loop; j++) {
      string a = list[loop - j - 1];
      a[n - i - 1] = '1';
      list.push_back(a);
    }
  }

  vector<long long> diffs;
  for (string s : list) {
    long long sum = 0;
    int i = 0;
    for (char c : s) {
      if (c == '0')
        sum += vec[i];
      else
        sum -= vec[i];

      i++;
    }

    diffs.push_back(abs(sum));
  }

  long long min_diff = diffs[0];
  for (long long item : diffs) {
    if (item < min_diff) min_diff = item;
  }

  cout << min_diff;
}