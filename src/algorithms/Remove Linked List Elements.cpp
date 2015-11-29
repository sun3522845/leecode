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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * p =head;
		ListNode * q = new ListNode(0);
		q->next = p;
		head = q;
		while(p)
		{
			if(p->val == val)
			{
				q->next=p->next;
				delete p;
				p=q->next;
			}
			else
			{
				q=p;
				p=p->next;
			}
		
		}

		p = head->next;
		delete head;
		return p;
    }
};