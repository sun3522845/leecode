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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
         ListNode * head=new ListNode(0);
		ListNode * node=head;;
		

		while(l1&&l2)
		{
			
			if(l1->val<l2->val)
			{
				node->next=l1;
				node=node->next;
				l1=l1->next;
			}
			else
			{
				node->next=l2;
				node=node->next;
				l2=l2->next;
			}
		}
		if(l1)
			node->next=l1;
		else if(l2)
			node->next=l2;

		node=head;
		head=head->next;
		delete node;
		return head;
    }
};