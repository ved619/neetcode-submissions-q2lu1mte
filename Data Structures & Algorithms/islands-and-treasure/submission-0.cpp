class Solution {
 public:
  void islandsAndTreasure(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 0) {
      return;
    }
    int m = grid[0].size();
    queue<pair<int, int>> q;

    // step1: push all treasures into queue
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 0) {
          q.push({i, j});
        }
      }
    }
    // directions
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    // step 2: BFS

    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        // check bounds
        if (nr < 0 or nr >= n or nc < 0 or nc >= m) {
          continue;
        }
        // only process land
        if (grid[nr][nc] != INT_MAX) {
          continue;
        }
        grid[nr][nc] = grid[r][c] + 1;

        // push into queue
        q.push({nr, nc});
      }
    }
  }
};
