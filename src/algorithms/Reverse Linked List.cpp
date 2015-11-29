/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!(head->next))
        {
            return head;
        }
        
        ListNode * p = head->next;
        ListNode * ret = reverseList(head->next);
        p->next = head;
        
       head->next = NULL;
        return ret;
        
    }
};