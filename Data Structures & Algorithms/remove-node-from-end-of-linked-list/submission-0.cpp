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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* prev, *ahead;
        prev=ahead=dummy;
        for(int i=0;i<=n;++i){
            ahead=ahead->next;
        }
        while(ahead){
            prev=prev->next;
            ahead=ahead->next;
        }
        prev->next=prev->next->next;
        return dummy->next;
    }
};
