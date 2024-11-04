#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;

int fp(int a, int b = MOD - 2) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> fact(1e6 + 1);
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 1e6; i++) fact[i] = fact[i - 1] * i % MOD;

    int t; cin >> t;
    while (t--)
    {
        int a, b; cin >> a >> b;
        cout << (fact[a] * fp(fact[b]) % MOD) * fp(fact[a - b]) % MOD << endl;
    }   
    
    
    
    return 0;
}