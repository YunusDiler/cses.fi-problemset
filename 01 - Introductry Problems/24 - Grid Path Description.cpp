#include <iostream>

using namespace std;

#define UNDETERMINED -1

#define N 7
bool grid[N + 2][N + 2] = {0};

const int xMove[4] = {1, 0, -1, 0};
const int yMove[4] = {0, 1, 0, -1};

#define PATH_LENGTH (N * N - 1)
int path[PATH_LENGTH];

int search(int x, int y, int len) {
  grid[x][y] = true;
  int result = 0;

  for (int i = 0; i < 4; i++) {
    if (path[len] != UNDETERMINED && path[len] != i) continue;

    int nx = x + xMove[i];
    int ny = y + yMove[i];

    if (nx == 1 && ny == N) {
      result += len + 1 == PATH_LENGTH;
      continue;
    }

    if ((len + 1 == PATH_LENGTH) || grid[nx][ny] ||
        (grid[nx][ny - 1] && grid[nx][ny + 1] && !grid[nx - 1][ny] &&
         !grid[nx + 1][ny]) ||
        (grid[nx - 1][ny] && grid[nx + 1][ny] && !grid[nx][ny - 1] &&
         !grid[nx][ny + 1])) {
      continue;
    }

    result += search(nx, ny, len + 1);
  }

  grid[x][y] = false;
  return result;
}

int main() {
  for (int i = 0; i < N + 2; i++) {
    grid[0][i] = true;
    grid[i][0] = true;
    grid[N + 1][i] = true;
    grid[i][N + 1] = true;
  }

  string s;
  cin >> s;
  for (int i = 0; i < PATH_LENGTH; i++) {
    switch (s[i]) {
      case 'R':
        path[i] = 0;
        break;
      case 'D':
        path[i] = 1;
        break;
      case 'L':
        path[i] = 2;
        break;
      case 'U':
        path[i] = 3;
        break;
      default:
        path[i] = UNDETERMINED;
        break;
    }
  }

  int count = search(1, 1, 0);
  cout << count;
  return 0;
}