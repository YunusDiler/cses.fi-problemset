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
    vector<bool> visited(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    queue<int> p;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (!visited[u])
        {
            ans.push_back(u);
            p.push(u);
            while (!p.empty())
            {
                auto c = p.front();
                p.pop();
                visited[c] = true;
                for (auto v : adj[c])
                {
                    if (!visited[v])
                    {
                        p.push(v);
                    }
                }
            }
        }
    }
    cout << ans.size() - 1 << endl;
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << ' ' << ans[i + 1] << endl;
    }

    return 0;
}