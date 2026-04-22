class Solution {
 public:
  int n, m;
  int dr[4] = {1, -1, 0, 0};
  int dc[4] = {0, 0, 1, -1};

  bool canVisit(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
    if (row < 0 or row >= n or col < 0 or col >= m) {
      return false;
    }
    if (vis[row][col]) {
      return false;
    }
    return true;
  }
  int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
    vis[row][col] = true;
    int result = 1;
    // explore neighbors
    for (int i = 0; i < 4; ++i) {
      int nr = row + dr[i];
      int nc = col + dc[i];
      if (canVisit(nr, nc, grid, vis) and grid[nr][nc] == 1) {
        result += dfs(nr, nc, grid, vis);
      }
    }
    return result;
  }
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int result=0;
    // dfs from 1's positions
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) {
          if (vis[i][j] == false) {
            result=max(result,dfs(i, j, grid, vis));
          }
        }
      }
    }
    return result;
  }
};
