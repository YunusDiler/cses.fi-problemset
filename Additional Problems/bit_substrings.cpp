#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;

const double PI = 2.0 * acos(0.0);
using cd = complex<double>;

void fft(vector<cd> &a, bool invert = 0) {
  int n = a.size();

  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;

    if (i < j) swap(a[i], a[j]);
  }

  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      cd w(1);
      for (int j = 0; j < len / 2; j++) {
        cd u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }

  if (invert) {
    for (cd &x : a) x /= n;
  }
}

vector<int> multiply(vector<int> const &a, vector<int> const &b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < a.size() + b.size()) n <<= 1;
  fa.resize(n);
  fb.resize(n);

  fft(fa);
  fft(fb);
  for (int i = 0; i < n; i++) fa[i] *= fb[i];
  fft(fa, 1);

  vector<int> result(n);
  for (int i = 0; i < n; i++) result[i] = round(fa[i].real());

  return result;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s;
  cin >> s;
  vector<int> a;
  int count = 0, z = 0;
  for (auto& c : s) {
    if (c == '1') {
      a.push_back(count + 1);
      z += count * (count + 1) / 2;
      count = 0;
    }
    else {
      count++;
    }
  }
  a.push_back(count + 1);
  z += (count + 1) * count / 2;

  vector<int> b = a;
  reverse(b.begin(), b.end());

  vector<int> res = multiply(a, b);
  cout << z << ' ';
  for (int i = (int)(a.size() - 2); i >= 0; i--) cout << res[i] << ' ';
  for (int i = 0; i <= (int)(s.size() - a.size()); i++) cout << 0 << ' ';


  return 0;
}