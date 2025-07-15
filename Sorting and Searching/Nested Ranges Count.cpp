#include <bits/stdc++.h>

#define int long long

using namespace std;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first.first == b.first.first) {
    return a.first.second > b.first.second;
  }
  return a.first.first < b.first.first;
}

bool cmpr(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first.first == b.first.first) {
    return a.first.second < b.first.second;
  }
  return a.first.first > b.first.first;
}

vector<int> tree;
int N = 1;

void update(int index) {
  index += N - 1;
  while (index) {
    tree[index]++;
    index >>= 1;
  }
}

int range(int left, int right) {
  left += N - 1;
  right += N - 1;
  int sum = 0;

  while (left < right) {
    if (left & 1) sum -= tree[left ^ 1];
    left >>= 1;
    if (!(right & 1)) sum -= tree[right ^ 1];
    right >>= 1;
  }
  sum += tree[right];
  return sum;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vector<pair<pair<int, int>, int>> v(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v[i].first.first = a;
    v[i].first.second = b;
    v[i].second = i;
  }

  vector<int> contains(n);
  vector<int> contained(n);

  map<int, int> mps;
  map<int, int> mped;

  sort(v.begin(), v.end(), cmp);
  for (auto p : v) {
    mped[p.first.second] = true;
  }

  vector<int> fed;
  int t = 1;
  for (auto m : mped) {
    fed.push_back(t);
    mped[m.first] = t;
    t++;
  }

  while (N < fed.size()) N <<= 1;
  tree.resize(2 * N, 0);

  for (auto p : v) {
    contained[p.second] = range(mped[p.first.second], fed.size());
    update(mped[p.first.second]);
  }

  sort(v.begin(), v.end(), cmpr);
  for (auto p : v) {
    mps[p.first.second] = true;
  }

  vector<int> fs;
  t = 1;
  for (auto m : mps) {
    fs.push_back(t);
    mps[m.first] = t;
    t++;
  }

  for (int i = 0; i < tree.size(); i++) tree[i] = 0;

  for (auto p : v) {
    contains[p.second] = range(1, mps[p.first.second]);
    update(mps[p.first.second]);
  }

  for (auto b : contains) cout << b << ' ';
  cout << endl;
  for (auto b : contained) cout << b << ' ';

  return 0;
}