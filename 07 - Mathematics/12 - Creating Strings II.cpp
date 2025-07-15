#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int MOD = 1e9 + 7;

int fp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    need_for_speed
    
    string s; cin >> s;
    int n = s.size();
    vector<int> v(n + 1);
    v[1] = 1;
    for (int i = 2; i <= n; i++) v[i] = v[i - 1] * i % MOD;
    vector<int> count(26);
    for (char c : s) count[c - 'a']++;

    int ans = v[n];
    for (auto c : count) if (c) ans = ans * fp(v[c], MOD - 2) % MOD;
    
    cout << ans;
    
    return 0;
}