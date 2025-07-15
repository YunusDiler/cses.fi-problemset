#include <bits/stdc++.h>

using namespace std;

#define needforspeed                                                                                                   \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define ll long long

int main()
{
    needforspeed 
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<vector<char>> parent(n, vector<char>(m));
    int Ax, Ay;
    vector<pair<int, int>> monsters;
    for (int y = 0; y < n; y++)
    {
        cin >> grid[y];
        for (int x = 0; x < m; x++)
        {
            if (grid[y][x] == 'A')
            {
                Ax = x;
                Ay = y;
            }
            else if (grid[y][x] == 'M')
            {
                monsters.push_back({y, x});
            }
        }
    }

    queue<pair<int, int>> q;
    queue<pair<int, int>> ambush;
    vector<vector<bool>> visited(n, vector<bool>(m));

    for (int i = 0; i < monsters.size(); i++)
    {
        ambush.push(monsters[i]);
        visited[monsters[i].first][monsters[i].second] = true;
    }

    q.push({Ay, Ax});

    while (!q.empty())
    {

        int horde = ambush.size();
        while (horde--)
        {
            auto [my, mx] = ambush.front();
            ambush.pop();


            if (mx > 0 && grid[my][mx - 1] == '.' && !visited[my][mx - 1])
            {
                ambush.push({my, mx - 1});
                visited[my][mx - 1] = true;
            }
            if (mx < m - 1 && grid[my][mx + 1] == '.' && !visited[my][mx + 1])
            {
                ambush.push({my, mx + 1});
                visited[my][mx + 1] = true;
            }
            if (my > 0 && grid[my - 1][mx] == '.' && !visited[my - 1][mx])
            {
                ambush.push({my - 1, mx});
                visited[my - 1][mx] = true;
            }
            if (my < n - 1 && grid[my + 1][mx] == '.' && !visited[my + 1][mx])
            {
                ambush.push({my + 1, mx});
                visited[my + 1][mx] = true;
            }
        }

        horde = q.size();

        while (horde--)
        {
            auto [y, x] = q.front();
            q.pop();


            if (x == 0 || y == 0 || x == m - 1 || y == n - 1)
            {
                vector<char> ans;
                while (grid[y][x] != 'A')
                {
                    char c = parent[y][x];
                    ans.push_back(c);
                    if (c == 'U')
                        y++;
                    else if (c == 'D')
                        y--;
                    else if (c == 'L')
                        x++;
                    else
                        x--;
                }
                cout << "YES\n" << ans.size() << endl;
                for (int i = ans.size() - 1; i >= 0; i--)
                {
                    cout << ans[i];
                }
                return 0;
            }

            if (x > 0 && grid[y][x - 1] == '.' && !visited[y][x - 1] && !parent[y][x - 1])
            {
                q.push({y, x - 1});
                parent[y][x - 1] = 'L';
            }
            if (x < m - 1 && grid[y][x + 1] == '.' && !visited[y][x + 1] && !parent[y][x + 1])
            {
                q.push({y, x + 1});
                parent[y][x + 1] = 'R';
            }
            if (y > 0 && grid[y - 1][x] == '.' && !visited[y - 1][x] && !parent[y - 1][x])
            {
                q.push({y - 1, x});
                parent[y - 1][x] = 'U';
            }
            if (y < n - 1 && grid[y + 1][x] == '.' && !visited[y + 1][x] && !parent[y + 1][x])
            {
                q.push({y + 1, x});
                parent[y + 1][x] = 'D';
            }
        }


    }

    cout << "NO";

    return 0;
}
