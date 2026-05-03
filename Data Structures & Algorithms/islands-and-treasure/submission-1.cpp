class Solution {
 public:
  int dr[4] = {1, -1, 0, 0};
  int dc[4] = {0, 0, 1, -1};
  void islandsAndTreasure(vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    int n = grid.size();
    int m = grid[0].size();

    // start from treasures
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 0) {
          q.push({i, j});
        }
      }
    }

    // multisource bfs from treasures
    while (!q.empty()) {
      auto [row, col] = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (nr >= 0 and nr < n and nc >= 0 and nc < m) {
          if (grid[nr][nc] == INT_MAX) {
            grid[nr][nc] = grid[row][col] + 1;
            q.push({nr, nc});
          }
        }
      }
    }
  }
};
