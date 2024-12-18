#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;

int fp(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return fp(a, MOD - 2);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    n *= n;
    int a = fp(2, n / 4), b = fp(2, n / 2);

    int ans = 0;
    ans += a;

    ans += a * (a - 1) % MOD * inv(2);
    ans %= MOD;

    ans += b * (b - 1) % MOD * inv(4);
    if (n & 1) ans *= 2;
    ans %= MOD;


    cout << ans;
    
    
    return 0;
}