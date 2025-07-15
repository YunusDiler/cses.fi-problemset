#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;




int32_t main() {
    need_for_speed
    
    int n, sum = 0; cin >> n;
    vector<int> v(n);
    set<int> s; s.insert(0);
    for (int i = 0; i < n; i++) {cin >> v[i]; sum += v[i];}
    sort(v.begin(), v.end());

    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j > 0; j--) {
            if (j - v[i] >= 0 && dp[j - v[i]]) {
                dp[j] = 1;
                s.insert(j);
            }
        }
    }
    
    s.erase(0);
    cout << s.size() << endl;
    for (auto& x : s) cout << x << ' ';
    
    return 0;
}