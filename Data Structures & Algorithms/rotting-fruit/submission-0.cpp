class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    int fresh = 0;

    // add rotten fruit to queue + count fresh
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 2) {
          q.push({i, j});
        } else if (grid[i][j] == 1) {
          ++fresh;
        }
      }
    }
    // directions
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    int time = 0;

    // BFS
    while (!q.empty() and fresh > 0) {
      int sizeQueue = q.size();

      for (int i = 0; i < sizeQueue; ++i) {
        auto [r, c] = q.front();
        q.pop();

        for (int j = 0; j < 4; ++j) {
          int nr = r + dr[j];
          int nc = c + dc[j];

          // check if in bounds
          if (nr < 0 or nr >= n or nc < 0 or nc >= m) {
            continue;
          }

          // can only rot fresh fruits
          if (grid[nr][nc] != 1) {
            continue;
          }
          grid[nr][nc] = 2;
          q.push({nr, nc});
          fresh--;
        }
      }
      ++time;
    }
    if (fresh) {
      return -1;
    }
    return time;
  }
};
