#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;
const int MAX = 1e6 + 31;

vector<int> spf(MAX);
vector<int> primes;

void sieve() {
    for (int i = 2; i < MAX; ++i) {
        if (spf[i]) continue;
        spf[i] = i;
        primes.emplace_back(i);
        for (int j = i * i; j < MAX; j += i) if (!spf[j]) spf[j] = i;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    sieve();

    int n; cin >> n;
    vector<int> v(n);
    for (auto& i : v) cin >> i;
    
    int ans = 0;
    vector<int> dp(MAX);

    int counter = 0;
    for (auto i : v) {
        if (i == 1) {ans += counter++; continue;}
        vector<int> p = {spf[i]};
        i /= spf[i];
        while (i > 1) {
            if (spf[i] != p.back()) p.push_back(spf[i]);
            i /= spf[i];
        }

        int k = p.size(), coprime = 0;
        for (i = 1; i < (1 << k); i++) {
            int m = 1;
            for (int j = 0; j < k; j++) {
                if (i & (1 << j)) m *= p[j];
            }

            int popcnt = __builtin_popcount(i);
            if (popcnt & 1) coprime += dp[m];
            else coprime -= dp[m];

            dp[m]++;
        }
        ans += counter - coprime;
        counter++;
    }

    cout << ans;
    
    return 0;
}