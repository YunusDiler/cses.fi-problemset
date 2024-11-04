#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

constexpr int MOD = 1e9 + 7;

int fp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return fp(a, MOD - 2);
}

int32_t main() {
    need_for_speed
    
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (auto& p : v) cin >> p.first >> p.second;
    
    int number = 1, sum = 1, product = 1, number_but_mod_minus_1 = 1;

    for (auto &p : v) {
        number = (p.second + 1) * number % MOD;

        sum = ((((fp(p.first, p.second + 1) - 1) + MOD) % MOD) * inv(p.first - 1) % MOD) * sum % MOD;

        product = fp(product, p.second + 1) * fp(fp(p.first, p.second * (p.second + 1) / 2), number_but_mod_minus_1) % MOD;
        number_but_mod_minus_1 = (p.second + 1) * number_but_mod_minus_1 % (MOD - 1);
    }

    cout << number << ' ' << sum << ' ' << product;

    return 0;
}