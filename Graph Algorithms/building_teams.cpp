#include <bits/stdc++.h>

#define ll long long
#define need_for_speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main() {
    need_for_speed
    
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    }
    
    vector<int> colors(n + 1);
    vector<bool> visited(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
        if (colors[i] == 0) colors[i] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (visited[u]) continue;
            visited[u] = true;
            
            int c = colors[u];

            for (auto v : adj[u])
            {
                if (colors[v] - c == 0)
                {
                    cout << "IMPOSSIBLE";
                    return 0;
                }
                colors[v] = c == 1 ? 2 : 1;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << colors[i] << ' ';
    }
    
    
    return 0;
}