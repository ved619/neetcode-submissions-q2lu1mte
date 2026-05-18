class Solution {
 public:
  vector<vector<int>> memo;
  int dp(int i, int j, vector<int>& piles) {
    if (i == j) {
      return piles[i];
    }
    if (memo[i][j] != -1) {
      return memo[i][j];
    }
    int takeLeft = piles[i] - dp(i + 1, j, piles);
    int takeRight = piles[j] - dp(i, j - 1, piles);
    return memo[i][j] = max(takeLeft, takeRight);
  }
  bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    memo.resize(n, vector<int>(n, -1));
    return dp(0, n - 1, piles) > 0;
  }
};