class Solution {
 public:
  vector<vector<int>> memo;
  int solve(int i, int j, string& word1, string& word2) {
    int n = word1.size();
    int m = word2.size();

    if (i == n) {
      return m - j;
    }
    if (j == m) {
      return n - i;
    }
    if (memo[i][j] != -1) {
      return memo[i][j];
    }
    if (word1[i] == word2[j]) {
      return solve(i + 1, j + 1, word1, word2);
    }

    int insertOp = 1 + solve(i, j + 1, word1, word2);
    int deleteOp = 1 + solve(i + 1, j, word1, word2);
    int replaceOp = 1 + solve(i + 1, j + 1, word1, word2);
    return memo[i][j] = min({insertOp, deleteOp, replaceOp});
  }
  int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    memo.resize(n, vector<int>(m, -1));
    return solve(0, 0, word1, word2);
  }
};
