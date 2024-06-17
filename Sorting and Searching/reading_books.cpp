#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int32_t main() {
    need_for_speed
    
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    sort(v.begin(), v.end());
    
    int sum = 0;
    for (int i = 0; i < n - 1; i++) sum += v[i];
    if (v[n - 1] > sum) cout << 2 * v[n - 1];
    else cout << sum + v[n - 1];
    
    return 0;
}