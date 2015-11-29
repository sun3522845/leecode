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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        	ListNode * nhead=new ListNode(0);
		ListNode * p=nhead;
		int up=0;
		while(l1&&l2)
		{
			int val = l1->val+l2->val+up;
			if (val>=10)
			{
				val = val-10;
				up=1;
			}
			else
			{
				up=0;
			}
			nhead->next=new ListNode(val);
			nhead=nhead->next;
			l1=l1->next;
			l2=l2->next;
		}
		ListNode *q=NULL;
		if(l1)
		{
			q=l1;
		}
		else if(l2)
		{
			q=l2;
		}
		while(q)
		{
			int val =q->val+up;
			if (val>=10)
			{
				val = val-10;
				up=1;
			}
			else
			{
				up=0;
			}
			nhead->next=new ListNode(val);
			nhead=nhead->next;
			q=q->next;
		}
		if(up==1)
		{
			nhead->next=new ListNode(1);
			
		}
		nhead= p->next;
		delete p;
		return nhead;
    }
};