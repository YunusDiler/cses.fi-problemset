#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;

void fill(vector<vector<int>>& grid, int x, int y) {
  grid[x][y] = 4;
  grid[x][y + 2] = 4;
  grid[x + 3][y] = 4;
  grid[x + 2][y + 4] = 4;

  grid[x][y + 4] = 1;
  grid[x + 1][y + 7] = 1;
  grid[x + 2][y + 6] = 1;
  grid[x + 3][y + 5] = 1;
  grid[x + 3][y + 3] = 1;

  grid[x + 1][y + 1] = 2;
  grid[x + 1][y + 3] = 2;
  grid[x + 3][y + 2] = 2;
  grid[x + 3][y + 8] = 2;

  grid[x][y + 5] = 3;
  grid[x][y + 7] = 3;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int t; cin >> t;
  while (t--)
  {
    int n, m; cin >> n >> m;
    if (n * m % 3 || min(n, m) < 2 || (n * m % 2 && min(n, m) == 3)) {
      cout << "NO" << endl;
      continue;
    } 
    cout << "YES" << endl;

    bool swapped = 0;
    if (n % 3 == 0) {swap(n, m); swapped = 1;}

    vector<vector<int>> grid(n, vector<int>(m));
    if (n * m % 2 == 1) {
      fill(grid, 0, 0);
      for (int i = 9; i < m; i += 3) {
        grid[0][i] = 4;
        grid[0][i + 2] = 2;
      }
      for (int i = 9; i < m; i += 2) {
        grid[2][i] = 4;
        grid[3][i + 1] = 2;
      }

      for (int i = 5; i < n; i += 2) {
        for (int j = 0; j < m; j += 3) {
          grid[i][j] = 4;
          grid[i][j + 2] = 2;
        }
      }
    }
    else {
      if (n % 3 == 0) {
        if (m % 2 == 0) {
          for (int j = 0; j < n; j += 3) {
            for (int i = 0; i < m; i += 2) {
              grid[j][i] = 4;
              grid[j + 1][i + 1] = 2;
            }
          }
        }
        else {
          for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < m - 3; j += 2) {
              grid[i][j] = 4;
              grid[i + 1][j + 1] = 2;
            }
          }
          for (int i = 0; i < n; i += 2) {
            grid[i][m - 3] = 4;
            grid[i][m - 1] = 2;
          }
        }
      }
      else {
        if (n % 2 == 0) {
          for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < m; j += 3) {
              grid[i][j] = 4;
              grid[i][j + 2] = 2;
            }
          }
        }
        else {
          for (int i = 0; i < m; i += 2) {
            grid[0][i] = 4;
            grid[1][i + 1] = 2;
          }
          for (int i = 3; i < n; i += 2) {
            for (int j = 0; j < m; j += 3) {
              grid[i][j] = 4;
              grid[i][j + 2] = 2;
            }
          }
        }
      }
    }


    vector<vector<char>> ans(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int val = grid[i][j];
        char c;
        if (val) {
          c = 'A' + (4 * (i % 4) + (j % 4));
        } else continue;

        ans[i][j] = c;
        if (val == 1) {
          ans[i + 1][j] = c;
          ans[i + 1][j + 1] = c;
        }
        else if (val == 2) {
          ans[i + 1][j] = c;
          ans[i + 1][j - 1] = c;
        }
        else if (val == 3) {
          ans[i][j + 1] = c;
          ans[i + 1][j + 1] = c;
        }
        else if (val == 4) {
          ans[i + 1][j] = c;
          ans[i][j + 1] = c;
        }
      }
    }

    if (swapped) {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          cout << ans[j][i];
        }
        cout << endl;
      }
    }
    else {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << ans[i][j];
        }
        cout << endl;
      }
    }
  }
  
  
  
  return 0;
}