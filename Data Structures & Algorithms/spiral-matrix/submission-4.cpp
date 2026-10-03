class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int left = 0, top = 0;
    int right = matrix[0].size() - 1;
    int bottom = matrix.size() - 1;
    vector<int> result;

    while (top <= bottom and left <= right) {
      for (int i = left; i <= right; ++i) {          // fix 1
        result.push_back(matrix[top][i]);
      }
      ++top;
      for (int i = top; i <= bottom; ++i) {
        result.push_back(matrix[i][right]);
      }
      --right;
      if (top <= bottom) {                           // fix 2
        for (int i = right; i >= left; --i) {
          result.push_back(matrix[bottom][i]);
        }
        --bottom;                                    // fix 3
      }
      if (left <= right) {                           // fix 2
        for (int i = bottom; i >= top; --i) {
          result.push_back(matrix[i][left]);
        }
        ++left;
      }
    }
    return result;
  }
};