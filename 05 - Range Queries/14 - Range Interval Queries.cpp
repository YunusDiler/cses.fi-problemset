#include <bits/stdc++.h>
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
// fast IO
struct _istream {
#define getchar getc
  bool eof;
  char buf[200000], *p1, *p2;
  inline operator bool() { return !eof; }
  inline char getc() {
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 200000, stdin), p1 == p2) ? EOF : *p1++;
  }
  template <typename T>
  inline _istream& operator>>(T& re) {
    re = 0;
    char c = getchar();
    bool neg = 0;
    while (!isdigit(c)) {
      if (c == EOF) {
        eof = 1;
        return *this;
      }
      if (c == '-') neg = 1;
      c = getchar();
    }
    while (isdigit(c)) {
      re = re * 10 + c - '0';
      c = getchar();
    }
    re = (neg ? -re : re);
    return *this;
  }
  _istream() : eof(0) { p1 = p2 = buf; }
} rit;
 
struct _ostream {
#define putchar putchar_unlocked
  inline _ostream& operator<<(const char c) {
    putchar(c);
    return *this;
  }
  inline _ostream& operator<<(const char* s) {
    while (*s != '\0') putchar(*s++);
    return *this;
  }
  inline _ostream& operator<<(const string s) {
    for (const auto& i : s) putchar(i);
    return *this;
  }
  template <typename T>
  inline _ostream& operator<<(T x) {
    if (x < 0) {
      putchar('-');
      x = -x;
    }
    char s[25];
    size_t len = 0;
    do s[len++] = x % 10 + 48;
    while (x /= 10);
    while (len) putchar(s[--len]);
    return *this;
  }
} wit;
#define cin rit
#define cout wit
#define endl '\n'
#define istream _istream
#define ostream _ostream
 
 
int v[200031];
 
int32_t main() {
  int n, q; cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<array<int, 4>> qs(q), qss(q);
  vector<int> ans(q);
 
  for (int i = 0; i < q; i++) {
    cin >> qs[i][0] >> qss[i][0] >> qs[i][1] >> qs[i][2];
    qs[i][3] = i;
    qss[i][3] = i;
    qss[i][1] = qs[i][1];
    qss[i][2] = qs[i][2];
  }
 
  sort(qs.begin(), qs.end());
  sort(qss.begin(), qss.end());
  int qit = 0;
  ordered_set s;
  for (int i = 0; i < n; i++) {
    while (qit < q && qs[qit][0] == i + 1) {
      int c = qs[qit][1], d = qs[qit][2];
      int x = s.order_of_key(d + 1) - s.order_of_key(c);
      ans[qs[qit][3]] -= x;
      qit++;
    }
    s.insert(v[i]);
  }
 
  ordered_set ss;
  qit = 0;
  for (int i = 0; i < n; i++) {
    ss.insert(v[i]);
    while (qit < q && qss[qit][0] == i + 1) {
      int c = qss[qit][1], d = qss[qit][2];
      int x = ss.order_of_key(d + 1) - ss.order_of_key(c);
      ans[qss[qit][3]] += x;
      qit++;
    }
  }
 
  for (auto& i : ans) cout << i << endl;
 
  return 0;
}