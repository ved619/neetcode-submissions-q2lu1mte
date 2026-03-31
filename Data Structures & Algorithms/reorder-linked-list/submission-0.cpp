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
    void reorderList(ListNode* head) {
        ListNode* slow, *fast;
        slow=fast=head;
        //finding middle
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //disconnecting first and secondHalf
        ListNode* firstHalf=head;
        ListNode *secondHalf=slow->next;
        slow->next=nullptr;
        //reversing the second half
        ListNode*prev=nullptr;
        while(secondHalf){
            ListNode* temp=secondHalf->next;
            secondHalf->next=prev;
            prev=secondHalf;
            secondHalf=temp;
        }
        secondHalf=prev;
        //merge 2halves together
        while(secondHalf){
            ListNode* temp1=firstHalf->next;
            ListNode* temp2=secondHalf->next;
            firstHalf->next=secondHalf;
            secondHalf->next=temp1;
            firstHalf=temp1;
            secondHalf=temp2;
        }
    }
};
