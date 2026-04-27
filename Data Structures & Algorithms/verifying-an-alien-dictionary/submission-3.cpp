class Solution {
 public:
  bool isAlienSorted(vector<string>& words, string order) {
    vector<int> v(26);

    // order
    for (int i = 0; i < order.length(); ++i) {
      v[order[i] - 'a'] = i;
    }

    // comparing adjacent strings
    for (int i = 0; i < words.size() - 1; ++i) {
      string word1 = words[i];
      string word2 = words[i + 1];
      int l = 0;
      while (l < word1.size() and l < word2.size()) {
        if (word1[l] == word2[l]) {
          ++l;
          continue;
        }
        if (v[word1[l] - 'a'] > v[word2[l] - 'a']) {
          return false;
        }
        break;
      }
      if (l == word2.size() and word1.size() > word2.size()) {
        return false;
      }
    }
    return true;
  }
};