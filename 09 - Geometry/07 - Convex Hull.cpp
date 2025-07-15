#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

struct Point {
  int x, y;
  Point(int x, int y) : x(x), y(y) {}
  Point() : x(0), y(0) {}
  bool operator<(const Point& p) const {
    return (x == p.x) ? (y < p.y) : (x < p.x);
  }
};

inline int Loc(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n; cin >> n;
  vector<Point> v(n);
  for (auto& p : v) cin >> p.x >> p.y;
  
  sort(v.begin(), v.end());

  vector<Point> lr = {v[0], v[1]};
  for (int i = 2; i < n; i++) {
    while (lr.size() >= 2 && Loc(lr[lr.size() - 2], v[i], lr.back()) < 0) lr.pop_back();
    lr.push_back(v[i]);
  }
  
  vector<Point> rl = {v[n - 1], v[n - 2]};
  for (int i = n - 3; i >= 0; i--) {
    while (rl.size() >= 2 && Loc(v[i], rl[rl.size() - 2], rl.back()) > 0) rl.pop_back();
    rl.push_back(v[i]);
  }
  
  cout << rl.size() + lr.size() - 2 << endl;
  for (int i = 0; i < (int) lr.size(); i++) cout << lr[i].x << ' ' << lr[i].y << endl;
  for (int i = 1; i < (int) rl.size() - 1; i++) cout << rl[i].x << ' ' << rl[i].y << endl;
  
  return 0;
}