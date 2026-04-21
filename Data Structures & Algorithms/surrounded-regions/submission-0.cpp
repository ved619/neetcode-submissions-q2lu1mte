class Solution {
 public:
  int n, m;
  int dr[4] = {1, -1, 0, 0};
  int dc[4] = {0, 0, 1, -1};
  void dfs(int r, int c, vector<vector<char>>& board) {
    // boundary check
    if (r < 0 or r >= n or c < 0 or c >= m) {
      return;
    }
    if (board[r][c] != 'O') {
      return;
    }
    board[r][c] = 'T';
    for (int i = 0; i < 4; ++i) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      dfs(nr, nc, board);
    }
  }
  void solve(vector<vector<char>>& board) {
    n = board.size();
    m = board[0].size();

    // step1 : run DFS on boundary "0"
    for (int i = 0; i < n; ++i) {
      if (board[i][0] == 'O') {
        dfs(i, 0, board);
      }
      if (board[i][m - 1] == 'O') {
        dfs(i, m - 1, board);
      }
    }
    for (int j = 0; j < m; ++j) {
      if (board[0][j] == 'O') {
        dfs(0, j, board);
      }
      if (board[n - 1][j] == 'O') {
        dfs(n - 1, j, board);
      }
    }
    // step 2: flip and restore
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        } else if (board[i][j] == 'T') {
          board[i][j] = 'O';
        }
      }
    }
  }
};
