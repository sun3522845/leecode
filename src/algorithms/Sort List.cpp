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
    ListNode * MergeList(ListNode * left,ListNode * right)
	{
		ListNode * head=new ListNode(0);
		ListNode *p=head;
		while(left&&right)
		{
			if(left->val<right->val)
			{
				p->next=left;
				left=left->next;
			}
			else
			{
				p->next=right;
				right=right->next;
			}
			p=p->next;
			p->next=NULL;

		}
		if(left)
		{
			p->next=left;
		}
		else
		{
			p->next=right;
		}
		p=head->next;
		delete head;
		return p;
	}

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
	ListNode* sortList(ListNode* head) {
		
		int length = LengthOfList(head);
		if (length<=1)
		{
			return head;
		}
		
		ListNode * right=head;
		for(int i=0;i<length/2-1;i++)
		{
			right = right->next;
			
		}

		ListNode *tmp = right->next;
		right->next=NULL;	
		ListNode * left = sortList(head);
		ListNode * rght = sortList(tmp);
		return MergeList(left,rght);


    }
};