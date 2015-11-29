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
    ListNode* swapPairs(ListNode* head) {
        if(!head)
			return head;
        ListNode * p = new ListNode(0);
		p->next = head;
		ListNode * q =head->next;;
		head = p;
		while(q)
		{
			
			ListNode *tmp=p->next;
			p->next = q;
			p = q->next;
			q->next = tmp;
			q=p;
			p=tmp;
			tmp->next = q;
			if(q)
			{
				q=q->next;
			}
			else
			{
				break;
			}
		}

		p = head->next;
		delete head;
		return p;
    }
};