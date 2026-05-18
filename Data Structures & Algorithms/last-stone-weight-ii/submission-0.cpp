class Solution {
 public:
  int total;
  vector<vector<int>> memo;
  int solve(int i, int currSum, vector<int>& stones) {
    if (i == stones.size()) {
      return abs(total - 2 * currSum);
    }
    if (memo[i][currSum] != -1) {
      return memo[i][currSum];
    }
    // take rock
    int take = solve(i + 1, currSum + stones[i], stones);
    // skip
    int skip = solve(i + 1, currSum, stones);
    return memo[i][currSum] = min(take, skip);
  }
  int lastStoneWeightII(vector<int>& stones) {
    total = 0;
    for (int x : stones) {
      total += x;
    }
    int n = stones.size();
    memo.resize(n, vector<int>(total + 1, -1));
    return solve(0, 0, stones);
  }
};