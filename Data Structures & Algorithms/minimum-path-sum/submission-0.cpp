class Solution {
 public:
  int n, m;
  vector<vector<int>> memo;
  int solve(int row, int col, vector<vector<int>>& grid) {
    if (row >= n or col >= m) {
      return INT_MAX;
    }
    if (row == n - 1 and col == m - 1) {
      return grid[row][col];
    }
    if (memo[row][col] != -1) {
      return memo[row][col];
    }
    int down = solve(row + 1, col, grid);
    int right = solve(row, col + 1, grid);
    return memo[row][col] = grid[row][col] + min(down, right);
  }
  int minPathSum(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();
    memo.resize(n, vector<int>(m, -1));
    return solve(0, 0, grid);
  }
};