#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int n, res = 0;
vector<array<int, 3>> projects;
vector<int> prices;



int32_t main() {
    need_for_speed
    
    cin >> n;
    projects.resize(n);
    prices.resize(n);
    for (int i = 0; i < n; i++)
        cin >> projects[i][1] >> projects[i][0] >> projects[i][2];
    
    sort(projects.begin(), projects.end());

    map<int, int> mp;
    mp[0] = 0;
    int m = 0;
    for (auto &p : projects)
    {
        auto it = mp.lower_bound(p[1]);
        it--;
        mp[p[0]] = m;
        mp[p[0]] = max(it->second + p[2], mp[p[0]]);
        m = max(m, mp[p[0]]);
    }

    cout << m;
    
    
    return 0;
}