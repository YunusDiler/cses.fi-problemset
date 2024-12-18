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
    
    cout << fixed << setprecision(6);
 
    int n; cin >> n;
    vector<int> v(n);
    for (auto& i : v) cin >> i;
    
    double ans = 0;
 
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int a;
            if (v[i] <= v[j]) a = v[i] * (v[i] - 1) / 2;
            else a = v[j] * (v[j] - 1) / 2 + (v[i] - v[j]) * v[j];
 
            ans += ((double)a / (double)(v[i] * v[j])) * 1000;
        }
    }
    
 
    
    cout << ans / 1000 << endl;
    
    
    return 0;
}