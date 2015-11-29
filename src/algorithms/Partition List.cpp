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
    ListNode* partition(ListNode* head, int x) {
       	ListNode * p = head;
		ListNode * lb = new ListNode(0);
		ListNode * le = lb;
		ListNode * gb= new ListNode(0);
		ListNode * ge = gb;
		while(p)
		{
		    ListNode * tmp = p->next;
			if(p->val<x)
			{
				le->next = p;
				le=le->next;
				le->next=NULL;
			}
			else
			{
				ge->next=p;
				ge=ge->next;
				ge->next=NULL;
			}
			p = tmp;
		}
	
		le->next=gb->next;
		delete gb;
		le = lb->next;
		delete lb;
		return le;
    }
};