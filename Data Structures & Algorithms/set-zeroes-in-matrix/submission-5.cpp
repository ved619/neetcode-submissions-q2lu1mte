class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    bool firstRowOne = false;
    bool firstColOne = false;

    // checking if first row has zero
    for (int i = 0; i < m; ++i) {
      if (matrix[0][i] == 0) {
        firstRowOne = true;
      }
    }
    // checking if 1st col has a zero
    for (int i = 0; i < n; ++i) {
      if (matrix[i][0] == 0) {
        firstColOne = true;
      }
    }

    // for remaining rows and cols set 0's in row start and col start
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;  // set first element of row to 0
          matrix[0][j] = 0;  // set first element of col to 0
        }
      }
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        if (matrix[i][0] == 0 or matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
    if (firstRowOne) {
      for (int i = 0; i < m; ++i) {
        matrix[0][i] = 0;
      }
    }
    if (firstColOne) {
      for (int i = 0; i < n; ++i) {
        matrix[i][0] = 0;
      }
    }
  }
};
