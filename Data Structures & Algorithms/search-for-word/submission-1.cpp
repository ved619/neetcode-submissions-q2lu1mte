class Solution {
public:
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    int n, m;
    bool ans = false;

    bool isValid(int r, int c, const vector<vector<bool>>& isVis) {
        return r >= 0 && r < n && c >= 0 && c < m && !isVis[r][c];
    }

    void backTrack(int r, int c, const string& word,
                   vector<vector<char>>& board,
                   vector<vector<bool>>& isVis,
                   int index) {
        if (ans) return;
        if (board[r][c] != word[index]) return;
        if (index == (int)word.size() - 1) {
            ans = true;
            return;
        }

        isVis[r][c] = true;
        for (int i = 0; i < 4 && !ans; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (isValid(nr, nc, isVis) && board[nr][nc] == word[index + 1]) {
                backTrack(nr, nc, word, board, isVis, index + 1);
            }
        }
        isVis[r][c] = false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        if ((int)word.size() > n * m) return false;

        vector<vector<bool>> isVis(n, vector<bool>(m, false));
        ans = false;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    backTrack(i, j, word, board, isVis, 0);
                    if (ans) return true;
                }
            }
        }
        return false;
    }
};
