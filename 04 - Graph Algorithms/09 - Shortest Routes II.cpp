#include <bits/stdc++.h>

#define int long long
#define need_for_speed                                                                                                 \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

using namespace std;

int32_t main()
{
    need_for_speed;

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, LLONG_MAX / 2)); //adj matrix 
    for (int i = 0; i < m; i++)
    {
        int u, v, dist;
        cin >> u >> v >> dist;
        adj[u][v] = min(dist, adj[u][v]); // multiple roads between edges
        adj[v][u] = min(dist, adj[v][u]);
    }
    for (int i = 1; i <= n; i++)
        adj[i][i] = 0;

    //Floyd-Warsahll O(n^3)
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (adj[i][j] > adj[i][k] + adj[k][j]) //LLONG_MAX / 2 -> !overflow
                    adj[i][j] = adj[i][k] + adj[k][j];


    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (adj[a][b] == LLONG_MAX / 2)
            cout << -1 << endl;
        else
            cout << adj[a][b] << endl;
    }

    return 0;
}
