#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int32_t main() {
    need_for_speed;
    
    int n, target; 
    cin >> n >> target;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first, v[i].second = i+1;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            if ((v[l].first + v[r].first + v[i].first) == target) {cout << v[i].second << ' ' << v[l].second << ' ' << v[r].second; return 0;}
            else if ((v[l].first + v[r].first + v[i].first) < target) l++;
            else r--;
        }
    }
    cout << "IMPOSSIBLE";
    
    return 0;
}