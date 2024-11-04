#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;


int solve(int n, int k) {
    if (n == 1) return 1;
    if (k <= (n + 1) / 2) return 2 * k == n + 1 ? 1 : 2 * k;
    int a = 2 * (solve(n / 2, k - (n + 1) / 2) + (n & 1)) - 1;
    return a;
}

int32_t main() {
    need_for_speed
    
    int q; cin >> q;
    while (q--)
    {
        int n, k; cin >> n >> k;
        cout << solve(n, k) << endl;
    }

    return 0;
}