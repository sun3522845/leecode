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
	int LengthOfList(ListNode* head)
	{
		int length=0;
		while(head)
		{
			length++;
			head=head->next;
		}
		return length;
	}
    ListNode* rotateRight(ListNode* head, int k) {
         int length =  LengthOfList(head);
		if(length<=1)
			return head;
		int dk = k%length;
        if(dk==0)
            return head;
		ListNode * p ,*q;
		p=q=head;
		for(int i=0;i<(length-dk-1);i++)
		{
			p=p->next;
		}
		q=p->next;
		p->next=NULL;
		p=q;
	
		while(p->next)
		{
			p=p->next;
		}
		p->next=head;
		return q;
    }
};