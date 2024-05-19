#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MOD = 1e9 + 7;

using namespace std;

int32_t main() {
    need_for_speed
    
    vector<int> dp(1000031);
    dp[1] = 2;
    dp[2] = 8;
    for (int i = 3; i < 1000031; i++) {dp[i] = 6 * dp[i - 1] - 7 * dp[i - 2] + 8 * MOD; dp[i] %= MOD;}

    int n; cin >> n;
    while (cin >> n) cout << dp[n] << endl;
    
    return 0;
}