class Solution {
 public:
  vector<int> memo;
  int solve(int n) {
    if (n == 0) {
      return 0;
    }
    if (memo[n] != -1) {
      return memo[n];
    }
    int ans = INT_MAX;
    for (int i = 1; i * i <= n; ++i) {
      int square = i * i;
      ans = min(ans, 1 + solve(n - square));
    }
    return memo[n] = ans;
  }
  int numSquares(int n) {
    memo.resize(n + 1, -1);
    return solve(n);
  }
};