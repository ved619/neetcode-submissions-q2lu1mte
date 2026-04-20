class Solution {
 public:
  int dr[4] = {1, -1, 0, 0};
  int dc[4] = {0, 0, 1, -1};
  int n, m;

  bool isValid(int r, int c, vector<vector<bool>>& vis) {
    if (r < 0 or r >= n or c < 0 or c >= m) {
      return false;
    }
    if (vis[r][c]) {
      return false;
    }
    return true;
  }
  int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
    vis[row][col] = true;
    int area = 1;
    for (int i = 0; i < 4; ++i) {
      int nr = row + dr[i];
      int nc = col + dc[i];
      if (isValid(nr, nc, vis) and grid[nr][nc] == 1) {
        area += dfs(nr, nc, grid, vis);
      }
    }
    return area;
  }
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int result = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!vis[i][j] and grid[i][j] == 1) {
          int area = dfs(i, j, grid, vis);
          result = max(result, area);
        }
      }
    }
    return result;
  }
};
