class Solution {
 public:
  int dr[4] = {1, -1, 0, 0};
  int dc[4] = {0, 0, 1, -1};
  int n, m;

  bool isValid(int row, int col, vector<vector<bool>>& vis) {
    if (row < 0 or row >= n or col < 0 or col >= m) {
      return false;
    }
    if (vis[row][col]) {
      return false;
    }
    return true;
  }

  int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
    int result = 1;
    vis[row][col] = true;
    for (int i = 0; i < 4; ++i) {
      int nr = row + dr[i];
      int nc = col + dc[i];
      if (isValid(nr, nc, vis) and grid[nr][nc] == 1) {
        result = result + dfs(nr, nc, grid, vis);
      }
    }
    return result;
  }
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();
    int ans = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) {
          ans = max(ans, dfs(i, j, grid, vis));
        }
      }
    }
    return ans;
  }
};
