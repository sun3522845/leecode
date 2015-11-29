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
    ListNode* insertionSortList(ListNode* head) {
       if(!head)
			return head;
       
		ListNode * nhead = new ListNode(0);
		nhead->next = head;
		ListNode * p = head->next;
		head->next=NULL;
		while(p)
		{
			ListNode *tmp = nhead->next;
			ListNode *q = nhead;
			while(tmp&&tmp->val<p->val)
			{
				tmp = tmp->next;
				q=q->next;
			}
			q->next=p;
			q=p->next;
			p->next=tmp;
			p=q;
		
		}

		head = nhead->next;
		delete nhead;
		return head;
    }
};