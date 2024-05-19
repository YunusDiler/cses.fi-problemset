// NOT A SOLUTION

#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

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

int32_t main() {
    need_for_speed
    
    int n; cin >> n;
    vector<pair<pair<int, int>, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        v[i].first.first = a;
        v[i].first.second = b;
        v[i].second = i;
    }
    sort(v.begin(), v.end(), cmp);

    vector<short> contains(n);
    vector<short> contained(n);

    int m = 0;
    for (auto p : v)
    {
        if (p.first.second <= m) contained[p.second] = 1;
        m = max(m, p.first.second);
    }

    sort(v.begin(), v.end(), cmpr);

    m = INT_MAX;
    for (auto p : v)
    {
        if (p.first.second >= m) contains[p.second] = 1;
        m = min(m, p.first.second);
    }

    for (auto b : contains) cout << b << ' ';
    cout << endl;
    for (auto b : contained) cout << b << ' ';

    
    return 0;
}