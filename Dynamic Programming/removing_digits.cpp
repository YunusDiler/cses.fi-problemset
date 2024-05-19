#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int n;
vector<int> dp;

void solve()
{
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int i = 1; i < 1000001; i *= 10)
        {
            int a = t % (i * 10) / i;
            if (a && t - a >= 0)
            {
                if(dp[t] + 1 < dp[t - a])
                {
                    q.push(t - a);
                    dp[t - a] = dp[t] + 1;
                }
            }
        }
    }
}

int32_t main() {
    need_for_speed
    
    cin >> n;
    dp.resize(n + 1, INT_MAX);
    dp[n] = 0;
    solve();
    cout << dp[0];
    
    
    return 0;
}