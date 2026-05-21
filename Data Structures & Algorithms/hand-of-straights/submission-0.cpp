class Solution {
 public:
  bool isNStraightHand(vector<int>& hand, int groupSize) {
    // Total cards must divide evenly
    if (hand.size() % groupSize != 0) return false;

    // Count frequencies
    map<int, int> freq;

    for (int card : hand) {
      freq[card]++;
    }

    // Process cards from smallest to largest
    for (auto& [card, count] : freq) {
      // While this card still exists
      while (freq[card] > 0) {
        // Try forming one complete group
        for (int i = 0; i < groupSize; i++) {
          int curr = card + i;

          // Missing required card
          if (freq[curr] == 0) return false;

          freq[curr]--;
        }
      }
    }

    return true;
  }
};
