class Solution {
 public:
  vector<vector<int>> memo;
  int n, m;

  int dp(int row, int col, vector<vector<int>>& obstacleGrid) {
    if ((row < 0 or row >= n or col < 0 or col >= m) or obstacleGrid[row][col] == 1) {
      return 0;
    }
    if (row == n - 1 and col == m - 1) {
      return 1;
    }
    if (memo[row][col] != -1) {
      return memo[row][col];
    }
    return memo[row][col] = dp(row, col + 1, obstacleGrid) + dp(row + 1, col, obstacleGrid);
  }

  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    n = obstacleGrid.size();
    m = obstacleGrid[0].size();
    memo.assign(n,vector<int>(m,-1));
    return dp(0, 0, obstacleGrid);
  }
};