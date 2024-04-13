#include <bits/stdc++.h>

#define int long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int32_t main() {
    need_for_speed
    
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    }
    
    vector<int> parent(n + 1);
    vector<bool> visited(n + 1);

    stack<int> s;
    
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i]) s.push(i);

        while (!s.empty())
        {
            int u = s.top();
            s.pop();
            visited[u] = true;
            for (auto v : adj[u])
            {
                if (v == parent[u]) continue;
                parent[v] = u;
                if (visited[v])
                {
                    int start = v;
                    vector<int> ans = {v};
                    while (u != start)
                    {
                        ans.push_back(u);
                        u = parent[u];
                    }
                    ans.push_back(v);

                    cout << ans.size() << endl;
                    for (auto x : ans) cout << x << ' ';
                    return 0;
                }
                s.push(v);
            }
        }
    }
    cout << "IMPOSSIBLE";

    
    return 0;
}