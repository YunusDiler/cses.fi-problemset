#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;



int32_t main() {
    need_for_speed
    
    int n, x; cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];

    vector<pair<int, int>> dp(1 << n);
    
    dp[0].first = 1;
    dp[0].second = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < 20; j++)
        {
            
        }
    }
    
    
    return 0;
}