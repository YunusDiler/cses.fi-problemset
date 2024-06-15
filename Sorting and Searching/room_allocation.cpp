#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

struct Room {
    int l;
    int r;
    int id;
};

bool cmp(const Room &a, const Room &b) {
    return a.r < b.r;
}

int32_t main() {
    need_for_speed
    
    int n; cin >> n;
    vector<Room> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].l >> v[i].r;
        v[i].id = i;
    }

    sort(v.begin(), v.end(), cmp);
    
    multimap<int, int> mp;

    vector<int> ans(n);
    int room = 1, m = 0;
    for (int i = 0; i < n; i++)
    {   
        auto it = mp.upper_bound(-v[i].l);
        if (it == mp.end()) {
            ans[i] = room;
            mp.insert({-v[i].r, room});
            room++;
        }
        else {
            ans[i] = it->second;
            mp.erase(it);
            mp.insert({-v[i].r, ans[i]});
        }
        m = max(ans[i], m);
    }

    vector<int> res(n);
    for (int i = 0; i < n; i++) res[v[i].id] = ans[i];
    

    cout << m << endl;
    for (auto i : res) cout << i << ' ';

    return 0;
}