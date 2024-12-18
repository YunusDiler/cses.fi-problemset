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
    
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for (auto& i : v) cin >> i;

    int N = 1 << n;
    vector<pair<int, int>> vp(N, {INF, x});
    vp[0] = {1, 0};

    for (int i = 0; i < N; i++) {
        for (int p = 0; p < n; p++) {
            if ((1 << p) & i) continue;

            int num = i ^ (1 << p);
            if (vp[num].first >= vp[i].first) {
                int a = vp[i].first + (vp[i].second + v[p] > x), b = vp[i].second + v[p];
                if (b > x) b = v[p];
                if (a < vp[num].first) vp[num] = {a, b};
                if (a == vp[num].first) vp[num] = {a, min(b, vp[num].second)};
            }
        }
    }

    cout << vp[N - 1].first;
    

    return 0;
}