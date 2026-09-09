/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* insertGreatestCommonDivisors(ListNode* head) {
    ListNode* tmp = head;
    while (tmp->next != nullptr) {
      int a = tmp->val;
      int b = tmp->next->val;
      int val = gcd(a, b);
      ListNode* x = new ListNode(val);
      ListNode* y = tmp->next;
      tmp->next = x;
      x->next = y;
      tmp = y;
    }
    return head;
  }
};