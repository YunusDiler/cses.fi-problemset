#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> ch(2e5 + 5);
vector<vector<int>> v(2e5 + 5);

void dfs(int node) {
    for (auto x : v[node]) dfs(x);
    for (auto x : v[node]) ch[node] += ch[x];
    ch[node] += v[node].size();
}

int32_t main() {
    need_for_speed
    
    int n; cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int x; cin >> x;
        v[x].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) cout << ch[i] << ' ';

    
    
    
    return 0;
}