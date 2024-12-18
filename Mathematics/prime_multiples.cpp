#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k; cin >> n >> k;
    vector<int> v(k);
    for (auto& i : v) cin >> i;

    int ans = 0;
    for (int i = 1; i < (1 << k); i++) {
        int count = __builtin_popcountll(i);
        __int128 s = 1;
        for (int j = 0; j < k; j++) {
            if ( (1 << j) & i) s *= v[j];
            if (s > 1e18) s = 0;
        }
        if (s == 0) continue;

        if (count & 1) ans += n / s;
        else ans -= n / s;
    }
    
    cout << ans;
    
    return 0;
}