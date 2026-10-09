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
    ListNode* res = head;
    while (res->next != nullptr) {
      ListNode* temp = new ListNode();
      ListNode* nextNode = res->next;
      int data = gcd(res->val, res->next->val);
      temp->val = data;
      res->next = temp;
      temp->next = nextNode;
      res=res->next->next;
    }
    return head;
  }
};