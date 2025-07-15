#include <bits/stdc++.h>

#define need_for_speed                                                                                                 \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);                                                                                                        \
    cout.tie(0)
#define ll long long
using namespace std;

int main()
{
    need_for_speed;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> parent(n + 1, -1);
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    if (parent[n] == -1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        vector<int> path;
        for (int v = n; ~v; v = parent[v])
        {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for (int v : path)
        {
            cout << v << " ";
        }
    }

    return 0;
}