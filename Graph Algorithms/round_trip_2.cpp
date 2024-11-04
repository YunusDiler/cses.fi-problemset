#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
       int u, v; cin >> u >> v;
       adj[u].push_back(v);
    }
    
    vector<int> vis(n + 1);
    vector<int> parent(n + 1);

    stack<int> s;
    
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            s.push(i);
            count++;
        }

        while (!s.empty()) {
            int from = s.top();
            s.pop();

            vis[from] = count;
            for (auto to : adj[from]) {
                if (vis[to] == count) {
                    parent[to] = from;
                    deque<int> ans;
                    ans.push_back(from);
                    int u = parent[from];
                    while (u != from) {
                        ans.push_front(u);
                        u = parent[u];
                    }
                    cout << ans.size() + 1 << endl;
                    cout << from << ' ';
                    for (auto& i : ans) cout << i << ' ';
                    return 0;
                }
                else {
                    s.push(to);
                    parent[to] = from;
                }
            }
        }
    }

    cout << "IMPOSSIBLE";
    
    return 0;
}