#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
 
const int MOD = 1e9 + 7;

int32_t main() {
    need_for_speed

    long long n, sum = 0; cin >> n;
    sum = n * (n + 1) / 2;
    vector<int> dp(sum * 2 + 1);
    vector<bool> v(sum * 2 + 1);
    v[sum] = true;
    dp[sum] = 1;
    for (int i = 1; i <= n; i++)
    {
        vector<int> a(sum * 2 + 1);
        vector<bool> nw(sum * 2 + 1);
        for (int j = 0; j <= 2 * sum; j++)
        {
            if (v[j]) {a[j - i] += dp[j]; a[j - i] %= MOD; a[j + i] += dp[j]; a[j + i] %= MOD; nw[j - i] = true; nw[j + i] = true;}
        }
        dp = a;
        v = nw;
    }
    
    cout << dp[sum] * 500000004 % MOD;
    
    return 0;
}