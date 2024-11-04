#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> v(1e6 + 1);
    for (int i = 2; i <= 1e6; i++) {
        for (int j = i; j <= 1e6; j += i) {
            ++v[j];
        }
    }

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        cout << v[n] + 1 << endl;
    }
    
    
    
    return 0;
}