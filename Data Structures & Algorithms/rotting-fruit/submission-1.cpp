class Solution {
 public:
  int dr[4] = {1, -1, 0, 0};
  int dc[4] = {0, 0, 1, -1};
  int n, m;

  bool isValid(int row, int col) {
    if (row < 0 or row >= n or col < 0 or col >= m) {
      return false;
    }
    return true;
  }
  int orangesRotting(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();
    queue<pair<int, int>> q;
    int freshFruits = 0;
    bool spread = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 2) {
          q.push({i, j});
        }
        if (grid[i][j] == 1) {
          ++freshFruits;
        }
      }
    }
    int time = 0;
    while (!q.empty()) {
      int level = q.size();
      for (int i = 0; i < level; ++i) {
        auto [row, col] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
          int nr = row + dr[i];
          int nc = col + dc[i];
          if (isValid(nr, nc) and grid[nr][nc] == 1) {
            q.push({nr, nc});
            grid[nr][nc] = 2;
            --freshFruits;
            spread = true;
          }
        }
      }
      if (spread) {
        ++time;
      }
      spread = false;
    }
    if (freshFruits == 0) {
      return time;
    }
    return -1;
  }
};
